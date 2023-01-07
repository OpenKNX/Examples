# PlatformIO Build Flags
These flags are used to tell the KNX Stack what you wantor need.  
You can control the behavier and remove not needed components.  
You can finde them in your `platformio.ini`.


|Name|Description|Required|
|---|---|---|
|DBG_TRACE|||
|KNX_BUTTON|Pin Number for ProgButton||
|KNX_DEBUG_SERIAL|Serial where debug logs will be printed. Only if *KNX_NO_PRINT* is not defined.||
|KNX_FLASH_SIZE|Size of Flash. Must be  multiple of 4096. Only if *USE_RP2040_EEPROM_EMULATION* is not defined.|**yes**|
|KNX_LED|Pin Number for ProgLED. Also used for fatal Error display.||
|KNX_NO_AUTOMATIC_GLOBAL_INSTANCE|Stack won't create the knx instance automaticly. You need to create it manually.||
|KNX_NO_DEFAULT_UART|Create a knx instance without set *KNX_SERIAL*.||
|KNX_NO_SPI|Don't include SPI library||
|KNX_NO_PRINT|Don't print debug messages to *KNX_DEBUG_SERIAL*.||
|KNX_SERIAL|Serial to the BCU. Default is platform specific Serial.||
|KNX_WAIT_FOR_ADDR|After seeing a L2 packet start, stay in loop until address bytes are received and the AK/NAK packet is sent.||
|LWIP_DONT_PROVIDE_BYTEORDER_FUNCTIONS|Core won't provide byteorder functions. Stack provides those already.|**yes**|
|NCN5120|||
|NO_KNX_CONFIG|||
|PIO_FRAMEWORK_ARDUINO_ENABLE_RTTI||**yes**|
|SMALL_GROUPOBJECT|Reduces the size of each GroupObject from 19 Bytes to 8 Bytes.||
|USERDATA_SAVE_SIZE|||
|USE_BINSEARCH|Activate binary search in GroupAddressTable. Is faster with many different GroupAddresses.||
|USE_CEMI_SERVER|Activates CEMI Server. Required for *USE_USB*.||
|USE_DATASECURE|Activate support for DataSecure Features.||
|USE_IP|Activate KNX over IP support. Ony if **NO_KNX_CONFIG** is not defined.||
|USE_SAMD_EEPROM_EMULATION|Activate EEPROM Emulation||
|USE_RF|Activate KNX over RF support. Only if **NO_KNX_CONFIG** is not defined.||
|USE_RP2040_EEPROM_EMULATION|EEPROM Emulation from arduino-pico core (max 4k) can be used.||
|USE_RP2040_LARGE_EEPROM_EMULATION|A RAM-buffered Flash.||
|USE_TP|Activate KNX over TwistedPair support. Only if **NO_KNX_CONFIG** is not defined.||
|USE_USB|Activates features to use it as USB Interface. This will automaticly define *USE_CEMI_SERVER*||


#### KNX_NO_AUTOMATIC_GLOBAL_INSTANCE
By default the Stack will create a knx instance for you with the correct platform.  
Sometimes it is a good option to create this instance by your own. (Because you dont want to use a prog button)  
Once you added this flag you can create it by adding following line in your main code:
```C++
KnxFacade<xxxPlatform,BauXXX> knx;
```