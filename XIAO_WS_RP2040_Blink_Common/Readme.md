# XIAO_WS_RP2040_Blink_Common
In this example we create a KNX Device as actuator with one channel.  
The state of the channel will be displayed by a LED (Buildin NeoPixel).
We use the [OGM-Common](https://github.com/OpenKNX/OGM-Common) to initialize the KNX stack.  

### Things you need
If you want to use OGM-Common you need some things for now:  
Create three files in include:
 - hardware.h this includes defines for hardware specific defines
    - **PROG_LED_PIN / PROG_LED_PIN_ACTIVE_ON** -> Config for led pin
    - **PROG_BUTTON_PIN** -> Pin for prog button
    - **KNX_UART_TX_PIN / KNX_UART_RX_PIN** -> pins for Serial1
  - knxprod.h this includes the created header file for your KnxProd
    - **MAIN_OpenKnxId** -> your [OpenKnxId](https://github.com/OpenKNX/OpenKNX/wiki/Information-about-KnxProd#applicationnumber) (first byte of ApplicationNumber 0xA?--)
    - **MAIN_ApplicationNumber** -> your AppNumber (second byte of ApplicationNumber 0x--??)
    - **MAIN_ApplicationVersion** -> VersionNumber of the Application
    - **MAIN_OrderNumber** -> The OrderNumber of the Product
To copy the needed files to OGM-Common you need the file "extra_script.py". it will just copy the three files to the include folder of OGM-Common.

Your platformio.ini should now look like this:
```ini
[env:seeed_xiao_rp2040]
platform = raspberrypi
board = seeed_xiao_rp2040
framework = arduino
board_build.core = earlephilhower
board_build.filesystem_size = 0.5m
monitor_port = COM7
monitor_speed = 115200
monitor_raw = yes ;for color in terminal
lib_ldf_mode = deep+
lib_deps = 
	https://github.com/thelsing/knx
	https://github.com/OpenKnx/OGM-Common
	adafruit/Adafruit NeoPixel
build_flags = 
	-D PIO_FRAMEWORK_ARDUINO_ENABLE_RTTI
	-D LWIP_DONT_PROVIDE_BYTEORDER_FUNCTIONS
	-D MASK_VERSION=0x07B0
	-D KNX_FLASH_SIZE=4096
	-D KNX_FLASH_OFFSET=0x180000
	-D OPENKNX_FLASH_SIZE=4096
	-D OPENKNX_FLASH_OFFSET=0x180000
	-Wno-unknown-pragmas
	-D SMALL_GROUPOBJECT
	-D SERIAL_DEBUG=Serial
extra_scripts = extra_script_seeed_xiao_rp2040.py
```

### ComObjects
The KnxProd will have two ComObjects:
|Number|Name|Function|DPST|Description|
|---|---|---|---|---|
|1|LED|Switch|1.001 Switch|Turn LED On or Off
|2|LED|Status|1.001 Switch|Status of the Channel

### Parameters
We have three Parameters. 
|Name|Type|Size|Offset|BitOffset|
|---|---|---|---|---|
|Color|Enum (Red, Green, Blue)|2 bit|0|0|
|Blink|Checkbox|1 bit|0|2|
|Interval|Unsigned Integer|8 bit|1|0|
>Interval is only visible if the Parmeter blink is true.  

### Function
If we receive a KNX-Telegram with `True` on ComObject 1 the LED will turn on and ComObject 2 will send a KNX-Telegram with `True`.  
If Blink is true the LED will start blinking with the given Interval (value * 10ms, example 10: 100ms off - 100ms on).  
If we receive a KNX-Telegram with `False` on ComObject 1 the LED will turn off and ComObject 2 will send a KNX-Telegram with `False`.  

## Mandatory!
Your KNX Device must be configured to run setup/loop of Modules/Channels!