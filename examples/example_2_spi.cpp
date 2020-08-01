/**
 * Example of SPI 128x64 OLED display usage.
 *
 * It shows 4 tapes that are updated periodically.
 */
#include "mbed.h"
#include "ssd1306_driver.h"

using namespace ssd1306driver;

// pin configuration
#define DISPLAY_SPI_MOSI_PIN PA_7
#define DISPLAY_SPI_SCLK_PIN PA_5
#define DISPLAY_SPI_SSEL_PIN PA_4
#define DISPLAY_DC_PIN PB_0
#define DISPLAY_DC_RESET PB_1
// display parameters
#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 64
#define DISPLAY_COMPIN_LAYOUT SSD1306DisplayDriver::COMPINLAYOUT_AN

static DigitalOut user_led(LED1, 1);

static SSD1306DisplayInterfaceSPI display_interafce(DISPLAY_SPI_MOSI_PIN, DISPLAY_SPI_SCLK_PIN, DISPLAY_SPI_SSEL_PIN, DISPLAY_DC_PIN, DISPLAY_DC_RESET);
static SSD1306DisplayDriver display_dirver(&display_interafce, DISPLAY_WIDTH, DISPLAY_HEIGHT, SSD1306DisplayDriver::VCC_INTERNAL, DISPLAY_COMPIN_LAYOUT);

int main()
{
    int err;

    err = display_dirver.init();
    if (err) {
        MBED_ERROR(MBED_MAKE_ERROR(MBED_MODULE_APPLICATION, MBED_ERROR_CODE_INITIALIZATION_FAILED), "Fail to initialize display");
    }

    const int tick_width = 2;
    const int tick_heght = 2;
    const int tick_fill_num = 3;
    const uint8_t tick_fill_bufs[tick_fill_num][tick_width * tick_heght] = {
        { 0xFF, 0xFF, 0xFF, 0xFF },
        { 0x5A, 0xA5, 0x5A, 0xA5 },
        { 0x00, 0x00, 0x00, 0x00 }
    };

    const int tick_x_num = display_dirver.get_width() / tick_width;
    const int tick_y_num = display_dirver.get_heigth() / 8 / tick_heght;

    printf("-- start --\n");
    while (true) {
        for (int tick_fill_i = 0; tick_fill_i < tick_fill_num; tick_fill_i++) {
            for (int tick_y = 0; tick_y < tick_y_num; tick_y++) {
                for (int tick_x = 0; tick_x < tick_x_num; tick_x++) {
                    display_dirver.draw_bitmap(tick_x * tick_width, (tick_x + 1) * tick_width - 1, tick_y * tick_heght, (tick_y + 1) * tick_heght - 1, tick_fill_bufs[tick_fill_i]);
                    ThisThread::sleep_for(20ms);
                }
            }
            user_led = !user_led;
        }
    }
}
