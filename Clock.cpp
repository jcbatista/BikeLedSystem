#include "Clock.h"
#include <Arduino.h>

Clock::Clock()
{
  tick();
}

void Clock::tick()
{
  _current = millis();
}
