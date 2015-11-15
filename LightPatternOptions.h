#ifndef LightPatternOptions_h
#define LightPatternOptions_h

#include <FastLED.h>
#include "event.h"

struct LightPatternOptions
{
    CRGBPalette16 palette;
    TBlendType    blendType;
    uint8_t       frequency;
    uint8_t       brightness;
    int           duration = EVENT_DURATION_NONE;
};

#endif // LightPatternOptions_h
