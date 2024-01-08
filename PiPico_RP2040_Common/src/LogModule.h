#include "LogChannel.h"
#include "OpenKNX.h"
#include "hardware.h"

class LogModule : public OpenKNX::Module
{
	public:
		void loop() override;
		void setup() override;

		// Wenn -D OPENKNX_DUALCORE verwendet wird
		// void loop1() override;
		// void setup2() override;
		void processAfterStartupDelay() override;
		void processInputKo(GroupObject &ko) override;

		const std::string name() override;
		const std::string version() override;

		// Wenn das Modul auch Daten im Flash speichern soll, werden folgenden Methoden benötigt.
		// void writeFlash() override;
		// void readFlash(const uint8_t* data, const uint16_t size) override;
		// uint16_t flashSize() override;

	private:
		LogChannel *_channels[BTN_ChannelCount];
};

//Wir benutzen das, um in main besser auf das Modul zugreifen zu können
extern LogModule openknxLogModule;