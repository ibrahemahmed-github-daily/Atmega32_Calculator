/* 
 * File:   keypad_interface.h
 * Author: chbib
 *
 * Created on June 14, 2023, 9:10 AM
 */

#ifndef KEYPAD_INTERFACE_H
#define	KEYPAD_INTERFACE_H


/* ----------------- Includes -----------------*/
#include "keypad_private.h"
#include "../../MCAL/DIO/DIO_Interface.h"
/* ----------------- Macro Declarations -----------------*/
#define KEYPAD_ROWS 4
#define KEYPAD_COLS 4
/* ----------------- Macro Functions Declarations -----------------*/
  
/* ----------------- Data Type Declarations -----------------*/
typedef struct {
    PINCONFIG_t keypad_ROW_pins[KEYPAD_ROWS];
    PINCONFIG_t keypad_COL_pins[KEYPAD_COLS];
}keypad_t;
/* ----------------- Software Interfaces Declarations -----------------*/
Std_ReturnType keypad_init (const keypad_t * _keypad);
Std_ReturnType keypad_read_value (const keypad_t * _keypad);

#endif	/* KEYPAD_INTERFACE_H */

