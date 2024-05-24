/* 
 * File:   PUSH_BTN.h
 * Author: Alaa
 *
 * Created on March 8, 2024, 10:07 AM
 */

#ifndef PUSH_BTN_H
#define	PUSH_BTN_H




/* Includes section */
#include "../../MCAL_LAYER/GPIO/HAL_GPIO.h"
#include "PUSH_BUTTON_CFG.h"
//#include "PUSH_BTN.h"
/* Macros section */
/* Marco-like functions section */
/* User defined datatype section */
typedef enum{
    NOT_PRESSED,
    PRESSED
}button_state_t;

typedef enum{
    ACTIVE_LOW,
    ACTIVE_HIGH
}active_t;

typedef struct {
    pin_config_t pin;
    button_state_t btn_state;
    active_t btn_active;
}btn_t;

/* Function declaration section */

STD_ReturnType btn_init(const btn_t* btn);
STD_ReturnType btn_read(const btn_t* btn, button_state_t* btn_state);



#endif	/* PUSH_BTN_H */

