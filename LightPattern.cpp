#include "LightPattern.h"

LightPattern::LightPattern(Clock* pClock, LedController* pLedController): Event(pClock)
{
  initialize(pLedController);
}

LightPattern::LightPattern(int duration, Clock* pClock, LedController* pLedController): Event(pClock, duration)
{
  initialize(pLedController);
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

