#ifndef LightPattern_h
#define LightPattern_h

#include <FastLED.h>
#include "Event.h"

class LightPattern: public Event
{
  private:
    CRGBPalette16 _palette;
    TBlendType   _blendType;
  
  public:
    LightPattern(CRGBPalette16 palette, TBlendType blendType, Clock* pClock, int duration);

};
#endif // LightPattern_h
