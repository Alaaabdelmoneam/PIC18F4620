/* 
 * File:   timer.h
 * Author: Alaa
 *
 * Created on May 6, 2024, 3:01 PM
 */

#ifndef TIMER0_H
#define	TIMER0_H

/* Includes section */

#include "timer_cfg.h"
#include "../GPIO/HAL_GPIO.h"
#include "../interrupts/MCAL_INTERNAL_INTERRUPT.h"

/* Macros section */

#define ENABLED  0x01
#define DISABLED 0x00

/* Marco-like functions section */


#define TIMER0_ENABLE()                 T0CONbits.TMR0ON  = 1
#define TIMER0_DISABLE()                T0CONbits.TMR0ON  = 0

#define TIMER0_ENABLE_8_bit()           T0CONbits.T08BIT  = 1
#define TIMER0_ENABLE_16_bit()          T0CONbits.T08BIT  = 0

#define TIMER0_ENABLE_COUNTER_MODE()    T0CONbits.T0CS    = 1
#define TIMER0_ENABLE_TIMER_MODE()      T0CONbits.T0CS    = 0

#define TIMER0_COUNTER_FALLING_EDGE()    T0CONbits.T0SE    = 1
#define TIMER0_COUNTER_RISING_EDGE()     T0CONbits.T0SE    = 0

#define PRESCALER_DISABLE()              T0CONbits.PSA    = 1
#define PRESCALER_ENABLE()               T0CONbits.PSA    = 0

#define PRESCALER_DIV_2()                T0CONbits.T0PS   = 0
#define PRESCALER_DIV_4()                T0CONbits.T0PS   = 1
#define PRESCALER_DIV_8()                T0CONbits.T0PS   = 2
#define PRESCALER_DIV_16()               T0CONbits.T0PS   = 3
#define PRESCALER_DIV_32()               T0CONbits.T0PS   = 4
#define PRESCALER_DIV_64()               T0CONbits.T0PS   = 5
#define PRESCALER_DIV_128()              T0CONbits.T0PS   = 6
#define PRESCALER_DIV_256()              T0CONbits.T0PS   = 7



#define PRESCALER_DIV_SET(PRESCALER_FREQ_DIV) T0CONbits.T0PS = PRESCALER_FREQ_DIV

/* User defined datatype section */

typedef enum{
    TIMER0_PRESCALER_FREQ_DIV_2,
    TIMER0_PRESCALER_FREQ_DIV_4,
    TIMER0_PRESCALER_FREQ_DIV_8,
    TIMER0_PRESCALER_FREQ_DIV_16,
    TIMER0_PRESCALER_FREQ_DIV_32,
    TIMER0_PRESCALER_FREQ_DIV_64,
    TIMER0_PRESCALER_FREQ_DIV_128,
    TIMER0_PRESCALER_FREQ_DIV_256,
}timer0_prescaler_value_t;

typedef struct{

#ifdef TIMER0_INTERRUPT_FEATURE_ENABLE
    void (*Interrupt_Handler)(void);
    
#ifdef PRIORITY_FEATURE_ENABLED
    uint8 priority:  1;
#endif
    
#endif
    uint16 preload_value;
    uint8 prescaler_enable     : 1;
    uint8 counter_mode         : 1;
    uint8 timer_8bit_mode      : 1;
    uint8 counter_rising_edge  : 1;
    uint8 prescaler_value      : 3;
    
}timer0_t;

/* Function declaration section */

STD_ReturnType Timer0_Init(timer0_t *timer0);
STD_ReturnType Timer0_Deinit(timer0_t *timer0);
STD_ReturnType Timer0_Read(timer0_t *timer0, uint16 *ticks);
STD_ReturnType Timer0_Write(timer0_t *timer0, uint16 value);
#endif	/* TIMER0_H */

