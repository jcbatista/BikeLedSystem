#ifndef LedController_h
#define LedController_h

#include <FastLED.h>

#define DATA_PIN    3
#define CLOCK_PIN   2
#define NUM_LEDS    24
#define BRIGHTNESS  64
#define LED_TYPE    LPD8806
#define COLOR_ORDER GRB
#define UPDATES_PER_SECOND 100

// This example shows several ways to set up and use 'palettes' of colors
// with FastLED.
//
// These compact palettes provide an easy way to re-colorize your 
// animation on the fly, quickly, easily, and with low overhead.
//
// USING palettes is MUCH simpler in practice than in theory, so first just
// run this sketch, and watch the pretty lights as you then read through 
// the code.  Although this sketch has eight (or more) different color schemes,
// the entire sketch compiles down to about 6.5K on AVR.
//
// FastLED provides a few pre-configured color palettes, and makes it
// extremely easy to make up your own color schemes with palettes.
//
// Some notes on the more abstract 'theory and practice' of 
// FastLED compact palettes are at the bottom of this file.

class LedController
{
  private:
    CRGB _leds[NUM_LEDS];
    CRGBPalette16 _currentPalette;
    TBlendType    _currentBlending;
  
  public:
    void initialize();
    void displayPattern();
    void setupTotallyRandomPalette();
    void setupBlackAndWhiteStripedPalette();
    void setupPurpleAndGreenPalette();
    void changePalettePeriodically();
    void fillLEDsFromPaletteColors( uint8_t colorIndex);  
};

#endif // LedController_h
