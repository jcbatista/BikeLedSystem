#ifndef SensorController_h
#define SensorController_h

#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>

class SensorController
{
  private:
     // Assign a unique ID to this sensor at the same time
     Adafruit_LSM303_Accel_Unified _accel;
 
  public:
    SensorController();
    void initialize();
    void process();
    void displaySensorDetails();
    bool processAccelerationData(sensors_event_t& event);
};

#endif // SensorController_h
