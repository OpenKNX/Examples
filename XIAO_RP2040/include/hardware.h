//--------------------Allgemein---------------------------
#define MAIN_OpenKnxId 0xAF
#define MAIN_ApplicationNumber 0xAF00
#define MAIN_ApplicationVersion 0x11
#define MAIN_OrderNumber "TA-00002.1" //may not work with multiple devices on same hardware or app on different hardware

// Offset: 0, Size: 2 Bit, Text: Farbe
#define PARAM_color		0x0000
#define PARAM_color_Mask	0x00C0
#define PARAM_color_Shift	6
// Offset: 0, BitOffset: 2, Size: 1 Bit, Text: Blinken?
#define PARAM_blink		0x0000
#define PARAM_blink_Mask	0x0020
#define PARAM_blink_Shift	5
// Offset: 1, Size: 8 Bit (1 Byte), Text: Interval
#define PARAM_interval		0x0001
#define COMOBJ_onoff 	0	//!< Number: 0, Text: LED, Function: Schalten
#define COMOBJ_state 	1	//!< Number: 1, Text: LED, Function: Status