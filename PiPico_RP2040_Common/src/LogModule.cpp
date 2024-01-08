#include "LogModule.h"

//Give your Module a name
//it will be desplayed when you use the method log("Hello")
// -> Log     Hello
const std::string LogModule::name()
{
    return "Log";
}

//You can also give it a version
//will be displayed in Command Infos 
const std::string LogModule::version()
{
    return ""; // Leeren string zurückgeben, damit nur der Hash angezeigt wird in der Konsole
}

//will be called once
//only if knx.configured == true
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

//will be called every loop
//only if knx.configured == true
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

//will be called once a KO received a telegram
void LogModule::processInputKo(GroupObject& iKo)
{
    for (uint8_t i = 0; i < BTN_ChannelCount; i++)
        _channels[i]->processInputKo(iKo);
}

//will be called once after StartupDelay
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

LogModule openknxLogModule;