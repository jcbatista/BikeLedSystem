#include "LightPattern.h"

LightPattern::LightPattern(CRGBPalette16 palette, TBlendType blendType, Clock* pClock, int duration): Event(pClock, duration)
{
  _palette = palette;
  _blendType = blendType;
}
