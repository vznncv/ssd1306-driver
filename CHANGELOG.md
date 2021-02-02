# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [0.2.0] - 2021-02-02

### Changed

- Rename ``SSD1306DisplayDriver::get_heigth`` to ``SSD1306DisplayDriver::get_height`` to fix typo.
- Update LVGL example to Kernel::Clock to get current time.
- Fix library name in the "mbed_lib.json".

### Fixed

- Fix compilation warnings.

## [0.1.0] - 2020-08-01

### Added

- Add base SSD1306 driver
- Add I2C wrapper for SSD1306 driver
- Add SPI wrapper for SSD1306 driver
