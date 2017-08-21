#include "Arduino.h"
#include "Smoother.h"

Smoother::Smoother(int resolution)
{
  numReadings = resolution;
  readings = new int [numReadings];            // the readings from the analog input (Array)
  readIndex = 0;                    // the index of the current reading
  total = 0;                        // the running total
  averageVal = 0;                   // the average  
  
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  } 

}
 
int Smoother::average(int data) {

  // for debugging
  // Serial.print("ReadIndex: ");
  // Serial.println(readIndex);
  // Serial.print("Readings: ");
  // for (int i = 0; i<= numReadings; i++) {
  //   Serial.print(readings[i]);
  //   Serial.print(", ");
  // }
  // Serial.println();

  total = total - readings[readIndex];          // subtract the last reading
  readings[readIndex] = data;                   // read from the sensor
  total = total + readings[readIndex];          // add the reading to the total
  readIndex = readIndex + 1;                    // advance to the next position in the array
  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  averageVal = total / numReadings;      // calculate the average
  delay(200);                            // delay in between reads for stability
  
  return averageVal;    
}


/*------------------------------------------------------------------------------
  Originally developed to work with an arduino using the StandardFirmata 
  library as detailed on http://playground.arduino.cc/Interfacing/Processing
  
  To use it with an arduino, set up an Arduino object as described in the 
  link above, and assign the pin data to rawData in the draw() loop. 
  Ex: rawData = myArduino.analogRead(0);
  
  Using the Smoother class requires the following:
  
  1. calling the object. 
     Ex: Smoother foo;
  2. initializing the object in the setup() function
     Ex: foo = new Smoother(resolution);
  3. setting your data source in the draw() loop
     Ex: rawData = DATA SOURCE
  4. to smooth your data, use the average(rawData) method
     Ex smoothedValue = foo.average(rawData);
     
  Note: The example data in this demo is randomized data between 0-1000. 
  The smoothed data should appear to waver around the midpoint (500).
  
------------------------------------------------------------------------------*/

