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
    logInfoP("Setup");
}

void LogChannel::loop()
{
    if(lastHello + ((_channelIndex+1) * 1000) < millis())
    {
        lastHello = millis();
        if(_channelIndex == 0)
        {
            logErrorP("You can also print a red error message");
        } else if(_channelIndex == 1) {
            logIndentUp();
            logInfoP("A message a bit more right");
            logIndentDown();
        } else {
            logInfoP("Hallo");
        }
    }
}

void LogChannel::readStatus()
{
    
}

void LogChannel::processInputKo(GroupObject &ko)
{

}