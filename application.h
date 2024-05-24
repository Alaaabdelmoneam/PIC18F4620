/* 
 * File:   application.h
 * Author: Alaa
 *
 * Created on February 20, 2024, 9:14 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

#ifdef	__cplusplus
extern "C" {
#endif




/* Includes section */
#include "ECU_LAYER/LED/LED.h"
#include "ECU_LAYER/PUSH_BUTTON/PUSH_BTN.h"
#include "ECU_LAYER/RELAY/RELAY.h"
#include "ECU_LAYER/DC_MOTOR_DRIVER/dc_motor.h"
#include "ECU_LAYER/LCD/LCD.h"
#include "ECU_LAYER/KEYPAD/keypad.h"
#include "ECU_LAYER/CHAR_LCD/chr_lcd.h"
#include "MCAL_LAYER/interrupts/MCAL_EXTERNAL_INTERRUPT.h"
#include "MCAL_LAYER/EEPROM/EEPROM.h"
#include "MCAL_LAYER/ADC/adc.h"
#include "MCAL_LAYER/TIMER0/timer.h"
#include "MCAL_LAYER/TIMER1/timer.h"
#include "MCAL_LAYER/TIMER2/timer2.h"
    
/* Macros section */
/* Marco-like functions section */
/* User defined datatype section */
/* Function declaration section */


#ifdef	__cplusplus
}
#endif

#endif	/* APPLICATION_H */

