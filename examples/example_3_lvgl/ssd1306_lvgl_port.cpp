#include <cstring>

#include "mbed.h"
#include "ssd1306_lvgl_port.h"

using ssd1306driver::SSD1306DisplayDriver;

//
// Common LittlevGL initialization functions
//

static bool lvgl_is_initialized = false;

int app_littlevlg_init()
{
    if (lvgl_is_initialized) {
        return 0;
    }
    lv_init();
    lvgl_is_initialized = true;
    return 0;
}

int app_littlevgl_process_ui()
{
    lv_task_handler();
    return 0;
}

//
// LittlevGL bindings
//

static void sdd1306_set_px_cb(lv_disp_drv_t *disp_drv, uint8_t *buf, lv_coord_t buf_w, lv_coord_t x, lv_coord_t y,
    lv_color_t color, lv_opa_t opa)
{
    int buf_index = x + (y >> 3) * buf_w;
    buf += buf_index;
    uint8_t pixel_mask = 0x01 << (y & 0x07);

    if (color.full) {
        *buf |= pixel_mask;
    } else {
        *buf &= ~pixel_mask;
    }
}

static void ssd1306_rounder_cb(lv_disp_drv_t *disp_drv, lv_area_t *area)
{
    // Update the areas as needed. Can be only larger.
    // For SSD1306 we must always have lines 8 px height.
    area->y1 = area->y1 & ~0x07;
    area->y2 = area->y2 | 0x07;
}

static void ssd1306_flush_cb(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
{
    SSD1306DisplayDriver *display_driver = (SSD1306DisplayDriver *)(disp_drv->user_data);
    uint8_t *buf = (uint8_t *)color_p;
    uint8_t start_page = (uint8_t)(area->y1 / 8);
    uint8_t end_page = (uint8_t)(area->y2 / 8);
    uint8_t start_col = area->x1;
    uint8_t end_col = area->x2;

    int err = display_driver->draw_bitmap(start_col, end_col, start_page, end_page, buf);
    MBED_ASSERT(err == 0);
    lv_disp_flush_ready(disp_drv);
}

SSD1306LVGLDisplay::SSD1306LVGLDisplay(SSD1306DisplayDriver *display_driver)
    : _display_driver(display_driver)
{
}

SSD1306LVGLDisplay::~SSD1306LVGLDisplay()
{
    if (_buf) {
        delete[] _buf;
    }
}

int SSD1306LVGLDisplay::init()
{
    if (_lv_disp) {
        return 0;
    }

    // initialize buffer
    size_t buf_size = _display_driver->get_width() * _display_driver->get_heigth();
    _buf = new uint8_t[buf_size / 8];
    memset(_buf, 0, buf_size / 8);
    lv_disp_buf_init(&_lv_buf, _buf, NULL, buf_size);

    // initialize display driver
    lv_disp_drv_init(&_lv_drv);
    _lv_drv.flush_cb = ssd1306_flush_cb;
    _lv_drv.user_data = _display_driver;
    _lv_drv.buffer = &_lv_buf;
    _lv_drv.hor_res = _display_driver->get_width();
    _lv_drv.ver_res = _display_driver->get_heigth();
    _lv_drv.set_px_cb = sdd1306_set_px_cb;
    _lv_drv.rounder_cb = ssd1306_rounder_cb;
    _lv_disp = lv_disp_drv_register(&_lv_drv);
    if (_lv_disp == nullptr) {
        return -1;
    }

    return 0;
}

lv_disp_t *SSD1306LVGLDisplay::get_display()
{
    return _lv_disp;
}

lv_obj_t *SSD1306LVGLDisplay::get_screen()
{
    if (_lv_disp == nullptr) {
        return nullptr;
    } else {
        return lv_disp_get_scr_act(_lv_disp);
    }
}
