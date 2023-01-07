## Include the Stack
In your `main.cpp` include the stack with `#include "knx.h"` in the first line.  
If your platform is supported by the stack it will create automaticly an instance of knx.  

Also add some stuff to make the stack work.
```C++
#include <Arduino.h>
#include <knx.h>

void setup()
{
    knx.readMemory();

    if (knx.configured())
    {
        //read parameters and setup your device
    }
        
    knx.start(); //start stack
}

void loop()
{
    knx.loop();

    if (!knx.configured()) 
        return; //do nothing if not configured

    //do some stuff
}

```