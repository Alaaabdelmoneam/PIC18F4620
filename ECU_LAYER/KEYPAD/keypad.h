/* 
 * File:   keypad.h
 * Author: Alaa
 *
 * Created on April 11, 2024, 3:23 PM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H


/* Includes section */
#include "keypad_cfg.h"
#include "../../MCAL_LAYER/GPIO/HAL_GPIO.h"


/* Macros section */

#define KEYPAD_ROWS_NUMBER 4
#define KEYPAD_COLS_NUMBER 4

/* Marco-like functions section */
/* User defined datatype section */

typedef struct {
    pin_config_t rows[4];
    pin_config_t cols[4];
}keypad_t;

/* Function declaration section */

STD_ReturnType keypad_init(const keypad_t *keypad); 
STD_ReturnType keypad_read_value(const keypad_t *keypad, uint8 *value); 

#endif	/* KEYPAD_H */

