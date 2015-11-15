#ifndef Event_h
#define Event_h
#include "Clock.h"

#define EVENT_DURATION_NONE -1

/*
 An event is a "pattern" being drawn for a specific durations
 */

class Event 
{
protected:  
  int _start;
  int _duration;
  Clock* _pClock;
  
public:
 Event(Clock* pClock);
 Event(Clock* pClock, int duration);
 void start();
 void stop();
 bool isStarted();
 bool isCompleted();
};

#endif // Event_h


