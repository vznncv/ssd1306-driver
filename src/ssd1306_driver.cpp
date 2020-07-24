#include "ssd1306_driver.h"
using namespace ssd1306driver;

static inline int any_err(int err1, int err2)
{
    if (err1) {
        return err1;
    } else {
        return err2;
    }
}

SSD1306DisplayInterfaceI2C::SSD1306DisplayInterfaceI2C(PinName sda, PinName scl, SSD1306DisplayInterfaceI2C::I2CAddress addr, PinName reset_pin)
    : _addr(addr)
    , _cleanup_flag(true)
    , _reset_pin(NC, 1)

{
    _i2c = new I2C(sda, scl);
    _i2c->frequency(_I2C_FREQ);
}

SSD1306DisplayInterfaceI2C::SSD1306DisplayInterfaceI2C(I2C *i2c, SSD1306DisplayInterfaceI2C::I2CAddress addr, PinName reset_pin)
    : _i2c(i2c)
    , _addr(addr)
    , _cleanup_flag(false)
    , _reset_pin(NC, 1)
{
}

SSD1306DisplayInterfaceI2C::~SSD1306DisplayInterfaceI2C()
{
    if (_cleanup_flag) {
        delete _i2c;
    }
}

const uint8_t SSD1306DisplayInterfaceI2C::_I2C_CONTROL_CMD = 0x00;
const uint8_t SSD1306DisplayInterfaceI2C::_I2C_CONTROL_GRAM = 0x40;

int SSD1306DisplayInterfaceI2C::write_command_data(const uint8_t *buf, size_t len)
{
    int err_op_cmd;
    int err_op_data;

    _i2c->lock();
    err_op_cmd = _i2c->write(_addr, (const char *)&_I2C_CONTROL_CMD, 1, true);
    err_op_data = _i2c->write(_addr, (const char *)buf, len, false);
    _i2c->unlock();

    return any_err(err_op_cmd, err_op_data);
}

int SSD1306DisplayInterfaceI2C::write_gram_data(const uint8_t *buf, size_t len)
{
    int err_op_cmd;
    int err_op_data;

    _i2c->lock();
    err_op_cmd = _i2c->write(_addr, (const char *)&_I2C_CONTROL_GRAM, 1, true);
    err_op_data = _i2c->write(_addr, (const char *)buf, len, false);
    _i2c->unlock();

    return any_err(err_op_cmd, err_op_data);
}

int SSD1306DisplayInterfaceI2C::reset()
{
    if (_reset_pin.is_connected()) {
        // as this function isn't called frequently, initialize pin dynamically to save memory
        _reset_pin = 1;
        ThisThread::sleep_for(1ms);
        _reset_pin = 0;
        ThisThread::sleep_for(10ms);
        _reset_pin = 1;
    }
    return 0;
}

SSD1306DisplayDriver::SSD1306DisplayDriver(SSD1306DisplayInterface *interface, uint8_t width, uint8_t height, SSD1306DisplayDriver::VCCMode vcc_mode, SSD1306DisplayDriver::CompinLayout compin_layout)
    : _interface(interface)
    , _width(width)
    , _height(height)
    , _vcc_mode(vcc_mode)
    , _compin_layout(compin_layout)
{
}

SSD1306DisplayDriver::~SSD1306DisplayDriver()
{
}

int SSD1306DisplayDriver::init(bool start)
{
    int err;

    // send NOP operations to check if interface is valid
    const uint8_t nop_cmd[] = { CMD_NOP };
    err = _interface->write_command_data(nop_cmd, sizeof(nop_cmd));
    if (err) {
        return err;
    }

    // reset display
    err = _interface->reset();
    if (err) {
        return err;
    }

    // send command to initialize display
    const uint8_t init_cmd[] = {
        // switch off display
        CMD_DISPLAYSLEEP_ON,

        // configure frequency
        CMD_SETDISPLAYCLOCKDIV,
        0x80, // the suggested ratio 0x80 (see Adafruit_SSD1306 library)

        // configure GRAM row mapping to display row mapping
        CMD_SETMULTIPLEX, // set multiple ratio, i.e (number of actual oled rows - 1)
        (uint8_t)(_height - 1),
        CMD_SETDISPLAYOFFSET, // row offset
        0x00,
        CMD_SETSTARTLINE | 0x00, // row remapping

        // configure led driver
        CMD_CHARGEPUMP,
        _vcc_mode,

        // configure GRAM addressing mode
        CMD_ADDRESSING_SETMODE,
        0x00, // horizontal addressing mode
        // flip column order
        CMD_SEGREMAP | 0x01,
        CMD_COMSCANDEC,

        // configure COM (display rows) pin mapping
        CMD_SETCOMPINS,
        _compin_layout,

        // contrast
        CMD_SETCONTRAST,
        _DEFAULT_CONTRAST,

        // hardware configuration (see Adafruit_SSD1306 library)
        CMD_SETPRECHARGE,
        0xF1,
        CMD_SETVCOMDETECT,
        0x40,

        // reset inversion
        CMD_INVERTDISPLAY_OFF,
        // disable scroll
        CMD_DEACTIVATE_SCROLL,
        // enable display
        CMD_DISPLAYON,
    };
    err = _interface->write_command_data(init_cmd, sizeof(init_cmd));
    if (err) {
        return err;
    }

    // clear GRAM memory as it may contain "rubbish" data
    err = clear();
    if (err) {
        return err;
    }

    // run display
    if (start) {
        err = set_sleep_mode(false);
        if (err) {
            return err;
        }
    }

    return 0;
}

int SSD1306DisplayDriver::set_constrast(uint8_t value)
{
    const uint8_t cmd_buf[] = {
        CMD_SETCONTRAST,
        value
    };
    return _interface->write_command_data(cmd_buf, sizeof(cmd_buf));
}

int SSD1306DisplayDriver::set_invert_mode(bool value)
{
    const uint8_t cmd_buf[] = {
        value ? CMD_INVERTDISPLAY_ON : CMD_INVERTDISPLAY_OFF
    };
    return _interface->write_command_data(cmd_buf, sizeof(cmd_buf));
}

int SSD1306DisplayDriver::set_sleep_mode(bool value)
{
    const uint8_t cmd_buf[] = {
        value ? CMD_DISPLAYSLEEP_ON : CMD_DISPLAYSLEEP_OFF
    };
    return _interface->write_command_data(cmd_buf, sizeof(cmd_buf));
}

int SSD1306DisplayDriver::_set_draw_region(uint8_t start_col, uint8_t end_col, uint8_t start_page, uint8_t end_page)
{
    int err;
    MBED_ASSERT(start_col <= end_col);
    MBED_ASSERT(start_page <= end_page);
    MBED_ASSERT(end_col < _width);
    MBED_ASSERT(end_page < _height / 8);

    uint32_t region = (start_col << 24) | (end_col << 16) | (start_page << 8) | end_page;
    if (region != _last_region) {
        // set addressing region
        const uint8_t cmd_buf[] = {
            CMD_ADDRESSING_SETCOL,
            start_col,
            end_col,
            CMD_ADDRESSING_SETPAGE,
            start_page,
            end_page
        };
        err = _interface->write_command_data(cmd_buf, sizeof(cmd_buf));
        if (err) {
            _last_region = 0;
            return err;
        }
        _last_region = region;
    }
    return 0;
}

int SSD1306DisplayDriver::draw_bitmap(uint8_t start_col, uint8_t end_col, uint8_t start_page, uint8_t end_page, const uint8_t *data)
{
    int err;

    err = _set_draw_region(start_col, end_col, start_page, end_page);
    if (err) {
        return err;
    }

    // write graphic data
    size_t data_len = (start_col - end_col + 1) * (start_page - end_page + 1);
    err = _interface->write_gram_data(data, data_len);
    if (err) {
        _last_region = 0;
    }

    return err;
}

int SSD1306DisplayDriver::clear()
{
    int err;
    err = _set_draw_region(0, _width - 1, 0, _height / 8 - 1);
    if (err) {
        return err;
    }

    int bytes_to_send = _width * _height;
    const size_t buf_len = 32;
    const uint8_t buf[buf_len] = { 0 };
    while (bytes_to_send > 0) {
        bytes_to_send -= buf_len;
        err = _interface->write_gram_data(buf, bytes_to_send >= 0 ? buf_len : buf_len + bytes_to_send);
        if (err) {
            _last_region = 0;
            return err;
        }
    }
    return 0;
}

int SSD1306DisplayDriver::send_commands(const uint8_t *commands, size_t len)
{
    return _interface->write_command_data(commands, len);
}
