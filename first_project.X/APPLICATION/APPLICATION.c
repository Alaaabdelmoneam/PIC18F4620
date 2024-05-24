/* 
 * File:   APPLICATION.c
 * Author: Alaa
 *
 * Created on October 29, 2023, 1:59 PM
 */
#include "APPLICATION.h"

/*
 * 
 */

pin_config_t pin1 = {
.PORT  = PORTC_INDEX,
.PIN   = 1,
.logic = HIGH,
.dir   = OUTPUT
};
pin_config_t pin2 = {
.PORT  = PORTC_INDEX,
.PIN   = 2,
.logic = HIGH,
.dir   = OUTPUT
};
pin_config_t pin3 = {
.PORT  = PORTC_INDEX,
.PIN   = 3,
.logic = HIGH,
.dir   = OUTPUT
};
Std_ReturnType ret = E_NOT_OK;

int main() {
    
    ret = gpio_pin_direction_initialize(&pin1);
    ret = 10;
    CLEAR_BIT(&TRISC, 1);
    ret = gpio_pin_direction_initialize(&pin2);
    ret = gpio_pin_direction_initialize(&pin3);
    ret = gpio_pin_direction_initialize(NULL);
    ret = gpio_pin_write_logic(&pin1,LOW);
    ret = gpio_pin_write_logic(&pin2,LOW);
    ret = gpio_pin_write_logic(&pin3,LOW);
    printf("ret = %i\n",ret);
    return (ret);
}

