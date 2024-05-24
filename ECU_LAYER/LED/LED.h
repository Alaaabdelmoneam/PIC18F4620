/* 
 * File:   LED.h
 * Author: Alaa
 *
 * Created on February 20, 2024, 5:07 PM
 */

#ifndef LED_H
#define	LED_H

#ifdef	__cplusplus
extern "C" {
#endif


/* Includes section */
#include "LED_CFG.h"
#include "../../MCAL_LAYER/GPIO/HAL_GPIO.h"
/* Macros section */
/* Marco-like functions section */
/* User defined datatype section */
    
typedef enum{
    LED_OFF,
    LED_ON
}led_status_t;

typedef struct{
    uint8 PORT    :3;
    uint8 PIN     :3;
    uint8 state   :1;
    uint8 reserved:1;
}led_t;
    
/* Function declaration section */
STD_ReturnType led_initialize(const led_t * led);
STD_ReturnType led_turn_on(const led_t * led);
STD_ReturnType led_turn_off(const led_t * led);
STD_ReturnType led_toggle(const led_t * led);


#ifdef	__cplusplus
}
#endif

#endif	/* LED_H */

