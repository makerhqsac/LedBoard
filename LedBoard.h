#ifndef LedBoard_h
#define LedBoard_h

#include <inttypes.h>
#include <Adafruit_NeoPixel.h>

#define LEDBOARD_DEFAULT_PIN            7
#define LEDBOARD_DEFAULT_HEIGHT         20
#define LEDBOARD_DEFAULT_WIDTH          10
#define LEDBOARD_DEFAULT_DIGIT_COUNT    6


class LedBoard {
public:
    // ctors
    LedBoard();
    LedBoard(uint8_t pin);
    LedBoard(uint8_t pin, uint16_t height, uint16_t width);
    LedBoard(uint8_t pin, uint16_t height, uint16_t width, uint16_t);

    void begin();
    void show();

    void setColor(uint16_t x, uint16_t y, uint8_t r, uint8_t g, uint8_t b);
    uint32_t getColor(uint16_t x, uint16_t y);

    void setDigit(uint8_t pos, byte digit, uint8_t r, uint8_t g, uint8_t b);


    // passthrough functions
    uint16_t numPixels(void);
    void setBrightness(uint8_t b);
    uint8_t getBrightness(void);
    void clear();
    void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b);
    void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b, uint8_t w);
    void setPixelColor(uint16_t n, uint32_t c);
    uint32_t getPixelColor(uint16_t n);

private:
    uint16_t xyToPixel(uint16_t x, uint16_t y);

    uint16_t
            board_height,   // board height
            board_width,    // board width
            digit_offset;   // pixel offset of where 7segment digits start

    Adafruit_NeoPixel
            led_strip;      // reference to neopixel object

};

#endif
