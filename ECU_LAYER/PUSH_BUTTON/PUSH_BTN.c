/* 
 * File:   PUSH_BTN.c
 * Author: Alaa
 *
 * Created on March 8, 2024, 10:07 AM
 */


/* Includes section */
#include "PUSH_BTN.h"
#include "../../MCAL_LAYER/GPIO/HAL_GPIO.h"    
/* Macros section */
/* Marco-like functions section */
/* User defined datatype section */

/* Function definitions section */

/**
 * 
 * @param btn
 * @return 
 */
STD_ReturnType btn_init(const btn_t* btn){
    STD_ReturnType ret = E_OK;
    if (NULL == btn){
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_direction_init(&(btn->pin));
        
    }
    return ret;
}

/**
 * 
 * @param btn
 * @param btn_state
 * @return 
 */
STD_ReturnType btn_read(const btn_t* btn, button_state_t* btn_state){
    STD_ReturnType ret = E_OK;
    logic_t btn_logic = LOW;
    if (NULL == btn || NULL == btn_state){
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_logic_read(&(btn->pin),&btn_logic);
        if (ret == E_OK){
            if (((btn->btn_active == ACTIVE_HIGH && btn_logic == HIGH ) || (btn->btn_active == ACTIVE_LOW && btn_logic == LOW ))){
            *btn_state = PRESSED;
            }
            else{
                *btn_state = NOT_PRESSED;
            }    
        }
        else{
            ret = E_NOT_OK;
        }
    }
    return ret;   
}
