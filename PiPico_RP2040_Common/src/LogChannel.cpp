#include "LogChannel.h"
#include <set>

LogChannel::LogChannel(uint8_t index)
{
    _channelIndex = index;
}

const std::string LogChannel::name()
{
    return "Log";
}

void LogChannel::setup()
{
    log("Setup");
    Serial.print("ChannelIndex: ");
    Serial.println(_channelIndex);
}

void LogChannel::loop()
{
    if(lastHello + ((_channelIndex+1) * 1000) < millis())
    {
        lastHello = millis();
        log("Hallo");
    }
}

void LogChannel::readStatus()
{
    
}

void LogChannel::processInputKo(GroupObject &ko)
{

}