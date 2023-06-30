/* 
 * File:   DIO_Interface.h
 * Author: chbib
 *
 * Created on June 14, 2023, 6:24 AM
 */

#ifndef DIO_INTERFACE_H
#define	DIO_INTERFACE_H

/* ----------------- Includes -----------------*/
#include "DIO_Privare.h"
#include "../mcal_std_types.h"
/* ----------------- Macro Declarations -----------------*/

/* ----------------- Macro Functions Declarations -----------------*/


/* ----------------- Data Type Declarations -----------------*/
typedef enum {
    PIN_0 = 0,
    PIN_1,
    PIN_2,
    PIN_3,
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7      
}PIN_t;

typedef enum {
    PORTA_INDEX = 0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX
}PORT_INDEX;

typedef enum {
    DIR_INPUT = 0,
    DIR_OUTPUT
    
}DIRECTION_t;

typedef enum {
    LOW = 0,
    HIGH   
}LOGIC_t;

typedef struct {
    PORT_INDEX port :3;
    PIN_t pin :3;
    DIRECTION_t direction :1;
    LOGIC_t logic :1;     
}PINCONFIG_t;


/* ----------------- Software Interfaces Declarations -----------------*/

Std_ReturnType M_DIO_pin_direction_intialize(const PINCONFIG_t *_pin_config);
Std_ReturnType M_DIO_pin_get_direction_status(const PINCONFIG_t *_pin_config, DIRECTION_t *direction_status);
Std_ReturnType M_DIO_pin_write_logic(const PINCONFIG_t *_pin_config, LOGIC_t logic);
Std_ReturnType M_DIO_pin_read_logic(const PINCONFIG_t *_pin_config, LOGIC_t *logic);
Std_ReturnType M_DIO_pin_toggle_logic(const PINCONFIG_t *_pin_config);
Std_ReturnType M_DIO_pin_intialize(const PINCONFIG_t *_pin_config);

#endif	/* DIO_INTERFACE_H */

