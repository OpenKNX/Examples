#include "LogModule.h"

const char* LogModule::name()
{
    return "Log";
}

const char* LogModule::version()
{
    return "0.0dev";
}

void LogModule::setup()
{
    for (uint8_t i = 0; i < BTN_ChannelCount; i++)
    {
        _channels[i] = new LogChannel(i);
        _channels[i]->setup();
    }
}

int lastmil = 0;
bool ledState = false;

void LogModule::loop()
{
    for (uint8_t i = 0; i < BTN_ChannelCount; i++)
    {
        _channels[i]->loop();
    }

    if(lastmil + 1000 < millis())
    {
        lastmil = millis();
        ledState = !ledState;
        digitalWrite(25, ledState);
    }
}

void LogModule::processInputKo(GroupObject& iKo)
{
    for (uint8_t i = 0; i < BTN_ChannelCount; i++)
        _channels[i]->processInputKo(iKo);
}

void LogModule::processAfterStartupDelay()
{
    for (uint8_t i = 0; i < BTN_ChannelCount; i++)
        _channels[i]->readStatus();
}

// void LogModule::writeFlash()
// {
//     for (size_t i = 0; i < flashSize(); i++)
//     {
//         //openknx.flash.writeByte(0xd0 + i);
//     }
// }

// void LogModule::readFlash(const uint8_t* data, const uint16_t size)
// {
//     // printHEX("RESTORE:", data,  len);
// }

// uint16_t LogModule::flashSize()
// {
//     return 10;
// }