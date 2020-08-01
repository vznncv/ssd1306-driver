#ifndef SSD1306_DRIVER_H
#define SSD1306_DRIVER_H

#include "mbed.h"

namespace ssd1306driver {

/**
 * Helper class to encapsulate communication with SSD1306 dispaly.
 */
class SSD1306DisplayInterface : NonCopyable<SSD1306DisplayInterface> {

public:
    SSD1306DisplayInterface() = default;
    virtual ~SSD1306DisplayInterface() = default;

    /**
     * Write command data.
     *
     * @param buf
     * @param len
     * @return 0 on success, otherwise non-zero value
     */
    virtual int write_command_data(const uint8_t *buf, size_t len) = 0;

    /**
     * Write data to graphic memory.
     *
     * @param buf
     * @param len
     * @return 0 on success, otherwise non-zero value
     */
    virtual int write_gram_data(const uint8_t *buf, size_t len) = 0;

    /**
     * Reset dispaly
     */
    virtual int reset() = 0;
};

/**
 * I2C interface for SSD1306 display
 */
class SSD1306DisplayInterfaceI2C : public SSD1306DisplayInterface {
private:
    I2C *_i2c;
    uint8_t _addr;
    bool _cleanup_flag;
    DigitalOut _reset_pin;

    static const int _I2C_FREQ = 400'000;
    static const uint8_t _I2C_CONTROL_CMD;
    static const uint8_t _I2C_CONTROL_GRAM;

public:
    enum I2CAddress : uint8_t {
        I2CADDR_SA0LOW = 0b01111000,
        I2CADDR_SA0HIGH = 0b01111010
    };

    /**
     * Constructor.
     *
     * @param sda I2C SDA pin
     * @param scl I2C SCL pin
     * @param addr display i2c address
     * @param reset_pin reset pin (optional)
     */
    SSD1306DisplayInterfaceI2C(PinName sda, PinName scl, I2CAddress addr = I2CADDR_SA0LOW, PinName reset_pin = NC);

    /**
     * Constructor.
     *
     * @param i2c i2c interface instance
     * @param addr display i2c address
     * @param reset_pin reset pin (optional)
     */
    SSD1306DisplayInterfaceI2C(I2C *i2c, I2CAddress addr = I2CADDR_SA0LOW, PinName reset_pin = NC);

    ~SSD1306DisplayInterfaceI2C();

public:
    // SSD1306DisplayInterface interface
    int write_command_data(const uint8_t *buf, size_t len);
    int write_gram_data(const uint8_t *buf, size_t len);
    int reset();
};

/**
 * SPI 4 wire for SSD1306 display.
 */
class SSD1306DisplayInterfaceSPI : public SSD1306DisplayInterface {
private:
    SPI *_spi;
    bool _cleanup_flag;
    DigitalOut _reset_pin;
    // note: keep 1 as default dc pin value
    DigitalOut _dc_pin;

    static const int _SPI_FREQ = 8'000'000;

public:
    /**
     * Constructor.
     *
     * @param mosi MOSI SPI pin (note: MISO pin isn't used). It's connected to D1 pin of SSD1306
     * @param sclk SCLK SPI pin. It's connected to D0 pin of SSD1306
     * @param ssel SPI chip selection pin
     * @param dc_pin digital output pin that is connected to D/C# pin of SSD1306
     * @param reset_pin digital output pin that is connected to reset pin of SSD1306 (optional)
     */
    SSD1306DisplayInterfaceSPI(PinName mosi, PinName sclk, PinName ssel, PinName dc_pin, PinName reset_pin = NC);

    /**
     * Constructor.
     *
     * @param spi SPI interface
     * @param dc_pin digital output pin that is connected to D/C# pin of SSD1306
     * @param reset_pin digital output pin that is connected to reset pin of SSD1306 (optional)
     */
    SSD1306DisplayInterfaceSPI(SPI *spi, PinName dc_pin, PinName reset_pin = NC);

    ~SSD1306DisplayInterfaceSPI();

public:
    // SSD1306DisplayInterface interface
    int write_command_data(const uint8_t *buf, size_t len);
    int write_gram_data(const uint8_t *buf, size_t len);
    int reset();
};

/**
 * SSD1306 driver,
 */
class SSD1306DisplayDriver : private NonCopyable<SSD1306DisplayDriver> {
private:
    SSD1306DisplayInterface *_interface;

    // helper variable to cache last GRAM accessed region
    uint32_t _last_region = 0;

    const uint8_t _width;
    const uint8_t _height;

    static const uint8_t _DEFAULT_CONTRAST = 0x80;

public:
    /**
     * Voltage source (7.5 V) for OLED driver block.
     */
    enum VCCMode : uint8_t {
        VCC_EXTERNAL = 0x10, // use external voltage source for oled display
        VCC_INTERNAL = 0x14 // use internal voltage source for oled display (internal DC-DC convert converts 3.3 V to 7.5 V)
    };

    enum CompinLayout : uint8_t {
        COMPINLAYOUT_SN = 0x02, // sequential layout, normal left-rigth layout
        COMPINLAYOUT_SI = 0x22, // sequential layout, inversed left-rigth layout
        COMPINLAYOUT_AN = 0x12, // alternate layout, normal left-rigth layout
        COMPINLAYOUT_AI = 0x32, // alternate layout, inversed left-rigth layout
    };

private:
    VCCMode _vcc_mode;
    CompinLayout _compin_layout;

public:
    /**
     * Constructor.
     *
     * @param interface interface wrapper
     * @param width display width
     * @param height display hight. It must be in range [16, 64].
     * @param vcc_mode led panel power source. For most panels `VCC_INTERNAL` is suitable value.
     * @param compin_layout hardware compin connection type. It's should be found in the display module description or you can brut force 4 configurations.
     */
    SSD1306DisplayDriver(SSD1306DisplayInterface *interface, uint8_t width, uint8_t height, VCCMode vcc_mode = VCC_INTERNAL, CompinLayout compin_layout = COMPINLAYOUT_SN);

    ~SSD1306DisplayDriver();

    int get_width() const;
    int get_heigth() const;

    /**
     * Initialize display.
     *
     * @param start if it's true, then display will be enabled immediaty, otherwise it will be initialize and switched to sleep mode
     * @return 0 on success, otherwise non-zero value
     */
    int init(bool start = true);

    /**
     * Set display contrast.
     *
     * @param value
     * @return 0 on success, otherwise non-zero value
     */
    int set_constrast(uint8_t value);

    /**
     * Enable/disable invert mode.
     *
     * @param value
     * @return 0 on success, otherwise non-zero value
     */
    int set_invert_mode(bool value);

    /**
     * Enable/disable sleep mode.
     *
     * @param value
     * @return 0 on success, otherwise non-zero value
     */
    int set_sleep_mode(bool value);

protected:
    /**
     * Set current GRAM region.
     */
    int _set_draw_region(uint8_t start_col, uint8_t end_col, uint8_t start_page, uint8_t end_page);

public:
    /**
     * Draw pixels on a display.
     *
     * As SSD1306 is monochrome display driver, it split rows into groups that are called "pages". Each page contains 8 rows.
     * Minimal modification region is 8x1 pixels: i.e when you send a byte to GRAM, it will update 8 pixels in current page and column.
     *
     * @param start_col start column
     * @param end_col end column (including end_col)
     * @param start_page start page
     * @param end_page end page (including end_page)
     * @param data buffer with data. It's size should be \f$("end_col" - "start_col" + 1)*("end_page" - "start_page" + 1)\f$
     * @return 0 on success, otherwise non-zero value
     */
    int draw_bitmap(uint8_t start_col, uint8_t end_col, uint8_t start_page, uint8_t end_page, const uint8_t *data);

    /**
     * Clear display.
     *
     * @return 0 on success, otherwise non-zero value
     */
    int clear();

    //
    // Internal API to send display commands directly.
    // It isn't recommended to use it without necessity.
    //

    /**
     * SSD1306 commands.
     *
     * See datasheet for more details.
     */
    enum SSD1306Commands : uint8_t {
        // base commands
        CMD_SETCONTRAST = 0x81,
        CMD_DISPLAYON = 0xA4,
        CMD_DISPLAYON_WITHOUTGRAM = 0xA5,
        CMD_INVERTDISPLAY_OFF = 0xA6,
        CMD_INVERTDISPLAY_ON = 0xA7,
        CMD_DISPLAYSLEEP_ON = 0xAE,
        CMD_DISPLAYSLEEP_OFF = 0xAF,

        // TODO: add all scroll commands
        CMD_DEACTIVATE_SCROLL = 0x2E,

        // GRAM addressing commands
        CMD_ADDRESSING_SETMODE = 0x20,
        CMD_ADDRESSING_SETCOL = 0x21,
        CMD_ADDRESSING_SETPAGE = 0x22,
        CMD_ADDRESSING_PM_SETPAGE = 0xB0, // range: 0xB0 - 0xB7
        CMD_ADDRESSING_PM_SETCOLL = 0x00, // range: 0x00 - 0x0F
        CMD_ADDRESSING_PM_SETCOLH = 0x10, // range: 0x10 - 0x1F

        // hardware configuration commands
        CMD_SETSTARTLINE = 0x40, // range: 0x40 - 0x7F
        CMD_SEGREMAP = 0xA0, // range: 0xA0 - 0xA1
        CMD_SETMULTIPLEX = 0xA8,
        CMD_COMSCANINC = 0xC0,
        CMD_COMSCANDEC = 0xC8,
        CMD_SETDISPLAYOFFSET = 0xD3,
        CMD_SETCOMPINS = 0xDA,

        // Timing & Driving Scheme Setting Command Table
        CMD_SETDISPLAYCLOCKDIV = 0xD5,
        CMD_SETPRECHARGE = 0xD9,
        CMD_SETVCOMDETECT = 0xDB,

        // charge pump commands
        CMD_CHARGEPUMP = 0x8D,

        // NOP commands
        CMD_NOP = 0xE3,
    };

    /**
     * Send one or more commands to SSD1306.
     *
     * @param commands
     * @param len
     * @return 0 on success, otherwise non-zero value
     */
    int send_commands(const uint8_t *commands, size_t len);
};
}

#endif // SSD1306_DRIVER_H
