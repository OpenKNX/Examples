#include <Arduino.h>
#include "OpenKNX.h"
#include "LogModule.h"

void setup()
{
	//Bei Firmwareänderungen, die keine neue knxprod benötigen, kann die Revision erhöht werden.
	const uint8_t firmwareRevision = 0;
    openknx.init(firmwareRevision);
    openknx.addModule(1, openknxLogModule);
    //openknx.addModule(9, openknxFileTransferModule); Es können auch weitere Module hinzugefügt werden
    openknx.setup();
}

void loop()
{
	openknx.loop();
}

//Wenn -D OPENKNX_DUALCORE verwendet wird
/*
void setup1()
{
	openknx.setup1();
}

void loop1()
{
	openknx.loop1();
}
*/