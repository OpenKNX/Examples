#include <Arduino.h>
#include "OpenKNX.h"
#include "LogModule.h"

void setup()
{
	//usually openknx.setup will take care of the begin
	//but we will use it to print "Starte" before setup
	//to show when common will start
	SERIAL_DEBUG.begin(115200);
	delay(10000);
	SERIAL_DEBUG.println("Starte");

	const uint8_t firmwareRevision = 0;
    openknx.init(firmwareRevision);
    openknx.addModule(1, new LogModule());
    openknx.setup();
}

void loop()
{
	openknx.loop();
}