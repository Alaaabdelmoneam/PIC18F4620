/* 
 * File:   LCD.h
 * Author: Alaa
 *
 * Created on March 20, 2024, 5:19 PM
 */
#include "../../MCAL_LAYER/GPIO/HAL_GPIO.h"
#include "LCD.h"

/**
 * 
 * @param lcd
 * @return 
 */

STD_ReturnType lcd_init(lcd_t* lcd){
    
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        gpio_pin_init(&(lcd->lcd_pins[SEG_PIN_0]));
        gpio_pin_init(&(lcd->lcd_pins[SEG_PIN_1]));
        gpio_pin_init(&(lcd->lcd_pins[SEG_PIN_2]));
        gpio_pin_init(&(lcd->lcd_pins[SEG_PIN_3]));

        ret = E_OK;
    }
    return ret;
    
}

/**
 * 
 * @param lcd
 * @param number
 * @return 
 */
STD_ReturnType lcd_write(lcd_t* lcd, char number){
    
    
}
