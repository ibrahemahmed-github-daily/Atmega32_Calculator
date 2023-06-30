#include "keypad_interface.h"




static const uint8 KeyPadMatrix[KEYPAD_ROWS][KEYPAD_COLS] = {{7, 8, 9, '/'},
                                                             {4, 5, 6, '*'},
                                                             {1, 2, 3, '-'},
                                                             {'C',0, '=', '+'}};

Std_ReturnType keypad_init(const keypad_t * _keypad) {
    Std_ReturnType ret = E_OK;
    uint8 row_counter = ZERO_INIT, col_counter = ZERO_INIT;
    if (NULL == _keypad) {
        ret = E_NOT_OK;
    } else {
        for (row_counter = ZERO_INIT; row_counter < KEYPAD_ROWS; row_counter++) {
            ret = M_DIO_pin_intialize(&(_keypad->keypad_ROW_pins[row_counter]));
        }
        for (col_counter = ZERO_INIT; col_counter < KEYPAD_COLS; col_counter++) {
            ret = M_DIO_pin_direction_intialize(&(_keypad->keypad_COL_pins[col_counter]));
        }
        return ret;
    }
}

uint8 keypad_read_value(const keypad_t * _keypad) {
    Std_ReturnType ret = E_OK;
    uint8 value = 'A';
    uint8 row_counter = ZERO_INIT, counter = ZERO_INIT, col_counter = ZERO_INIT ;
    uint8 ColValue = ZERO_INIT;
    if (NULL == _keypad) {
        ret = E_NOT_OK;
    } else {
        for (row_counter = ZERO_INIT; row_counter < KEYPAD_ROWS; row_counter++) {
            for (counter = ZERO_INIT; counter < KEYPAD_ROWS; counter++) {
                ret = M_DIO_pin_write_logic(&(_keypad->keypad_ROW_pins[counter]), HIGH);
            }
            ret = M_DIO_pin_write_logic(&(_keypad->keypad_ROW_pins[row_counter]), LOW);
            _delay_ms(20);
            for (col_counter = ZERO_INIT; col_counter < KEYPAD_COLS; col_counter++) {
                ret = M_DIO_pin_read_logic(&(_keypad->keypad_COL_pins[col_counter]),&ColValue);
                if (ColValue == LOW){
                    value = KeyPadMatrix[row_counter][col_counter];
                }
            }
        }
    }
    return value;
}