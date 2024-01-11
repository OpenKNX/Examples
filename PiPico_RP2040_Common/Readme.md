# PiPico_RP2040_Blink
In this example we create a simple blink/log project.  
We use the [OGM-Common](https://github.com/OpenKNX/OGM-Common) to initialize the knx stack.  
Also we create a Module which let the builtin led blink and four channels who will log "Hello" with different interval.  

## Mandatory!
Your KNX Device must be configured to run setup/loop of Modules/Channels!