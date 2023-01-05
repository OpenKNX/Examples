#include <Arduino.h>
#include <SoftwareSerial.h>
#include <knx.h>

SoftwareSerial ser(D8, D5);

void setup()
{
    pinMode(25, OUTPUT);
    //Serial.begin(115200);

    //ArduinoPlatform::SerialDebug = &Serial;
    //ser.begin(9600);

}

void loop()
{
    
}