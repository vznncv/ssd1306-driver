/**
 * Base example that demonstrates SSD1306 oled display usage.
 */
#include "mbed.h"
#include "ssd1306_driver.h"

// pin configuration
#define SSD1306_SDA_PIN PB_7
#define SSD1306_SCL_PIN PB_6

static DigitalOut user_led(LED1, 1);

static ssd1306driver::SSD1306DisplayInterfaceI2C display_interafce(SSD1306_SDA_PIN, SSD1306_SCL_PIN);
static ssd1306driver::SSD1306DisplayDriver display_dirver(&display_interafce, 128, 32);

int main()
{
    int err;

    err = display_dirver.init();
    printf("Display initialization code: %i\n", err);

    const uint8_t max_col = 128;
    const uint8_t max_page = 4;
    uint8_t page = 0;
    uint8_t col = 0;
    uint8_t gram_buf[1] = { 0xFF };

    while (true) {

        for (int i = 0; i < 32; i++) {
            user_led = !user_led;
            ThisThread::sleep_for(20ms);

            display_dirver.draw_bitmap(col, col, page, page, gram_buf);
            col++;
            if (col >= max_col) {
                col = 0;
                page++;

                if (page >= max_page) {
                    page = 0;
                    gram_buf[0] = ~gram_buf[0];
                }
            }
        }

        ThisThread::sleep_for(800ms);
    }
}
