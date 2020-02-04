#include "hx711adc.h"

Hx711adc adc(6,7);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a = adc.read_data();
  Serial.println(a);
  delay(2000);
}
