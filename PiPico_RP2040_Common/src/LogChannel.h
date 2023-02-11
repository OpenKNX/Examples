#include "OpenKNX.h"

class LogChannel : public OpenKNX::Channel
{
    private:
        uint8_t _channelIndex;
    public:
        LogChannel(uint8_t index);

        void setup() override;
        void loop() override;
        void processInputKo(GroupObject &ko) override;
        const char *name() override;
        void readStatus();
};