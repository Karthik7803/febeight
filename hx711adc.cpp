#include <Arduino.h>
#include "hx711adc.h"

Hx711adc::Hx711adc(int pin1, int pin2)
{
    pinMode(pin1, OUTPUT);
    pinNumber1 = pin1;
    pinMode(pin2, OUTPUT);
    pinNumber2 = pin2;
}

int Hx711adc::read_data()
{
    float y = 1;
    for (int h = 0; h < 2; h++)
    {
        long count = 0;
        for (int i = 0; i < 50; i++)
        {
            count = readCount();
            Serial.println(count);
            float w = 0;
            w = count / 10;
            y = w + y;
            delay(1);
        }
        y = y / 50;
    }
    return y;
}

unsigned long Hx711adc::readCount(void)
{
    unsigned long Count;
    unsigned char i;
    pinMode(pinNumber2, OUTPUT);
    digitalWrite(pinNumber2, HIGH);
    digitalWrite(pinNumber1, LOW);
    Count = 0;
    pinMode(pinNumber2, INPUT);
    while (digitalRead(pinNumber2));
    for (i = 0; i < 24; i++)
    {
        digitalWrite(pinNumber1, HIGH);
        Count = Count << 1;
        digitalWrite(pinNumber1, LOW);
        if (digitalRead(pinNumber2))
            Count++;
    }
    digitalWrite(pinNumber1, HIGH);
    Count = Count ^ 0x800000;
    digitalWrite(pinNumber1, LOW);
    return (Count);
}