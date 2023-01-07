




|Name|Description|Required|
|---|---|---|
|KNX_BUTTON|Pin Number for ProgButton||
|KNX_LED|Pin Number for ProgLED||
|KNX_NO_AUTOMATIC_GLOBAL_INSTANCE|Stack won't create the knx instance automaticly. You need to create it manually.||
|KNX_NO_PRINT|||
|LWIP_DONT_PROVIDE_BYTEORDER_FUNCTIONS|Core won't provide byteorder functions. Stack provides those already.|**yes**|
|NO_KNX_CONFIG|||
|PIO_FRAMEWORK_ARDUINO_ENABLE_RTTI||**yes**|
|USERDATA_SAVE_SIZE|||
|USE_CEMI_SERVER|||
|USE_DATASECURE|Activate support for DataSecure Features.||
|USE_RP2040_EEPROM_EMULATION|||
|USE_RP2040_LARGE_EEPROM_EMULATION|||
|USE_USB|Activates features to use it as USB Interface. This will automaticly define *USE_CEMI_SERVER*||


### USE_USB
This will activate all usb functions.  
It will autmaticly define USE_CEMI_SERVER.

### USE_RP2040_EEPROM_EMULATION
This will activate the eeprom emulation on the rp2040