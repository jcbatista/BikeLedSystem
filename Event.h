#ifndef Event_h
#define Event_h
#include "Clock.h"

#define EVENT_DURATION_INFINITE -1
#define EVENT_STOPPED -1

/*
 An event is a "pattern" being drawn for a specific durations
 */

class Event 
{
protected:  
  unsigned long _start;
  unsigned long  _duration;
  Clock* _pClock;
  
public:
 Event(Clock* pClock);
 Event(Clock* pClock, unsigned long duration);
 void start();
 void stop();
 bool isStarted();
 bool isCompleted();
 bool isInfinite();
};

#endif // Event_h


