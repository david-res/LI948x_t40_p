#include "ILI948x_t40_p.h"
#include "flexio_teensy_mm.c"
ILI948x_t40_p lcd = ILI948x_t40_p(13,11,12); //(dc, cs, rst)

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.print(CrashReport);
  
  lcd.begin();
  lcd.setBitDepth(16);
  lcd.setRotation(3);
}

void loop() {
  delay(1000);
  lcd.pushPixels16bit(flexio_teensy_mm,0,0,479,319); // 480x320
}
