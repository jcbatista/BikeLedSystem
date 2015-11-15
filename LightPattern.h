#ifndef LightPattern_h
#define LightPattern_h

#include "LightPatternOptions.h"
#include "LedController.h"
#include "Event.h"

class LightPattern: public Event
{
  private:
    LedController* _pLedController;
    CRGBPalette16 _palette;
    TBlendType   _blendType;
    uint8_t _frequency;
    uint8_t _brightness;
    void initialize(LedController* pLedController);
    
  public:
    LightPattern(Clock* pClock, LedController* pLedController);
    LightPattern(int duration, Clock* pClock, LedController* pLedController);
    LightPattern(LightPatternOptions lightPatternOptions, Clock* pClock, LedController* pLedController);
    void display();
    void display(int frequency);
};
#endif // LightPattern_h
