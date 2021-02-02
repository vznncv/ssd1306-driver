# [LVGL](https://github.com/lvgl/lvgl) example

This example contains a code that demonstrates LVGL 7 usage
with SSD1306 OLED 128x32 display.

## Project configuration

1. Add LVGL libraries to you project with commands:

```
mbed add https://github.com/lvgl/lvgl.git
cd lvgl
mbed update v7.2.0
```

2. Add the following lines to a `.mbedignore` project file to ignore non-source code files of LVGL:

```
# LVGL specific files
lvgl/docs
lvgl/examples
lvgl/tests
lvgl/lv_conf_template.h
```

3. Add `LV_CONF_INCLUDE_SIMPLE` macro to your `mbed_app.json` file:

```
{
    "macros": [
        "LV_CONF_INCLUDE_SIMPLE"
    ],
    "target_overrides": {
        "*": {
            "platform.stdio-baud-rate": 115200,
            "platform.minimal-printf-enable-floating-point": 1
        }
    }
}
```

4. Copy the following files to your project:

| filename | description |
|---|---|
| lv_conf.h | LVGL configuration file |
| lv_mbed_tick_port.h | LVGL ticker port for MbedOS |
| lv_mbed_tick_port.cpp | LVGL ticker port for MbedOS |
| ssd1306_lvgl_port.h | LVGL bindings for `SSD1306DisplayDriver` driver class |
| ssd1306_lvgl_port.cpp | LVGL bindings for `SSD1306DisplayDriver` driver class |
| app_lv_font_unscii_16.c | 16px height font for monochrome displays |
| main.cpp | example of the LVGL usage |

5. Adjust pin configuration in the `main.cpp`, if it's needed.

After the steps above you should be able to build and flash project.
If all are done correctly, display will show a bar and 2 labels with values,
that are being changed.
