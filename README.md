# Data Smoothing in the Arduino IDE

Library/class written for the Arduino IDE. Based on the [Smoothing example](https://www.arduino.cc/en/Tutorial/Smoothing) that comes with the Arduino IDE.

To use:

`#include "Smoother.h"
Smoother foo = Smoother(resolution);`

In loop, smooth data by using the average() method:

`foo.average(rawData);`