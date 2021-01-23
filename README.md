# Base Mbed OS driver for SSD1306 based OLED display

This library provides simple Mbed OS 6 driver for SSD1306 based OLED displays.

![128x32 display](docs/ssd1306_128x64_i2c.png)
![128x32 display](docs/ssd1306_128x32_i2c.png)

The driver only provides API to flush data from a buffer to a specified display region.

The interface should be drawn with some external libraries like [LVGL](https://lvgl.io/) and others.

Display usage examples can be found in the `examples` folder.

### Mbed OS version support

| Mbed OS | status |
|---|---|
| 6.2 | Compiles and runs ok |
