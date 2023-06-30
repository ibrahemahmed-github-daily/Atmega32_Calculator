#include "DIO_Interface.h"

volatile uint8 *DDR_REG [4] = {&DDRA,&DDRB,&DDRC,&DDRD};
volatile uint8 *PORT_REG[4] = {&PORTA,&PORTB,&PORTC,&PORTD};
volatile uint8 *PIN_REG [4] = {&PINA,&PINB,&PINC,&PIND};

Std_ReturnType M_DIO_pin_direction_intialize(const PINCONFIG_t *_pin_config){
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config ){
       Std_ReturnType ret = E_NOT_OK; 
    }
    else {
        switch(_pin_config->direction){
            case DIR_INPUT :
               CLEAR_BIT(*DDR_REG[_pin_config->port],_pin_config->pin);
               break;
            case DIR_OUTPUT :
                SET_BIT(*DDR_REG[_pin_config->port],_pin_config->pin);
                break;      
        }
    }
    return ret ;
}
Std_ReturnType M_DIO_pin_get_direction_status(const PINCONFIG_t *_pin_config, DIRECTION_t *direction_status){
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config || NULL == direction_status){
       Std_ReturnType ret = E_NOT_OK; 
    }
    else {
        
        *direction_status = READ_BIT(*DDR_REG[_pin_config->port],_pin_config->pin);
                     
        }
    
    return ret ;   
}
Std_ReturnType M_DIO_pin_write_logic(const PINCONFIG_t *_pin_config, LOGIC_t logic){
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config){
       Std_ReturnType ret = E_NOT_OK; 
    }
    else {
        
         switch(logic){
            case LOW :
               CLEAR_BIT(*PORT_REG[_pin_config->port],_pin_config->pin);
               break;
            case HIGH :
                SET_BIT(*PORT_REG[_pin_config->port],_pin_config->pin);
                break;      
        }
                     
        }
    
    return ret ; 
    
}
Std_ReturnType M_DIO_pin_read_logic(const PINCONFIG_t *_pin_config, LOGIC_t *logic) {
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config || NULL == logic) {
        ret = E_NOT_OK;
    } 
    else {
        *logic = READ_BIT(*PIN_REG[_pin_config->port], _pin_config->pin);
    }
    return ret;
}

Std_ReturnType M_DIO_pin_toggle_logic(const PINCONFIG_t *_pin_config){
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config){
       Std_ReturnType ret = E_NOT_OK; 
    }
    else {
        
        TOGGLE_BIT(*PORT_REG[_pin_config->port],_pin_config->pin);
                     
        }
 return ret ;   
}
Std_ReturnType M_DIO_pin_intialize(const PINCONFIG_t *_pin_config){
    Std_ReturnType ret = E_OK;
    if (NULL == _pin_config){
       Std_ReturnType ret = E_NOT_OK; 
    }
    else {
    ret = M_DIO_pin_direction_intialize (_pin_config);
    ret = M_DIO_pin_write_logic (_pin_config , _pin_config->logic);
    }
    return ret ;
}