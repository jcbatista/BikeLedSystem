#include "LedController.h"

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;

void LedController::initialize()
{
  Serial.println("Entering LedController::initialize()");
  
  FastLED.addLeds<LED_TYPE, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(_leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
  
  _currentPalette = RainbowColors_p;
  //_currentBlending = BLEND;
  _startIndex = 0;
  
  Serial.println("Exiting LedController::initialize()");
}

void LedController::displayPattern(uint8_t frequency)
{
  FastLED.show();
  FastLED.delay(1000 / frequency);
}

// There are several different palettes of colors demonstrated here.
//
// FastLED provides several 'preset' palettes: RainbowColors_p, RainbowStripeColors_p,
// OceanColors_p, CloudColors_p, LavaColors_p, ForestColors_p, and PartyColors_p.
//
// Additionally, you can manually define your own color palettes, or you can write
// code that creates color palettes on the fly.  All are shown here.

void LedController::changePalettePeriodically()
{
  /*
  uint8_t secondHand = (millis() / 1000) % 60;
  static uint8_t lastSecond = 99;
  
  if( lastSecond != secondHand) {
    lastSecond = secondHand;
    if( secondHand ==  0)  { _currentPalette = RainbowColors_p;         _currentBlending = BLEND; }
    if( secondHand == 10)  { _currentPalette = RainbowStripeColors_p;   _currentBlending = NOBLEND; }
    if( secondHand == 15)  { _currentPalette = RainbowStripeColors_p;   _currentBlending = BLEND; }
    if( secondHand == 20)  { SetupPurpleAndGreenPalette();              _currentBlending = BLEND; }
    if( secondHand == 25)  { SetupTotallyRandomPalette();               _currentBlending = BLEND; }
    if( secondHand == 30)  { SetupBlackAndWhiteStripedPalette();        _currentBlending = NOBLEND; }
    if( secondHand == 35)  { SetupBlackAndWhiteStripedPalette();        _currentBlending = BLEND; }
    if( secondHand == 40)  { _currentPalette = CloudColors_p;           _currentBlending = BLEND; }
    if( secondHand == 45)  { _currentPalette = PartyColors_p;           _currentBlending = BLEND; }
    if( secondHand == 50)  { _currentPalette = myRedWhiteBluePalette_p; _currentBlending = NOBLEND; }
    if( secondHand == 55)  { _currentPalette = myRedWhiteBluePalette_p; _currentBlending = BLEND; }
  }
  */
  _currentPalette = CloudColors_p;
  //_currentBlending = BLEND;
}

// This function fills the palette with totally random colors.
void LedController::setupTotallyRandomPalette()
{
  for( int i = 0; i < 16; i++) {
    _currentPalette[i] = CHSV( random8(), 255, random8());
  }
}

// This function sets up a palette of black and white stripes,
// using code.  Since the palette is effectively an array of
// sixteen CRGB colors, the various fill_* functions can be used
// to set them up.
void LedController::setupBlackAndWhiteStripedPalette()
{
  // 'black out' all 16 palette entries...
  fill_solid( _currentPalette, 16, CRGB::Black);
  // and set every fourth one to white.
  _currentPalette[0] = CRGB::White;
  _currentPalette[4] = CRGB::White;
  _currentPalette[8] = CRGB::White;
  _currentPalette[12] = CRGB::White;
}

// This function sets up a palette of purple and green stripes.
void LedController::setupPurpleAndGreenPalette()
{
  CRGB purple = CHSV( HUE_PURPLE, 255, 255);
  CRGB green  = CHSV( HUE_GREEN, 255, 255);
  CRGB black  = CRGB::Black;
  
  _currentPalette = CRGBPalette16( 
    green,  green,  black,  black,
    purple, purple, black,  black,
    green,  green,  black,  black,
    purple, purple, black,  black );
}

void LedController::fillLEDsFromPaletteColors(CRGBPalette16 palette, TBlendType blendType, uint8_t brightness)
{
  uint8_t colorIndex = _startIndex;
  for( int i = 0; i < NUM_LEDS; i++) {
    //_leds[i] = ColorFromPalette(palette, colorIndex, brightness, blendType);
    _leds[i] = ColorFromPalette(palette, colorIndex, brightness);
    colorIndex += 3;
  }
  _startIndex++;
}

/*
void LedController::fillLEDsFromPaletteColors( uint8_t colorIndex)
{
  uint8_t brightness = 255;
  
  for( int i = 0; i < NUM_LEDS; i++) {
    _leds[i] = ColorFromPalette( _currentPalette, colorIndex, brightness, _currentBlending);
    colorIndex += 3;
  }
}
 */

// This example shows how to set up a static color palette
// which is stored in PROGMEM (flash), which is almost always more 
// plentiful than RAM.  A static PROGMEM palette like this
// takes up 64 bytes of flash.
/*
const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM =
{
  CRGB::Red,
  CRGB::Gray, // 'white' is too bright compared to red and blue
  CRGB::Blue,
  CRGB::Black,

  CRGB::Red,
  CRGB::Gray,
  CRGB::Blue,
  CRGB::Black,

  CRGB::Red,
  CRGB::Red,
  CRGB::Gray,
  CRGB::Gray,
  CRGB::Blue,
  CRGB::Blue,
  CRGB::Black,
  CRGB::Black
};
*/

// Additionl notes on FastLED compact palettes:
//
// Normally, in computer graphics, the palette (or "color lookup table")
// has 256 entries, each containing a specific 24-bit RGB color.  You can then
// index into the color palette using a simple 8-bit (one byte) value.
// A 256-entry color palette takes up 768 bytes of RAM, which on Arduino
// is quite possibly "too many" bytes. 
//
// FastLED does offer traditional 256-element palettes, for setups that
// can afford the 768-byte cost in RAM.
//
// However, FastLED also offers a compact alternative.  FastLED offers
// palettes that store 16 distinct entries, but can be accessed AS IF
// they actually have 256 entries; this is accomplished by interpolating
// between the 16 explicit entries to create fifteen intermediate palette 
// entries between each pair.
//
// So for example, if you set the first two explicit entries of a compact 
// palette to Green (0,255,0) and Blue (0,0,255), and then retrieved 
// the first sixteen entries from the virtual palette (of 256), you'd get
// Green, followed by a smooth gradient from green-to-blue, and then Blue.

