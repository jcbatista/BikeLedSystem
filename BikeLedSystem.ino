#include <Button.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <FastLED.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include "SensorController.h"
#include "LedController.h"
#include "GpsController.h"
#include "Clock.h"
#include "Event.h"
#include "LightPatternManager.h"

Clock clock;
SensorController sensorController;
GpsController gpsController;

LedController ledController;
LightPatternManager ligthPatternMgr(&clock, &ledController);

// SoftwareSerial mySerial(10, 11); // RX, TX

// Start button setup -> using the button master library
#define BUTTON_PIN 5       //Connect a tactile button switch (or something similar)
                           //from Arduino pin 2 to ground.
#define PULLUP true        //To keep things simple, we use the Arduino's internal pullup resistor.
#define INVERT true        //Since the pullup resistor will keep the pin high unless the
                           //switch is closed, this is negative logic, i.e. a high state
                           //means the button is NOT pressed. (Assuming a normally open switch.)
#define DEBOUNCE_MS 20     //A debounce time of 20 milliseconds usually works well for tactile button switches.

#define LED_PIN 13         //The standard Arduino "Pin 13" LED.
#define LONG_PRESS 1000    //We define a "long press" to be 1000 milliseconds.
Button myBtn(BUTTON_PIN, PULLUP, INVERT, DEBOUNCE_MS);    //Declare the button

// end button setup
char buffer[256];

void setup() {
  delay( 3000 ); // power-up safety delay

  Serial.begin(9600);
  
  Serial.println("Accelerometer Test"); 
  Serial.println("");

  //sensorController.initialize();
  ledController.initialize();
  gpsController.initialize();
  
  /* Display some basic information on this sensor */
  sensorController.displaySensorDetails();
}

int currentIndex = -1;

void loop() {
  clock.tick();

  myBtn.read();                //Read the button
  if (myBtn.wasReleased()){
    Serial.println("Button Press!!!");
    ligthPatternMgr.next();
  }

   ligthPatternMgr.display();

  int index = ligthPatternMgr.getCurrentIndex();
  if(currentIndex != index){
    currentIndex=index;
    sprintf(buffer,"currentIndex=%d", currentIndex);
    Serial.println(buffer);
  }

  gpsController.process();
  //sensorController.process(); 
  
  //delay(500); 
  /* Display the results (acceleration is measured in m/s^2) */
  /*
  Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("  ");
  Serial.println("m/s^2 ");
  */
}

