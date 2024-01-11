#include "OpenKNX.h"
#include "hardware.h"

class BlinkModule : public OpenKNX::Module
{
	public:
		void loop() override;
		void setup() override;
		// Folgende Funktionen werden immer aufgerufen, egal ob konfiguriert oder nicht
		// Damit kann man die Info ob das Gerät konfiguriert ist selbst auswerten
		// void loop(bool configured) override;
		// void setup(bool configured) override;

		// Wenn -D OPENKNX_DUALCORE verwendet wird
		// void loop1() override;
		// void setup2() override;
		// Gilt ebenso
		// void loop1(bool configured) override;
		// void setup1(bool configured) override;

		void processAfterStartupDelay() override;
		void processInputKo(GroupObject &ko) override;

		const std::string name() override;
		const std::string version() override;
		
		// Wenn das Modul auch Daten im Flash speichern soll, werden folgenden Methoden benötigt.
		// void writeFlash() override;
		// void readFlash(const uint8_t* data, const uint16_t size) override;
		// uint16_t flashSize() override;
};

extern BlinkModule openknxBlinkModule;