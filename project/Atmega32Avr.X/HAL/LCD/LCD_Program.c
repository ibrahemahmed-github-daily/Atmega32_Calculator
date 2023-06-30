#include "LCD_interface.h"
static Std_ReturnType H_LCD_4BIT_SET_CURSOR(const LCD_t * lcd, uint8 row ,uint8 col);
static Std_ReturnType H_LCD_4BIT_ENABLE(const LCD_t * lcd);
static Std_ReturnType H_LCD_4BIT_SENDING(const LCD_t * lcd , uint8 command);

/**
 * 
 * @param lcd
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */


Std_ReturnType H_LCD_4BIT_INIT(const LCD_t * lcd){
    Std_ReturnType ret = E_OK;
    if (NULL == lcd){
        ret = E_NOT_OK;
    }
    else {
        ret = M_DIO_pin_intialize(&(lcd->LCD_RS));
        ret = M_DIO_pin_intialize(&(lcd->LCD_EN));
        for (uint8 init_counter = ZERO_INIT ; init_counter < 4 ; init_counter++ ){
            ret = M_DIO_pin_intialize(&(lcd->LCD_PINS[init_counter]));
        }
        _delay_ms(150);
        ret = H_LCD_4BIT_SEND_COMM(lcd,_4BITMODE1);
        _delay_ms(20);
        ret = H_LCD_4BIT_SEND_COMM(lcd,_4BITMODE2);
        _delay_ms(20);
        ret = H_LCD_4BIT_SEND_COMM(lcd,_4BITMODE3);
        _delay_ms(20);
        ret = H_LCD_4BIT_SEND_COMM(lcd,DISPLAYON);
        _delay_ms(20);
        ret = H_LCD_4BIT_SEND_COMM(lcd,CLR_DISPLAY);
        _delay_ms(20);
        ret = H_LCD_4BIT_SEND_COMM(lcd,RET_HOME);
        _delay_ms(20);
        ret = H_LCD_4BIT_SEND_COMM(lcd,ENTRY_MODE);
        _delay_ms(20);
        ret = H_LCD_4BIT_SEND_COMM(lcd,DDRAM_ADDRESS);
        _delay_ms(20);
    }
    return ret ; 
}

/*
Std_ReturnType H_LCD_4BIT_INIT(const LCD_t * lcd){
    Std_ReturnType ret = E_OK;
    if (NULL == lcd){
        ret = E_NOT_OK;
    }
    else {
        ret = M_DIO_pin_intialize(&(lcd->LCD_RS));
        ret = M_DIO_pin_intialize(&(lcd->LCD_EN));
        for(uint8 l_data_pins_counter=ZERO_INIT; l_data_pins_counter<4; l_data_pins_counter++){
            ret = M_DIO_pin_intialize(&(lcd->LCD_PINS[l_data_pins_counter]));
        }
        _delay_ms(20);
        ret = H_LCD_4BIT_SEND_COMM(lcd, _LCD_8BIT_MODE_2_LINE);
        _delay_ms(5);
        ret = H_LCD_4BIT_SEND_COMM(lcd, _LCD_8BIT_MODE_2_LINE);
        _delay_us(150);
        ret = H_LCD_4BIT_SEND_COMM(lcd, _LCD_8BIT_MODE_2_LINE);
        
        ret = H_LCD_4BIT_SEND_COMM(lcd, _LCD_CLEAR);
        ret = H_LCD_4BIT_SEND_COMM(lcd, _LCD_RETURN_HOME);
        ret = H_LCD_4BIT_SEND_COMM(lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
        ret = H_LCD_4BIT_SEND_COMM(lcd, _LCD_DISPLAY_ON);
        ret = H_LCD_4BIT_SEND_COMM(lcd, _LCD_4BIT_MODE_2_LINE);
        ret = H_LCD_4BIT_SEND_COMM(lcd, 0x80);
    }
    return ret ;
}
*/


/**
 * 
 * @param lcd
 * @param command
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType H_LCD_4BIT_SEND_COMM(const LCD_t * lcd , uint8 command){
    Std_ReturnType ret = E_OK;
    if (NULL == lcd){
        ret = E_NOT_OK;
    }
    else {
        ret = M_DIO_pin_write_logic(&(lcd->LCD_RS),LOW);
        ret = H_LCD_4BIT_SENDING(lcd , command >> 4);
        ret = H_LCD_4BIT_ENABLE(lcd);
        ret = H_LCD_4BIT_SENDING(lcd , command);
        ret = H_LCD_4BIT_ENABLE(lcd);
        
    }
    return ret ;
    
}
/**
 * 
 * @param lcd Pointer to the LCD configurations
 * @param data The data that we need to send to the LCD
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType H_LCD_4BIT_SEND_DATA(const LCD_t * lcd , uint8 data){
    Std_ReturnType ret = E_OK;
    if (NULL == lcd){
        ret = E_NOT_OK;
    }
    else {
        ret = M_DIO_pin_write_logic(&(lcd->LCD_RS),HIGH);
        ret = H_LCD_4BIT_SENDING(lcd , data>>4);
        ret = H_LCD_4BIT_ENABLE(lcd);
        ret = H_LCD_4BIT_SENDING(lcd , data);
        ret = H_LCD_4BIT_ENABLE(lcd);
    }
    return ret ;
    
}

/**
 * 
 * @param lcd
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType H_LCD_4BIT_SEND_STRING(const LCD_t * lcd ,const uint8 *str){
    Std_ReturnType ret = E_OK;
    if (NULL == lcd){
        ret = E_NOT_OK;
    }
    else {
        for (uint32 string_counter = 0 ; str[string_counter] != '\0' ; string_counter++ ){
                ret = H_LCD_4BIT_SEND_DATA (lcd , str[string_counter]);
        }
    }
    return ret ;
    
}
/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param data
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType H_LCD_4BIT_SEND_DATA_POS(const LCD_t * lcd, uint8 row ,uint8 col, uint8 data){
    Std_ReturnType ret = E_OK;
    if (NULL == lcd){
        ret = E_NOT_OK;
    }
    else {
        ret = H_LCD_4BIT_SET_CURSOR(lcd , row , col);
        ret = H_LCD_4BIT_SEND_DATA(lcd, data);
    }
    return ret ;
    
}

/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType H_LCD_4BIT_SEND_STRING_POS(const LCD_t * lcd,const uint8 *str, uint8 row ,uint8 col){
    Std_ReturnType ret = E_OK;
    if (NULL == lcd){
        ret = E_NOT_OK;
    }
    else {
        ret = H_LCD_4BIT_SET_CURSOR(lcd, row, col);
       
        for (int string_counter = 0 ; str[string_counter] != '\0' ; string_counter++ ){
                ret = H_LCD_4BIT_SEND_DATA(lcd , str[string_counter]);
        }
        
    }
    return ret ;
    
}

/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param _chr
 * @param mem_pos
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType H_LCD_4BIT_SENT_CUSTOM_CHAR(const LCD_t *lcd, uint8 row, uint8 col, const uint8 chr[], uint8 mem_pos){
    Std_ReturnType ret = E_OK;
    if (NULL == lcd){
        ret = E_NOT_OK;
    }
    else {
        ret = H_LCD_4BIT_SEND_COMM(lcd, (CGRAM_ADDRESS |(mem_pos*8)));
        for (uint32 data_counter = ZERO_INIT ; data_counter < 8 ;data_counter++){
            ret = H_LCD_4BIT_SEND_DATA(lcd ,chr[data_counter]);
        }
        ret = H_LCD_4BIT_SEND_DATA_POS(lcd,row,col,mem_pos);
        
    }
    return ret ;
    
}


/**
 * 
 * @param lcd
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static Std_ReturnType H_LCD_4BIT_ENABLE(const LCD_t * lcd){
    Std_ReturnType ret = E_OK;
    if (NULL == lcd){
        ret = E_NOT_OK;
    }
    else {
        ret = M_DIO_pin_write_logic(&(lcd->LCD_EN),HIGH);
        _delay_ms(5);
        ret = M_DIO_pin_write_logic(&(lcd->LCD_EN),LOW);
    }
    return ret ;
}

/**
 * 
 * @param lcd
 * @param _data_command
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static Std_ReturnType H_LCD_4BIT_SENDING(const LCD_t * lcd , uint8 data_command){
    Std_ReturnType ret = E_OK;
    if (NULL == lcd){
        ret = E_NOT_OK;
    }
    else {
        ret = M_DIO_pin_write_logic(&(lcd->LCD_PINS[0]), (data_command>>0)&(uint8)0x01);
        ret = M_DIO_pin_write_logic(&(lcd->LCD_PINS[1]), (data_command>>1)&(uint8)0x01);
        ret = M_DIO_pin_write_logic(&(lcd->LCD_PINS[2]), (data_command>>2)&(uint8)0x01);
        ret = M_DIO_pin_write_logic(&(lcd->LCD_PINS[3]), (data_command>>3)&(uint8)0x01);
        
    }
    return ret ;
    
}

/**
 * 
 * @param lcd
 * @param row
 * @param coulmn
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static Std_ReturnType H_LCD_4BIT_SET_CURSOR(const LCD_t * lcd, uint8 row ,uint8 col){
    Std_ReturnType ret = E_OK;
    
    if (NULL == lcd){
        ret = E_NOT_OK;
    }
    else {
    // Calculate the row address based on the given row number
    col--;
    switch(row){
        case ROW1 : ret = H_LCD_4BIT_SEND_COMM(lcd, (0x80 + col)); break; /* 0x00 -> Decimal : 0  */
        case ROW2 : ret = H_LCD_4BIT_SEND_COMM(lcd, (0xC0+ col)); break; /* 0x40 -> Decimal : 64 */
        case ROW3 : ret = H_LCD_4BIT_SEND_COMM(lcd, (0x94 + col)); break; /* 0x14 -> Decimal : 20 */
        case ROW4 : ret = H_LCD_4BIT_SEND_COMM(lcd, (0xD4 + col)); break; /* 0x54 -> Decimal : 84 */
        default : ;
            return;
    } }


    
    return ret;

}

/**
 * 
 * @param value
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType convert_uint8_to_string(uint8 value, uint8 *str) {
    Std_ReturnType ret = E_OK;
    if (NULL == str) {
        ret = E_NOT_OK;
    } else {
        memset((char *) str, '\0', 4);
        sprintf(str, "%i", value);
    }
    return ret;
}

Std_ReturnType H_LCD_4BIT_SEND_NUMBER(const LCD_t *lcd, sint32 Number) {
    Std_ReturnType ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        sint8 l_Counter = 0;
        uint8 l_Arr[10] = {0};
        if (Number < 0) {
            Number = Number * -1;
            H_LCD_4BIT_SEND_DATA(lcd, '-');
        }
        do {
            l_Arr[l_Counter] = Number % 10;
            Number = Number / 10;
            l_Counter++;
        } while (Number != 0);

        while (l_Counter > 0) {
            H_LCD_4BIT_SEND_DATA(lcd, l_Arr[--l_Counter] + 48);
        }

    }
    return ret;
}


Std_ReturnType H_LCD_4BIT_SEND_FLOAT(const LCD_t *lcd, float Number) {
    Std_ReturnType ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        // Check if the number is negative
        if (Number < 0.0) {
            Number = -Number;  // Convert to positive
            H_LCD_4BIT_SEND_DATA(lcd, '-');  // Display the minus sign
        }

        // Display the integer part
        sint32 integerPart = (sint32)Number;
        H_LCD_4BIT_SEND_NUMBER(lcd, integerPart);

        // Display the decimal part
        uint8 decimalPlaces = 2;  // Specify the desired number of decimal places
        float decimalPart = Number - (float)integerPart;  // Extract the decimal part
        if (decimalPart > 0.0 && decimalPlaces > 0) {
            H_LCD_4BIT_SEND_DATA(lcd, '.');  // Display the decimal point

            // Multiply the decimal part by a power of 10 to extract the desired number of decimal places
            for (uint8 i = 0; i < decimalPlaces; i++) {
                decimalPart *= 10.0;
                sint32 digit = (sint32)decimalPart;
                H_LCD_4BIT_SEND_DATA(lcd, digit + '0');  // Display each decimal digit
                decimalPart -= (float)digit;
            }
        }
    }
    return ret;
}


Std_ReturnType H_LCD_4BIT_SEND_FNUMBER_POS(const LCD_t *lcd, float Number,uint8 row , uint8 col) {
    Std_ReturnType ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        ret = H_LCD_4BIT_SET_CURSOR(lcd,row,col);
        ret = H_LCD_4BIT_SEND_FLOAT(lcd,Number);
        
    }
    return ret;
}
Std_ReturnType H_LCD_4BIT_SEND_NUMBER_POS(const LCD_t *lcd, uint16 Number,uint8 row , uint8 col) {
    Std_ReturnType ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        ret = H_LCD_4BIT_SET_CURSOR(lcd,row,col);
        ret = H_LCD_4BIT_SEND_NUMBER(lcd,Number);
        
    }
    return ret;
}