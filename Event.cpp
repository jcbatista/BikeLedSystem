#include "Event.h"

Event::Event(Clock* pClock)
{
  _pClock = pClock;
  _duration = EVENT_DURATION_INFINITE;
  _start = EVENT_STOPPED;
}

Event::Event(Clock* pClock, unsigned long  duration)
{
  _pClock = pClock;
  _duration = duration;
  _start = EVENT_STOPPED;
}

void Event::start() 
{
  _start = _pClock->getCurrent();
}

void Event::stop()
{
  if(!isStarted() || isInfinite())
    return;

  _start = EVENT_STOPPED;
}

bool Event::isInfinite()
{
  return _duration == EVENT_DURATION_INFINITE;
}

bool Event::isStarted()
{
  return _start != EVENT_STOPPED;
}

bool Event::isCompleted()
{
  if(!isStarted())
  {
    return true; 
  }

  if(isInfinite())
  {
    return false;
  }

  unsigned long end = _start + _duration;
  bool completed = end < _pClock->getCurrent();
  if(completed)
  {
    _start = EVENT_STOPPED;
  }

  return completed;
}

