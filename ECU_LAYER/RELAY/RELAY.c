/* 
 * File:   RELAY.h
 * Author: Alaa
 *
 * Created on March 9, 2024, 6:49 PM
 */

/* Includes section */
#include "RELAY.h"
#include "../../MCAL_LAYER/GPIO/HAL_GPIO.h"


/* Function definitions section */

/**
 * 
 * @param relay
 * @return 
 */

STD_ReturnType relay_initialize(const relay_t * relay){
    
    STD_ReturnType ret = E_OK;

    if (NULL == relay){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin = {
        .PIN       = relay->pin,
        .PORT      = relay->port,
        .direction = OUTPUT,
        .logic     = relay->logic,
        };
        ret = gpio_pin_init(&pin);
        
    }
    return ret;
    
}

/**
 * 
 * @param relay
 * @return 
 */

STD_ReturnType relay_turn_on(const relay_t * relay){
    
    STD_ReturnType ret = E_OK;

    if (NULL == relay){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin = {
        .PIN       = relay->pin,
        .PORT      = relay->port,
        .direction = OUTPUT,
        .logic     = HIGH,
        };
        ret = gpio_pin_logic_write(&pin,HIGH);
        
    }
    return ret;
}

/**
 * 
 * @param relay
 * @return 
 */

STD_ReturnType relay_turn_off(const relay_t * relay){
    
    STD_ReturnType ret = E_OK;

    if (NULL == relay){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin = {
        .PIN       = relay->pin,
        .PORT      = relay->port,
        .direction = OUTPUT,
        .logic     = LOW,
        };
        ret = gpio_pin_logic_write(&pin,LOW);
        
    }
    return ret;
}

/**
 * 
 * @param relay
 * @return 
 */

STD_ReturnType relay_toggle(const relay_t * relay){
    
    STD_ReturnType ret = E_OK;

    if (NULL == relay){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin = {
        .PIN       = relay->pin,
        .PORT      = relay->port,
        .direction = OUTPUT,
        .logic     = LOW,
        };
        ret = gpio_pin_logic_toggle(&pin);
        
    }
    return ret;
}
