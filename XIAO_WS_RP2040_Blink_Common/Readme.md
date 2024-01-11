# XIAO_WS_RP2040_Blink_Common
In this example we create a KNX Device as actuator with one channel.  
The state of the channel will be displayed by a LED (Buildin NeoPixel).
We use the [OGM-Common](https://github.com/OpenKNX/OGM-Common) to initialize the KNX stack.  

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