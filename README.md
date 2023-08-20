# ILI948x_t40_p
## A basic display driver for ILI948X series on a Teensy 4.0

**Disclaimer: This is an experimental library, currently a WIP. I cannot guarantee that all functions will work nor can I guarantee that this library will work with other libraries. Use at your own risk**  

This library can communicate with an ILI9488/9486/9481 TFT LCD via an 8 bit parallel interface (8080)
It utilizes FlexIO to write data to the screen while offloading the task from the CPU.
It can only write an image array at the moment with defined start/end coordinates.
The default bus speed is set to 12Mhz and can be lowered or raised with a simple function call.

First include the library and create a constructor:
```
#include "ILI948x_t40_p.h"
#define CS 11
#define DC 13
#define RST 12
ILI948x_t40_p lcd = ILI948x_t40_p(DC,CS,RST);
```
You can use and GPIO pins for CS, DC and RST

Next, wire up your LCD - use Teensy pins:
* pin 21 - WR
* pin 20 - RD
* pin 19 - D0
* pin 18 - D1
* pin 14 - D2
* pin 15 - D3
* pin 17 - D4
* pin 16 - D5
* pin 22 - D6
* pin 23 - D7
   
Wire the RD pin on the LCD to 3.3v

in the setup function call:
```
ILI948x_t40_p::begin();
```
The default baud rate is 20Mhz

In the begin(n) function you can pass 2,4,8,12,20,24, 30 and 40 to lower or raise the baud rate.


Call the following function for a polling method write:
```
ILI948x_t40_p::pushPixels16bit(flexio_teensy_mm,0,0,480,320);
```

to push the image data, the arguments are as follows:
* uint16_t color array (RGB565)
* uint16_t x1
* uint16_t y1
* uint16_t x2
* uint16_t y2

Additional API's:


Set rotation: 1,2,3,4
```
ILI948x_t40_p::setRotation(n);
```

Invert display color (true/false)
```
ILI948x_t40_p::invertDisplay(bool);
```

![Image of TFT with Teensy MM image](https://github.com/david-res/ILI948x_t40_p/blob/master/mm_flexio_example.jpg)

