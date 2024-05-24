/* 
 * File:   LED.c
 * Author: Alaa
 *
 * Created on February 20, 2024, 5:04 PM
 */
#include "LED.h"
/**
 * 
 * @param led
 * @return 
 */
STD_ReturnType led_initialize(const led_t * led){
    STD_ReturnType ret = E_OK;

    if (NULL == led){
        ret = E_NOT_OK;
    }
    else{
        
        pin_config_t pin = {
        .PIN       = led->PIN,
        .PORT      = led->PORT,
        .direction = OUTPUT,
        .logic     = led->state,
        };
        ret = gpio_pin_init(&pin);
        
    }
    return ret;
}

/**
 * 
 * @param led
 * @return 
 */
STD_ReturnType led_turn_on(const led_t * led){
    STD_ReturnType ret = E_OK;

    
    if (NULL == led){
        ret = E_NOT_OK;
    }
    else{

        pin_config_t pin = {
        .PIN       = led->PIN,
        .PORT      = led->PORT,
        .direction = OUTPUT,
        .logic     = HIGH,
        };
        ret = gpio_pin_logic_write(&pin,HIGH);

    }
    return ret;
}

/**
 * 
 * @param led
 * @return 
 */
STD_ReturnType led_turn_off(const led_t * led){
    STD_ReturnType ret = E_OK;
    if (NULL == led){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin = {
        .PIN       = led->PIN,
        .PORT      = led->PORT,
        .direction = OUTPUT,
        .logic     = LOW,
        };
        ret = gpio_pin_logic_write(&pin,LOW);
    }
    return ret;
}

/**
 * 
 * @param led
 * @return 
 */

STD_ReturnType led_toggle(const led_t * led){
    STD_ReturnType ret = E_OK;
    if (NULL == led){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin = {
        .PIN       = led->PIN,
        .PORT      = led->PORT,
        .direction = OUTPUT,
        .logic     = led->state,
        };
        ret = gpio_pin_logic_toggle(&pin);
    }
    return ret;
}