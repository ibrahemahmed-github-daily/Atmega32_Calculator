#include "../HAL/HAL_initializations.h"

keypad_t KEYPADMATRIX = { 
                    .keypad_ROW_pins[0].port = PORTC_INDEX,
                    .keypad_ROW_pins[0].pin = PIN_5,
                    .keypad_ROW_pins[0].logic = LOW,
                    .keypad_ROW_pins[0].direction = DIR_OUTPUT,
                    .keypad_ROW_pins[1].port = PORTC_INDEX,
                    .keypad_ROW_pins[1].pin = PIN_4,
                    .keypad_ROW_pins[1].logic = LOW,
                    .keypad_ROW_pins[1].direction = DIR_OUTPUT,
                    .keypad_ROW_pins[2].port = PORTC_INDEX,
                    .keypad_ROW_pins[2].pin = PIN_3,
                    .keypad_ROW_pins[2].logic = LOW,
                    .keypad_ROW_pins[2].direction = DIR_OUTPUT,
                    .keypad_ROW_pins[3].port = PORTC_INDEX,
                    .keypad_ROW_pins[3].pin = PIN_2,
                    .keypad_ROW_pins[3].logic = LOW,
                    .keypad_ROW_pins[3].direction = DIR_OUTPUT,
                    .keypad_COL_pins[0].port = PORTD_INDEX,
                    .keypad_COL_pins[0].pin = PIN_7,
                    .keypad_COL_pins[0].logic = LOW,
                    .keypad_COL_pins[0].direction = DIR_INPUT,
                    .keypad_COL_pins[1].port = PORTD_INDEX,
                    .keypad_COL_pins[1].pin = PIN_6,
                    .keypad_COL_pins[1].logic = LOW,
                    .keypad_COL_pins[1].direction = DIR_INPUT,
                    .keypad_COL_pins[2].port = PORTD_INDEX,
                    .keypad_COL_pins[2].pin = PIN_5,
                    .keypad_COL_pins[2].logic = LOW,
                    .keypad_COL_pins[2].direction = DIR_INPUT,
                    .keypad_COL_pins[3].port = PORTD_INDEX,
                    .keypad_COL_pins[3].pin = PIN_3,
                    .keypad_COL_pins[3].logic = LOW,
                    .keypad_COL_pins[3].direction = DIR_INPUT,   
};
LCD_t _4BIT_LCD = {
                    .LCD_EN.direction = DIR_OUTPUT,
                    .LCD_EN.logic = LOW,
                    .LCD_EN.pin = PIN_2,
                    .LCD_EN.port = PORTA_INDEX,
                    .LCD_RS.direction = DIR_OUTPUT,
                    .LCD_RS.logic = LOW,
                    .LCD_RS.pin = PIN_3,
                    .LCD_RS.port = PORTA_INDEX,
                    .LCD_PINS[0].direction = DIR_OUTPUT,
                    .LCD_PINS[0].logic = LOW,
                    .LCD_PINS[0].pin = PIN_0,
                    .LCD_PINS[0].port = PORTB_INDEX,
                    .LCD_PINS[1].direction = DIR_OUTPUT,
                    .LCD_PINS[1].logic = LOW,
                    .LCD_PINS[1].pin = PIN_1,
                    .LCD_PINS[1].port = PORTB_INDEX,
                    .LCD_PINS[2].direction = DIR_OUTPUT,
                    .LCD_PINS[2].logic = LOW,
                    .LCD_PINS[2].pin = PIN_2,
                    .LCD_PINS[2].port = PORTB_INDEX,
                    .LCD_PINS[3].direction = DIR_OUTPUT,
                    .LCD_PINS[3].logic = LOW,
                    .LCD_PINS[3].pin = PIN_4,
                    .LCD_PINS[3].port = PORTB_INDEX,};

void HAL_initializations (void){
    Std_ReturnType ret = E_NOT_OK;    
    ret = keypad_init(&KEYPADMATRIX);
    ret = H_LCD_4BIT_INIT(&_4BIT_LCD);   
}