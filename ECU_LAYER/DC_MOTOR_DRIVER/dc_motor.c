/* 
 * File:   dc_motor.c
 * Author: Alaa
 *
 * Created on March 11, 2024, 1:57 PM
 */

/* Includes section */
#include "dc_motor.h"

/* global variables declaration section*/


/* Function definitions section */



/**
 * 
 * @param motor
 * @return 
 */



STD_ReturnType motor_initialize(const motor_t * motor){
    STD_ReturnType ret = E_OK;

    if (NULL == motor){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t IN0;
        IN0.PORT      = motor->motor_pins[0].port;
        IN0.PIN       = motor->motor_pins[0].pin;
        IN0.logic     = motor->motor_pins[0].logic;
        IN0.direction = OUTPUT;
        pin_config_t IN1;
        IN1.PORT      = motor->motor_pins[1].port;
        IN1.PIN       = motor->motor_pins[1].pin;
        IN1.logic     = motor->motor_pins[1].logic;
        IN1.direction = OUTPUT;
        gpio_pin_init(&IN0);
        gpio_pin_init(&IN1);
    }
    return ret;
}

/**
 * 
 * @param motor
 * @return 
 */

STD_ReturnType motor_turn_left(const motor_t * motor){
    STD_ReturnType ret = E_OK;

    if (NULL == motor){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t IN0;
        IN0.PORT      = motor->motor_pins[0].port;
        IN0.PIN       = motor->motor_pins[0].pin;
        IN0.logic     = motor->motor_pins[0].logic;
        IN0.direction = OUTPUT;
        pin_config_t IN1;
        IN1.PORT      = motor->motor_pins[1].port;
        IN1.PIN       = motor->motor_pins[1].pin;
        IN1.logic     = motor->motor_pins[1].logic;
        IN1.direction = OUTPUT;
        gpio_pin_logic_write(&IN0,HIGH);
        gpio_pin_logic_write(&IN1,LOW);
    }
}

/**
 * 
 * @param motor
 * @return 
 */

STD_ReturnType motor_turn_right(const motor_t * motor){
    STD_ReturnType ret = E_OK;

    if (NULL == motor){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t IN0;
        IN0.PORT      = motor->motor_pins[0].port;
        IN0.PIN       = motor->motor_pins[0].pin;
        IN0.logic     = motor->motor_pins[0].logic;
        IN0.direction = OUTPUT;
        pin_config_t IN1;
        IN1.PORT      = motor->motor_pins[1].port;
        IN1.PIN       = motor->motor_pins[1].pin;
        IN1.logic     = motor->motor_pins[1].logic;
        IN1.direction = OUTPUT;
        gpio_pin_logic_write(&IN0,LOW);
        gpio_pin_logic_write(&IN1,HIGH);
    }
}

/**
 * 
 * @param motor
 * @return 
 */

STD_ReturnType motor_turn_off (const motor_t * motor){
    STD_ReturnType ret = E_OK;

    if (NULL == motor){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t IN0;
        IN0.PORT      = motor->motor_pins[0].port;
        IN0.PIN       = motor->motor_pins[0].pin;
        IN0.logic     = motor->motor_pins[0].logic;
        IN0.direction = OUTPUT;
        pin_config_t IN1;
        IN1.PORT      = motor->motor_pins[1].port;
        IN1.PIN       = motor->motor_pins[1].pin;
        IN1.logic     = motor->motor_pins[1].logic;
        IN1.direction = OUTPUT;
        gpio_pin_logic_write(&IN0,LOW);
        gpio_pin_logic_write(&IN1,LOW);
        
    }
}
