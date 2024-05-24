/* 
 * File:   RELAY.h
 * Author: Alaa
 *
 * Created on March 9, 2024, 6:49 PM
 */

#ifndef RELAY_H
#define	RELAY_H

/* Includes section */
#include "RELAY_CFG.h"
#include "../../MCAL_LAYER/GPIO/HAL_GPIO.h"
/* User defined datatype section */

typedef enum{
    RELAY_OFF,
    RELAY_ON
}relay_state_t;

typedef struct {
    uint8 port     :3;
    uint8 pin      :3;
    uint8 logic    :1;
    uint8 reserved :1;
}relay_t;


/* Function declaration section */

STD_ReturnType relay_initialize(const relay_t * relay);
STD_ReturnType relay_turn_on(const relay_t * relay);
STD_ReturnType relay_turn_off(const relay_t * relay);
STD_ReturnType relay_toggle(const relay_t * relay);

#endif	/* RELAY_H */

