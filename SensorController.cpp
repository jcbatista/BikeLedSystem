#include "SensorController.h"

SensorController::SensorController()
{
  _accel = Adafruit_LSM303_Accel_Unified(54321);
}

void SensorController::initialize()
{
  /* Initialise the sensor */
  if(!_accel.begin())
  {
    /* There was a problem detecting the ADXL345 ... check your connections */
    Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
    while(1);
  } 
}

void SensorController::displaySensorDetails()
{
  sensor_t sensor;
  _accel.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" m/s^2");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" m/s^2");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" m/s^2");  
  Serial.println("------------------------------------");
  Serial.println("");
}

void SensorController::process()
{
  /* Get a new sensor event */ 
  sensors_event_t event; 
  _accel.getEvent(&event);
}

/*
double  previous = -1;
double current = 0;
int DELTA=20;

bool SensorController::processAccelerationData(sensors_event_t& event)
{
  bool treshholdReached = false;
  current = event.acceleration.x + event.acceleration.y + event.acceleration.z;
  if(previous!=current)
  {
    double x = abs(current-previous);
    if(x>DELTA)
    {
      treshholdReached = true;
    }
    
    previous=current;  
  }
  
  return treshholdReached;
}
*/
