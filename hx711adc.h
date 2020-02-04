#ifndef Hx711adc_h
#define Hx711adc_h

#include <Arduino.h>

class Hx711adc
{
public:
    Hx711adc (int pin1,int pin2);
    int read_data();
    unsigned long readCount(void);

private:
    uint8_t pinNumber1;
    uint8_t pinNumber2;
};

#endif