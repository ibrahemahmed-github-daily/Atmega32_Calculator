/* 
 * File:   LCD_interface.h
 * Author: chbib
 *
 * Created on June 14, 2023, 12:56 PM
 */

#ifndef LCD_INTERFACE_H
#define	LCD_INTERFACE_H

/* ----------------- Includes -----------------*/
#include "LCD_private.h"
#include "../../MCAL/DIO/DIO_Interface.h"
/* ----------------- Macro Declarations -----------------*/

// Initialization sequence
#define _4BITMODE1        0x33  // Function Set: 8-bit mode
#define _4BITMODE2        0x32  // Function Set: 4-bit mode
#define _4BITMODE3        0x28  // Function Set: 4-bit mode, 2-line display, 5x8 dot font
#define DISPLAYON         0x0C  // Display On/Off Control: Display on, cursor off, cursor blinking off
#define CLR_DISPLAY       0x01  // Clear Display
#define ENTRY_MODE        0x06  // Entry Mode Set: Increment cursor, no display shift
#define RET_HOME          0x02
#define CGRAM_ADDRESS     0x40
#define DDRAM_ADDRESS     0x80

#define _LCD_CURSOR_MOVE_SHIFT_LEFT     0x10
#define _LCD_CURSOR_MOVE_SHIFT_RIGHT    0x14
#define _LCD_DISPLAY_SHIFT_LEFT         0x18
#define _LCD_DISPLAY_SHIFT_RIGHT        0x1C

#define _LCD_8BIT_MODE_2_LINE           0x38 
#define _LCD_4BIT_MODE_2_LINE           0x28
#define _LCD_CLEAR                      0X01
#define _LCD_RETURN_HOME                0x02
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF   0x06
#define _LCD_DISPLAY_ON                 0x0C



#define ROW1 1
#define ROW2 2
#define ROW3 3
#define ROW4 4

/* ----------------- Macro Functions Declarations -----------------*/

/* ----------------- Data Type Declarations -----------------*/
typedef struct {
    PINCONFIG_t LCD_RS ;
    PINCONFIG_t LCD_EN ;
    PINCONFIG_t LCD_PINS[4];
}LCD_t;
/* ----------------- Software Interfaces Declarations -----------------*/
Std_ReturnType H_LCD_4BIT_INIT(const LCD_t * lcd);
Std_ReturnType H_LCD_4BIT_SEND_COMM(const LCD_t * lcd , uint8 command);
Std_ReturnType H_LCD_4BIT_SEND_DATA(const LCD_t * lcd , uint8 data);
Std_ReturnType H_LCD_4BIT_SEND_STRING(const LCD_t * lcd , const uint8 *str);
Std_ReturnType H_LCD_4BIT_SEND_DATA_POS(const LCD_t * lcd, uint8 row ,uint8 col, uint8 data);
Std_ReturnType H_LCD_4BIT_SEND_STRING_POS(const LCD_t * lcd, const uint8 *str, uint8 row ,uint8 col);
Std_ReturnType H_LCD_4BIT_SENT_CUSTOM_CHAR(const LCD_t *lcd, uint8 row, uint8 col, const uint8 chr[], uint8 mem_pos);
Std_ReturnType H_LCD_4BIT_SEND_NUMBER(const LCD_t * lcd,sint32 Number);
Std_ReturnType H_LCD_4BIT_SEND_NUMBER_POS(const LCD_t *lcd, uint16 Number,uint8 row , uint8 col);
Std_ReturnType H_LCD_4BIT_SEND_FLOAT(const LCD_t *lcd, float Number);
Std_ReturnType H_LCD_4BIT_SEND_FNUMBER_POS(const LCD_t *lcd, float Number,uint8 row , uint8 col);
Std_ReturnType convert_uint8_to_string(uint8 value, uint8 *str);



#endif	/* LCD_INTERFACE_H */

