#include <Wire.h>
#include <SoftwareSerial.h>
#include <FastLED.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include "SensorController.h"
#include "LedController.h"
#include "Clock.h"
#include "Event.h"
#include "LightPatternManager.h"

SensorController sensorController;
LedController ledController;

Clock clock;
LightPatternManager ligthPatternMgr(&clock, &ledController);

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  delay( 3000 ); // power-up safety delay

  Serial.begin(9600);
  Serial.println("Accelerometer Test"); 
  Serial.println("");

  sensorController.initialize();
  ledController.initialize();

  /* Display some basic information on this sensor */
  sensorController.displaySensorDetails();
  
  // set the data rate for the SoftwareSerial port
  mySerial.begin(4800);
  mySerial.println("Hello, world?");
}

void loop()
{
  clock.tick();
  ligthPatternMgr.display();
  sensorController.process(); 
  //delay(500); 
  /* Display the results (acceleration is measured in m/s^2) */
  /*
  Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("  ");
  Serial.println("m/s^2 ");
  */
}

