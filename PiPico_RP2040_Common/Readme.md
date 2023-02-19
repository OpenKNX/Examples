# PiPico_RP2040_Blink
In this example we create a simple blink/log project.  
We use the [OGM-Common](https://github.com/OpenKNX/OGM-Common) to initialize the knx stack.  
Also we create a Module which let the builtin led blink and four channels who will log "Hello" with different interval.  

### Things you need
If you want to use OGM-Common you need some things for now:  
Create three files in include:
 - hardware.h this includes defines for hardware specific defines
    - **PROG_LED_PIN / PROG_LED_PIN_ACTIVE_ON** -> Config for led pin
    - **PROG_BUTTON_PIN** -> Pin for prog button
    - **KNX_UART_TX_PIN / KNX_UART_RX_PIN** -> pins for Serial1
    - **BTN_ChannelCount** (optional) -> How many channels will be created
  - knxprod.h this includes the created header file for your KnxProd
    - **MAIN_OpenKnxId** -> your [OpenKnxId](https://github.com/OpenKNX/OpenKNX/wiki/Information-about-KnxProd#applicationnumber) (first byte of ApplicationNumber 0xA?--)
    - **MAIN_ApplicationNumber** -> your AppNumber (second byte of ApplicationNumber 0x--??)
    - **MAIN_ApplicationVersion** -> VersionNumber of the Application
    - **MAIN_OrderNumber** -> The OrderNumber of the Product
To copy the needed files to OGM-Common you need the file "extra_script.py". it will just copy the three files to the include folder of OGM-Common.

Your platformio.ini should now look like this:
```ini
[env:pico]
platform = raspberrypi
board = pico
framework = arduino
board_build.core = earlephilhower
monitor_speed = 115200

lib_ldf_mode = deep+
lib_deps = 
	https://github.com/thelsing/knx#Flash_batchwrite ;specify branch
	https://github.com/OpenKnx/OGM-Common#modular ;specify branch
  	khoih-prog/TimerInterrupt_Generic ;needed for something

build_flags = 
	-D PIO_FRAMEWORK_ARDUINO_ENABLE_RTTI
	-D LWIP_DONT_PROVIDE_BYTEORDER_FUNCTIONS
	-D MASK_VERSION=0x07B0
	-D KNX_FLASH_SIZE=4096
	-D KNX_FLASH_OFFSET=0x180000
	-Wno-unknown-pragmas
	-D SMALL_GROUPOBJECT ;must be set for Modules
	-D SERIAL_DEBUG=Serial

extra_scripts = extra_script.py ;script to copy files
```

## Mandatory!
Your KNX Device must be configured to run setup/loop of Modules/Channels!