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
  _updatesPerSecond = 100;
  _startIndex = 0;
}

void LightPattern::display()
{
  display(_updatesPerSecond);
}

void LightPattern::display(int updatesPerSecond)
{
  _updatesPerSecond = updatesPerSecond;
  _startIndex = _startIndex + 1;
  _pLedController->fillLEDsFromPaletteColors(_palette, _blendType, _brightness, _startIndex);
  _pLedController->displayPattern(_updatesPerSecond);
}

