/**
 * Example of I2C 128x32 OLED display usage.
 *
 * It shows 2 tapes that are updated periodically.
 */
#include "mbed.h"
#include "ssd1306_driver.h"

using namespace ssd1306driver;

// pin configuration
#define DISPLAY_I2C_SDA_PIN PB_7
#define DISPLAY_I2C_SCL_PIN PB_6
// display parameters
#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 32
#define DISPLAY_COMPIN_LAYOUT SSD1306DisplayDriver::COMPINLAYOUT_SN

static DigitalOut user_led(LED1, 1);

static SSD1306DisplayInterfaceI2C display_interface(DISPLAY_I2C_SDA_PIN, DISPLAY_I2C_SCL_PIN);
static SSD1306DisplayDriver display_driver(&display_interface, DISPLAY_WIDTH, DISPLAY_HEIGHT, SSD1306DisplayDriver::VCC_INTERNAL, DISPLAY_COMPIN_LAYOUT);

int main()
{
    int err;

    err = display_driver.init();
    if (err) {
        MBED_ERROR(MBED_MAKE_ERROR(MBED_MODULE_APPLICATION, MBED_ERROR_CODE_INITIALIZATION_FAILED), "Fail to initialize display");
    }

    const int tick_width = 2;
    const int tick_height = 2;
    const int tick_fill_num = 3;
    const uint8_t tick_fill_bufs[tick_fill_num][tick_width * tick_height] = {
        { 0xFF, 0xFF, 0xFF, 0xFF },
        { 0x5A, 0xA5, 0x5A, 0xA5 },
        { 0x00, 0x00, 0x00, 0x00 }
    };

    const int tick_x_num = display_driver.get_width() / tick_width;
    const int tick_y_num = display_driver.get_height() / 8 / tick_height;

    printf("-- start --\n");
    while (true) {
        for (int tick_fill_i = 0; tick_fill_i < tick_fill_num; tick_fill_i++) {
            for (int tick_y = 0; tick_y < tick_y_num; tick_y++) {
                for (int tick_x = 0; tick_x < tick_x_num; tick_x++) {
                    display_driver.draw_bitmap(tick_x * tick_width, (tick_x + 1) * tick_width - 1, tick_y * tick_height, (tick_y + 1) * tick_height - 1, tick_fill_bufs[tick_fill_i]);
                    ThisThread::sleep_for(20ms);
                }
            }
            user_led = !user_led;
        }
    }

    return 0;
}
