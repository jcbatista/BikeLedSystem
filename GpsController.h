#ifndef GpsController_h
#define GpsController_h

#include <Adafruit_GPS.h>

class GpsController
{
  private:
    boolean usingInterrupt;
    void useInterrupt(boolean v);
    uint32_t timer;
    
  public:
    GpsController();
    void initialize();
    void process();
};

#endif // GpsController_h
