#include "lvgl.h"
#include "mbed.h"

#include "ssd1306_driver.h"

/**
 * Common LVGL initialization function.
 *
 * @return 0 on success, otherwise non-zero value
 */
int app_lvgl_init();

/**
 * LVGL task/ui handler.
 *
 * This function should be called periodically in the same thread that modifies UI.
 *
 * @return the time after which it must be called again, or negative value in case of error
 */
int app_lvgl_process_ui();

/**
 * Force display update with next app_lvgl_process_ui invocation.
 *
 * This function is useful if you need to show some information and don't invoke app_lvgl_process_ui during some time.
 *
 * @param disp display object
 * @return 0 on success, otherwise non-zero value
 */
int app_lvgl_display_ready(lv_disp_t *disp);

/**
 * Helper LVGL bindings for SSD1306DisplayDriver driver class.
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
     * Get initialized LVGL display structure.
     *
     * @return display structure or @c nullptr if display isn't initialized
     */
    lv_disp_t *get_display();

    /**
     * Get screen object of the LVGL display.
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
        return _display_driver->get_height();
    }
};
