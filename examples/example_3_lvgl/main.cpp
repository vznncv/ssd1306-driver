/**
 * Example of I2C 128x32 OLED display usage with LVGL.
 */
#include "mbed.h"
#include "ssd1306_driver.h"
#include "ssd1306_lvgl_port.h"

using namespace ssd1306driver;

// pin configuration
#define DISPLAY_I2C_SDA_PIN PB_7
#define DISPLAY_I2C_SCL_PIN PB_6
// display parameters
#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 32
#define DISPLAY_COMPIN_LAYOUT SSD1306DisplayDriver::COMPINLAYOUT_SN

static DigitalOut user_led(LED1);

static SSD1306DisplayInterfaceI2C display_interface(DISPLAY_I2C_SDA_PIN, DISPLAY_I2C_SCL_PIN);
static SSD1306DisplayDriver display_driver(&display_interface, DISPLAY_WIDTH, DISPLAY_HEIGHT, SSD1306DisplayDriver::VCC_INTERNAL, DISPLAY_COMPIN_LAYOUT);
static SSD1306LVGLDisplay lvgl_display(&display_driver);

static lv_obj_t *init_display()
{
    int err;
    lv_obj_t *screen;

    // initialize display
    err = display_driver.init();
    if (err) {
        MBED_ERROR(MBED_MAKE_ERROR(MBED_MODULE_APPLICATION, MBED_ERROR_CODE_INITIALIZATION_FAILED), "Fail to initialize display");
    }

    // initialize LVGL
    err = app_lvgl_init();
    if (err) {
        MBED_ERROR(MBED_MAKE_ERROR(MBED_MODULE_APPLICATION, MBED_ERROR_CODE_INITIALIZATION_FAILED), "Fail to initialize LVGL");
    }

    // initialize display driver
    err = lvgl_display.init();
    if (err) {
        MBED_ERROR(MBED_MAKE_ERROR(MBED_MODULE_APPLICATION, MBED_ERROR_CODE_INITIALIZATION_FAILED), "Fail to initialize LVGL display driver");
    }

    screen = lvgl_display.get_screen();
    MBED_ASSERT(screen != nullptr);

    return screen;
}

/**
 * Helper class that encapsulates LVGL UI.
 */
class AppScene {
private:
    bool _init_flag = false;

    lv_obj_t *_screen = nullptr;
    lv_obj_t *_progress_bar = nullptr;
    lv_obj_t *_first_value_label = nullptr;
    char _first_value_text[16];
    char _second_value_text[16];
    lv_obj_t *_second_value_label = nullptr;

public:
    AppScene(lv_obj_t *screen)
        : _screen(screen)
    {
    }
    ~AppScene() = default;

    /**
     * Initialize user interface.
     */
    int init()
    {
        if (_init_flag) {
            return 0;
        }

        // create progress bar
        _progress_bar = lv_bar_create(_screen, NULL);
        lv_bar_set_range(_progress_bar, 0, 1024);
        set_progress(0);
        lv_obj_set_width_margin(_progress_bar, lv_obj_get_width_fit(_screen));
        lv_obj_align(_progress_bar, NULL, LV_ALIGN_IN_TOP_MID, 0, 0);

        lv_obj_t *name_label;
        // create first label
        name_label = lv_label_create(_screen, NULL);
        lv_label_set_text(name_label, "A1:");
        _first_value_label = lv_label_create(_screen, NULL);
        set_first_value(0.0);
        lv_obj_align(name_label, NULL, LV_ALIGN_IN_BOTTOM_LEFT, 0, 0);
        lv_obj_align(_first_value_label, name_label, LV_ALIGN_OUT_RIGHT_MID, 0, 0);

        // create second label
        name_label = lv_label_create(_screen, NULL);
        lv_label_set_text(name_label, "A2:");
        _second_value_label = lv_label_create(_screen, NULL);
        set_second_value(1.0);
        lv_obj_align(name_label, NULL, LV_ALIGN_IN_BOTTOM_RIGHT, -lv_obj_get_width_margin(_second_value_label), 0);
        lv_obj_align(_second_value_label, name_label, LV_ALIGN_OUT_RIGHT_MID, 0, 0);
        return 0;
    }

    int set_progress(float value)
    {
        lv_bar_set_value(_progress_bar, lv_bar_get_max_value(_progress_bar) * value, LV_ANIM_OFF);
        return 0;
    }

    /**
     * Helper function to format float value.
     */
    int _format_fix_float(char *buf, float value, int size, int precision, bool show_sign = false)
    {
        MBED_ASSERT(size >= precision + 2);
        // convert float value to integer to simplify digit extraction
        int pr_mod = 1;
        for (int i = 0; i < precision; i++) {
            pr_mod *= 10;
        }
        int value_int = value * pr_mod;
        if (value - value_int >= 0.5f) {
            value_int++;
        }
        bool minus_sign = false;
        if (value_int < 0) {
            minus_sign = true;
            show_sign = true;
            value_int = -value_int;
        }
        // print digits
        int pos = size - 1;
        buf[size--] = '\0';
        for (int i = 0; i < precision; i++) {
            buf[pos--] = value_int % 10 + '0';
            value_int /= 10;
        }
        buf[pos--] = '.';
        do {
            buf[pos--] = value_int % 10 + '0';
            value_int /= 10;
        } while (value_int);
        while (pos >= 0) {
            if (show_sign) {
                buf[pos--] = minus_sign ? '-' : '+';
                show_sign = false;
            } else {
                buf[pos--] = ' ';
            }
        }

        return 0;
    }

    int set_first_value(float value)
    {
        _format_fix_float(_first_value_text, value, 4, 2);
        lv_label_set_text_static(_first_value_label, _first_value_text);
        return 0;
    }
    int set_second_value(float value)
    {
        _format_fix_float(_second_value_text, value, 5, 2, true);
        lv_label_set_text_static(_second_value_label, _second_value_text);
        return 0;
    }
};

int main()
{
    // initialize display
    lv_obj_t *screen = init_display();

    // build graphic interface
    AppScene app_scene(screen);
    int err = app_scene.init();
    if (err) {
        MBED_ERROR(MBED_MAKE_ERROR(MBED_MODULE_APPLICATION, MBED_ERROR_CODE_INITIALIZATION_FAILED), "Fail to initialize UI interface");
    }

    // simple demo
    printf("-- start --\n");
    float value = 0.0f;
    float d_value = 0.01f;
    while (true) {
        app_scene.set_progress(value);
        app_scene.set_first_value(value);
        app_scene.set_second_value(value * 2 - 1.0f);

        app_lvgl_process_ui();
        ThisThread::sleep_for(20ms);

        value += d_value;
        if (d_value > 0.0f && value > 1.0f) {
            d_value = -d_value;
            user_led = !user_led;
        } else if (d_value < 0.0f && value < 0.0f) {
            d_value = -d_value;
            user_led = !user_led;
        }
    }
}
