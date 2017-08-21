#ifndef Smoother_h
#define Smoother_h
 
#include "Arduino.h"
 
class Smoother {
  public:

    Smoother(int resolution);
    int average(int data);

  private:   
    int numReadings;
    int* readings;                // the readings from the analog input (Array)
    int readIndex;                // the index of the current reading
    int total;                     // the running total
    int averageVal;                   // the average

};
 
#endif
