#include "LightPattern.h"

LightPattern::LightPattern(Clock* pClock, LedController* pLedController): Event(pClock)
{
  initialize(pLedController);
}

LightPattern::LightPattern(unsigned long duration, Clock* pClock, LedController* pLedController): Event(pClock, duration)
{
  initialize(pLedController);
}

LightPattern::LightPattern(LightPatternOptions lightPatternOptions, Clock* pClock, LedController* pLedController): Event(pClock, lightPatternOptions.duration)
{
  initialize(pLedController);
  _palette = lightPatternOptions.palette;
  _blendType = lightPatternOptions.blendType;
  _brightness = lightPatternOptions.brightness;
  _frequency = lightPatternOptions.frequency;
  _duration = lightPatternOptions.duration;
}

void LightPattern::initialize(LedController* pLedController)
{
  _pLedController = pLedController;
  _palette = CloudColors_p;
  _blendType = BLEND;
  _brightness = 255;
  _frequency = 100;
}

void LightPattern::display()
{
  display(_frequency);
}

void LightPattern::display(int frequency)
{
  _frequency = frequency;
  _pLedController->fillLEDsFromPaletteColors(_palette, _blendType, _brightness);
  _pLedController->displayPattern(_frequency);
}