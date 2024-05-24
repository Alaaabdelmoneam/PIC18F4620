/* 
 * File:   HAL_GPIO.C
 * Author: Alaa
 *
 * Created on October 29, 2023, 1:32 PM
 */

/* Includes */
#include "HAL_GPIO.h"

/* Global variables declaration */

volatile uint8 *TRIS[] = {&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
volatile uint8 *PORT[] = {&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};
volatile uint8 *LAT[]  = {&LATA,&LATB,&LATC,&LATD,&LATE};

Std_ReturnType gpio_pin_direction_initialize(const pin_config_t *_pin_config){
    
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == _pin_config || ((_pin_config->PORT) > (MAX_PORT_NUMBER - 1)) || ((_pin_config->PIN) > (5)) ){
        ret = E_NOT_OK;
    }
    else {
        ret = E_OK;
        switch(_pin_config->dir)
        {
            case OUTPUT : 
                CLEAR_BIT(TRIS[_pin_config->PORT],_pin_config->PIN);
                break;
            case INPUT : 
                SET_BIT(TRIS[_pin_config->PORT],_pin_config->PIN);
                break;
            default:
                break;
        }
    }    
    
    return ret;

}

Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config, direction_t *direction_status){
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == _pin_config || NULL == direction_status || _pin_config->PORT > MAX_PORT_NUMBER || _pin_config->PIN > MAX_PIN_NUMBER ){
        ret = E_NOT_OK;
    }
    
    
    return ret;
}
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config, logic_t logic){
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == _pin_config || _pin_config->PORT > MAX_PORT_NUMBER || _pin_config->PIN > MAX_PIN_NUMBER ){
        ret = E_NOT_OK;
    }
    else {
        ret = E_OK;
        switch(_pin_config->logic)
        {
            case LOW : 
                CLEAR_BIT(LAT[_pin_config->PORT],_pin_config->PIN);
                break;
            case HIGH : 
                SET_BIT(LAT[_pin_config->PORT],_pin_config->PIN);
                break;
            default:
                break;
        }
    }    
    
    return ret;
}
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config, logic_t *logic){
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == _pin_config || NULL == logic || _pin_config->PORT > MAX_PORT_NUMBER || _pin_config->PIN > MAX_PIN_NUMBER ){
        ret = E_NOT_OK;
    }
    
    
    return ret;
}
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config){
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == _pin_config || _pin_config->PORT > MAX_PORT_NUMBER || _pin_config->PIN > MAX_PIN_NUMBER ){
        ret = E_NOT_OK;
    }

    
    
    return ret;
}


Std_ReturnType gpio_port_direction_initialize(const port_index_t port, uint8 direction){
    Std_ReturnType ret = E_NOT_OK;


    
    
    return ret;
}
Std_ReturnType gpio_port_get_direction_status(const port_index_t port, uint8 *direction_status){
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == direction_status){
        ret = E_NOT_OK;
    }
    else
    {
        *direction_status = READ_BIT()
    }
    
    
    return ret;
}
Std_ReturnType gpio_port_write_logic(const port_index_t port, uint8 logic){
    Std_ReturnType ret = E_NOT_OK;

    
    
    return ret;
}
Std_ReturnType gpio_port_read_logic(const port_index_t port, uint8 *logic){
    Std_ReturnType ret = E_NOT_OK;
    if ( NULL == logic ){
        ret = E_NOT_OK;
    }

    
    
    return ret;
}
Std_ReturnType gpio_port_toggle_logic(const port_index_t port){
    Std_ReturnType ret = E_NOT_OK;

    return ret;
}
