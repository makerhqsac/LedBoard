#include "LedBoard.h"

#include <inttypes.h>
#include <avr/pgmspace.h>

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


LedBoard::LedBoard() {
    LedBoard::LedBoard(LEDBOARD_DEFAULT_PIN);
}

LedBoard::LedBoard(uint8_t pin) {
    LedBoard::LedBoard(pin, LEDBOARD_DEFAULT_HEIGHT, LEDBOARD_DEFAULT_WIDTH);
}

LedBoard::LedBoard(uint8_t pin, uint16_t height, uint16_t width) {
    LedBoard::LedBoard(pin, height, width, LEDBOARD_DEFAULT_DIGIT_COUNT);
}

LedBoard::LedBoard(uint8_t pin, uint16_t height, uint16_t width, uint8_t digit_count) {
    led_strip = Adafruit_NeoPixel(width * height + (7 * digitCount), pin, NEO_GRB + NEO_KHZ800);
}

void LedBoard::begin() {
    digitOffset = xyToPixel(x, y) + 1;

    led_strip.begin();
    show();
}

void LedBoard::show() {
    led_strip.show();
}

void LedBoard::setColor(uint16_t x, uint16_t y, uint8_t r, uint8_t g, uint8_t b) {
    led_strip.setPixelColor(xyToPixel(x, y), r, g, b);
}

uint32_t LedBoard::getColor(uint16_t x, uint16_t y) {
    return led_strip.getPixelColor(xyToPixel(x, y));
}

uint16_t LedBoard::xyToPixel(uint16_t x, uint16_t y) {

    uint8_t rows_per_group = 8;

    uint16_t group = floor(y/rows_per_group);

#ifdef LEDBOARD_CONFIG_ZERO_TOP
    return x * y;
#else
    uint8_t row = y % rows_per_group;
    switch (row) {
        case 0:
            return (y * board_width) + x;
        case 1:
            return (y * board_width) + x;
    }

#endif
}

void LedBoard::setDigit(uint8_t pos, byte digit, uint8_t r, uint8_t g, uint8_t b) {

    uint16_t offset = digit_offset + (pos * 7);

    for (int i = 0; i < 7; i++) {
        strip.setPixelColor(offset + i, 0,0,0);
    }
    switch (digit) {
        case 0:
            led_strip.setPixelColor(offset + 0, r, g, b);
            led_strip.setPixelColor(offset + 1, r, g, b);
            led_strip.setPixelColor(offset + 2, r, g, b);
            led_strip.setPixelColor(offset + 4, r, g, b);
            led_strip.setPixelColor(offset + 5, r, g, b);
            led_strip.setPixelColor(offset + 6, r, g, b);
            break;
        case 1:
            led_strip.setPixelColor(offset + 0, r, g, b);
            led_strip.setPixelColor(offset + 4, r, g, b);
            break;
        case 2:
            led_strip.setPixelColor(offset + 1, r, g, b);
            led_strip.setPixelColor(offset + 2, r, g, b);
            led_strip.setPixelColor(offset + 3, r, g, b);
            led_strip.setPixelColor(offset + 4, r, g, b);
            led_strip.setPixelColor(offset + 5, r, g, b);
            break;
        case 3:
            led_strip.setPixelColor(offset + 0, r, g, b);
            led_strip.setPixelColor(offset + 1, r, g, b);
            led_strip.setPixelColor(offset + 3, r, g, b);
            led_strip.setPixelColor(offset + 4, r, g, b);
            led_strip.setPixelColor(offset + 5, r, g, b);
            break;
        case 4:
            led_strip.setPixelColor(offset + 0, r, g, b);
            led_strip.setPixelColor(offset + 3, r, g, b);
            led_strip.setPixelColor(offset + 4, r, g, b);
            led_strip.setPixelColor(offset + 6, r, g, b);
            break;
        case 5:
            led_strip.setPixelColor(offset + 0, r, g, b);
            led_strip.setPixelColor(offset + 1, r, g, b);
            led_strip.setPixelColor(offset + 3, r, g, b);
            led_strip.setPixelColor(offset + 5, r, g, b);
            led_strip.setPixelColor(offset + 6, r, g, b);
            break;
        case 6:
            led_strip.setPixelColor(offset + 0, r, g, b);
            led_strip.setPixelColor(offset + 1, r, g, b);
            led_strip.setPixelColor(offset + 2, r, g, b);
            led_strip.setPixelColor(offset + 3, r, g, b);
            led_strip.setPixelColor(offset + 5, r, g, b);
            led_strip.setPixelColor(offset + 6, r, g, b);
            break;
        case 7:
            led_strip.setPixelColor(offset + 0, r, g, b);
            led_strip.setPixelColor(offset + 4, r, g, b);
            led_strip.setPixelColor(offset + 5, r, g, b);
            break;
        case 8:
            led_strip.setPixelColor(offset + 0, r, g, b);
            led_strip.setPixelColor(offset + 1, r, g, b);
            led_strip.setPixelColor(offset + 2, r, g, b);
            led_strip.setPixelColor(offset + 3, r, g, b);
            led_strip.setPixelColor(offset + 4, r, g, b);
            led_strip.setPixelColor(offset + 5, r, g, b);
            led_strip.setPixelColor(offset + 6, r, g, b);
            break;
        case 9:
            led_strip.setPixelColor(offset + 0, r, g, b);
            led_strip.setPixelColor(offset + 1, r, g, b);
            led_strip.setPixelColor(offset + 3, r, g, b);
            led_strip.setPixelColor(offset + 4, r, g, b);
            led_strip.setPixelColor(offset + 5, r, g, b);
            led_strip.setPixelColor(offset + 6, r, g, b);
            break;
        default: break;
    }
}


// passthrough functions


uint16_t LedBoard::numPixels(void) {
    return led_strip.numPixels();
}

void LedBoard::setBrightness(uint8_t b) {
    led_strip.setBrightness(b);
}

uint8_t LedBoard::getBrightness(void) const {
    return led_strip.getBrightness();
}

void LedBoard::clear() {
    led_strip.clear();
}

void LedBoard::setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b) {
    led_strip.setPixelColor(n, r, g, b);
}
void LedBoard::setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b, uint8_t w) {
    led_strip.setPixelColor(n, r, g, b, w);
}
void LedBoard::setPixelColor(uint16_t n, uint32_t c) {
    led_strip.setPixelColor(n, c);
}

uint32_t LedBoard::getPixelColor(uint16_t n) {
    return led_strip.getPixelColor(n);
}
