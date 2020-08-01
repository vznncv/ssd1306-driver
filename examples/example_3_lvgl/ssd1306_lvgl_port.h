#include "lvgl.h"
#include "mbed.h"

#include "ssd1306_driver.h"

/**
 * Common littlevgl initialization function.
 *
 * @return 0 on success, otherwise non-zero value
 */
int app_littlevlg_init();

/**
 * Littlevgl task/ui handler.
 *
 * This function should be called periodically in the same thread that modifies UI.
 *
 * @return 0 on success, otherwise non-zero value
 */
int app_littlevgl_process_ui();

/**
 * Helper LittlevGL bindings for SSD1306DisplayDriver driver class.
 */
class SSD1306LVGLDisplay : NonCopyable<SSD1306LVGLDisplay> {
private:
    ssd1306driver::SSD1306DisplayDriver *const _display_driver = nullptr;
    uint8_t *_buf = nullptr;

    lv_disp_buf_t _lv_buf;
    lv_disp_drv_t _lv_drv;
    lv_disp_t *_lv_disp = nullptr;

public:
    /**
     * Constructor.
     *
     * @param display_driver SSD1306DisplayDriver driver pointer
     */
    SSD1306LVGLDisplay(ssd1306driver::SSD1306DisplayDriver *display_driver);

    ~SSD1306LVGLDisplay();

    /**
     * Initialize display driver.
     *
     * @return 0 on success, otherwise non-zero value
     */
    int init();

    /**
     * Get initialized LittlevGL display structure.
     *
     * @return display structure or @c nullptr if display isn't initialized
     */
    lv_disp_t *get_display();

    /**
     * Get screen object of the LittlevGL display.
     *
     * @return screen structure or @c nullptr if display isn't initialized
     */
    lv_obj_t *get_screen();

    /**
     * Get display width.
     */
    inline int get_width() const
    {
        return _display_driver->get_width();
    }

    /**
     * Get display height.
     */
    inline int get_height() const
    {
        return _display_driver->get_heigth();
    }
};
