#include "BlinkModule.h"
#include <Adafruit_NeoPixel.h>

//Give your Module a name
//it will be desplayed when you use the method log("Hello")
// -> Blink     Hello
const std::string BlinkModule::name()
{
    return "Blink";
}

//You can also give it a version
//will be displayed in Command Infos 
const std::string BlinkModule::version()
{
    return ""; // Leeren string zurückgeben, damit nur der Hash angezeigt wird in der Konsole
}

#define PIN        16
#define NUMPIXELS   1
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_RGB);

int counter = 0;
int lastmillis = 0;
bool ledState = false;
bool ledActive = false;
int interval = 0;
int color = 0;

//easy function to set led to a state
void setLed(bool state)
{
    ledState = state;

    if(ledState)
    {
        //turn led on
        pixels.setPixelColor(0, pixels.Color(color == 0 ? 255:0, color == 1 ? 255:0, color == 2 ? 255:0));
        pixels.show();
    } else {
        //turn led off
        pixels.clear();
        pixels.show();
    }
    
    //send state to ComObject 2
    KoAPP_state.value(ledState, DPT_Switch);
}

//will be called once
//only if knx.configured == true
void BlinkModule::setup()
{
    //read the color of the led
    //Size 2 bit; Offset 0; BitOffset 0
    color = ParamAPP_color;
    Serial.print("Parameter Color: ");
    Serial.println(color, HEX);

    //read if the led should blink
    //Size 1 bit; Offset 0; BitOffset 2
    bool blink = ParamAPP_blink;
    Serial.print("Parameter Blink: ");
    Serial.println(blink, HEX);

    //read the interval the led should blink
    //Size 8 bit; Offset 1; BitOffset 0
    uint8_t uinterval = ParamAPP_interval;
    Serial.print("Parameter Interval: ");
    Serial.println(uinterval);
    interval = blink ? (uinterval * 10) : -1;
    lastmillis = 0 - interval;

    Serial.println("Start");
}

//will be called every loop
//only if knx.configured == true
void BlinkModule::loop()
{
    //if channel(led) is activated by a knx-telegram
    if (ledActive)
    {
        //-1 if led should not blink
        //>=0 when the led should blink
        if (interval >= 0)
        {
            //check if interval is over
            if (lastmillis + interval < millis())
            {
                lastmillis = millis();
                //toggle led
                setLed(!ledState);
            }
        } else {
            //so the led should not blink
            //then jist turn it on if its off
            if (!ledState)
            {
                //turn led on
                setLed(true);
            }
        }
    }
    else if (ledState)
    {
        //if it is deactivated but the led is still on: turn it off
        setLed(false);
        Serial.print("halll");
    }
}

//will be called once a KO received a telegram
void BlinkModule::processInputKo(GroupObject& iKo)
{
    if (iKo.asap() == KoAPP_onoff.asap())
    {
        ledActive = iKo.value(DPT_Switch);
        Serial.print("Switch Callback ");
        Serial.println(ledActive ? "True" : "False");
    }
}

//will be called once after StartupDelay
void BlinkModule::processAfterStartupDelay()
{
}

// void BlinkModule::writeFlash()
// {
//     for (size_t i = 0; i < flashSize(); i++)
//     {
//         //openknx.flash.writeByte(0xd0 + i);
//     }
// }

// void BlinkModule::readFlash(const uint8_t* data, const uint16_t size)
// {
//     // printHEX("RESTORE:", data,  len);
// }

// uint16_t BlinkModule::flashSize()
// {
//     return 10;
// }

BlinkModule openknxBlinkModule;