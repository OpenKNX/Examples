#pragma once

#define paramDelay(time) (uint32_t)( \
            (time & 0xC000) == 0xC000 ? (time & 0x3FFF) * 100 : \
            (time & 0xC000) == 0x0000 ? (time & 0x3FFF) * 1000 : \
            (time & 0xC000) == 0x4000 ? (time & 0x3FFF) * 60000 : \
            (time & 0xC000) == 0x8000 ? ((time & 0x3FFF) > 1000 ? 3600000 : \
                                         (time & 0x3FFF) * 3600000 ) : 0 )
//--------------------Allgemein---------------------------
#define MAIN_OpenKnxId 0xFA
#define MAIN_ApplicationNumber 0xAF
#define MAIN_ApplicationVersion 0x12
#define MAIN_OrderNumber "TA-00002.1" //may not work with multiple devices on same hardware or app on different hardware
#define MAIN_ParameterSize 2
#define MAIN_MaxKoNumber 2


#define APP_color		0x0000
#define APP_color_Shift	6
#define APP_color_Mask	0x0003
// Offset: 0, Size: 2 Bit, Text: Farbe
#define ParamAPP_color ((uint)((knx.paramByte(0) >> APP_color_Shift) & APP_color_Mask))
#define APP_blink		0x0000
// Offset: 0, BitOffset: 2, Size: 1 Bit, Text: Blinken?
#define ParamAPP_blink knx.paramBit(0, 2)
#define APP_interval		0x0001
// Offset: 1, Size: 8 Bit (1 Byte), Text: Interval
#define ParamAPP_interval ((uint)((knx.paramByte(1))))
//!< Number: 1, Text: LED, Function: Schalten
#define APP_Koonoff 1
#define KoAPP_onoff knx.getGroupObject(1)
//!< Number: 2, Text: LED, Function: Status
#define APP_Kostate 2
#define KoAPP_state knx.getGroupObject(2)

