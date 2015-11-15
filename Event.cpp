#include "Event.h"

Event::Event(Clock* pClock)
{
  _pClock = pClock;
  _duration = -1;
  _start = -1;
}

Event::Event(Clock* pClock, int duration)
{
  _pClock = pClock;
  _duration = duration;
  _start = -1;
}

void Event::start() 
{
  _start = _pClock->getCurrent();
}

void Event::stop()
{
  if(!isStarted() || isCompleted())
    return;
    
  _start = -1;
}

bool Event::isStarted()
{
  return _start != -1;
}

bool Event::isCompleted()
{
  if(_duration == EVENT_DURATION_NONE)
  {
    return false;
  }
  int end = _start + _duration;
  return end > _pClock->getCurrent();
}

