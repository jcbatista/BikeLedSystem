#ifndef LightPattern_h
#define LightPattern_h

#include <FastLED.h>
#include "LedController.h"
#include "Event.h"

class LightPattern: public Event
{
  private:
    LedController* _pLedController;
    CRGBPalette16 _palette;
    TBlendType   _blendType;
    uint8_t _updatesPerSecond;
    uint8_t _brightness;
    uint8_t _startIndex;
    void initialize(LedController* pLedController);
    
  public:
    LightPattern(Clock* pClock, LedController* pLedController);
    LightPattern(int duration, Clock* pClock, LedController* pLedController);
    void display();
    void display(int updatesPerSecond);
};
#endif // LightPattern_h
