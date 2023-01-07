## Getting started
I assume you have installed VS Code with the PlatformIO extension.  
  
First you need to create a new project with platformio.  
Select your board and after creation open the `platformio.ini`.  
Here add the following lines:
```
board_build.core = earlephilhower
lib_ldf_mode = deep+
lib_deps = 
	https://github.com/thelsing/knx
build_flags = 
	-DPIO_FRAMEWORK_ARDUINO_ENABLE_RTTI
	-DLWIP_DONT_PROVIDE_BYTEORDER_FUNCTIONS
	-DMASK_VERSION=0x07B0
```
Read more about the [Flags here](doc/flags.md).


## Next Steps
[Include the Stack](doc/main.md)  
[Setup your hardware](doc/hardware.md)  



### Additional info
[Callbacks](doc/callbacks.md)  
