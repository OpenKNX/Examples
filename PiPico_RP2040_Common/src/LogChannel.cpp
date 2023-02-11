#include "LogChannel.h"
#include <set>

LogChannel::LogChannel(uint8_t index)
{
    _channelIndex = index;
}

const char *LogChannel::name()
{
    return "Log";
}

void LogChannel::setup()
{
    
}

void LogChannel::loop()
{
    log("Nur ein test");
}

void LogChannel::readStatus()
{
    
}

void LogChannel::processInputKo(GroupObject &ko)
{

}