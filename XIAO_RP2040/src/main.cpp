#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
#include <knx.h>
#include "hardware.h"

#define goLedSwitch knx.getGroupObject(1)
#define goLedState knx.getGroupObject(2)

KnxFacade<RP2040ArduinoPlatform, Bau07B0> knx;

SoftwareSerial ser(D8, D5);
int Power = 11;
int PIN = 12;
#define NUMPIXELS 1

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void progLedOff()
{
    ser.println("ProgMode OFF");
    pixels.clear();
    pixels.show();
}

void progLedOn()
{
    ser.println("ProgMode ON");
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));
    pixels.show();
}


int counter = 0;
int lastmillis = 0;
bool ledState = false;
bool ledActive = false;
int interval = 0;
int color = 0;

void setLed(bool state)
{
    ledState = state;

    if(ledState)
    {
        pixels.setPixelColor(0, pixels.Color(color == 0 ? 255:0, color == 1 ? 255:0, color == 2 ? 255:0));
        pixels.show();
    } else {
        pixels.clear();
        pixels.show();
    }
    goLedState.value(ledState);
}

void switchCallback(GroupObject& go)
{
    ledActive = go.value();
    ser.print("Switch Callback ");
    ser.println(go.value() ? "True" : "False");
}

void setup()
{
    //pinMode(25, OUTPUT);
    //digitalWrite(25, HIGH);
    ser.begin(115200);
    //delay(5000);
    //digitalWrite(25, LOW);

    pixels.begin();
    pinMode(Power, OUTPUT);
    digitalWrite(Power, HIGH);
    pixels.setPixelColor(0, pixels.Color(233, 242, 205));
    pixels.show();
    delay(1000);
    pixels.clear();
    pixels.show();

    ArduinoPlatform::SerialDebug = &ser;

    knx.setProgLedOffCallback(progLedOff);
    knx.setProgLedOnCallback(progLedOn);

    knx.readMemory();

    if (knx.configured())
    {
        byte col = (knx.paramByte(PARAM_color) & PARAM_color_Mask) >> PARAM_color_Shift;
        ser.print("Parameter Color: ");
        ser.println(col, HEX);
        color = col;
        byte blink = (knx.paramByte(PARAM_blink) & PARAM_blink_Mask) >> PARAM_blink_Shift;
        ser.print("Parameter Blink: ");
        ser.println(blink, HEX);
        uint8_t uinterval = knx.paramByte(PARAM_interval);
        ser.print("Parameter Interval: ");
        ser.println(uinterval);
        interval = blink == 1 ? (uinterval * 10) : -1;
        lastmillis = 0 - interval;

        goLedSwitch.callback(switchCallback);
        goLedSwitch.dataPointType(DPT_Switch);
        goLedState.dataPointType(DPT_Switch);
        ser.println("Callbacks linked");
    } else {
        ser.println("Nicht konfiguriert!");
    }
        

    knx.start();

    //knx.progMode(true);
    ser.println("Start");
}

void loop()
{
    knx.loop();

    if (!knx.configured()) return;


    if(ledActive)
    {
        if(interval >= 0)
        {
            if(lastmillis + interval < millis())
            {
                lastmillis = millis();
                setLed(!ledState);
            }
        } else {
            if(!ledState)
            {
                setLed(true);
            }
        }
    } else if(ledState)
    {
        setLed(false);
    }
    
}