/* 
 * File:   timer2.h
 * Author: Alaa
 *
 * Created on May 10, 2024, 10:51 AM
 */

#ifndef TIMER2_H
#define	TIMER2_H




/* Includes section */

#include "timer2_cfg.h"
#include "../GPIO/HAL_GPIO.h"
#include "../interrupts/MCAL_INTERNAL_INTERRUPT.h"

/* Macros section */

#define TIMER2_ENABLED  0x01
#define TIMER2_DISABLED 0x00

/* Marco-like functions section */

#define TIMER2_ENABLE()   T2CONbits.TMR2ON = 0x01
#define TIMER2_DISABLE()  T2CONbits.TMR2ON = 0x00

#define TIMER2_WRITE(value) TMR2 = value    

#define TIMER2_SET_PRESCALER_VALUE(value)  T2CONbits.T2CKPS = value
#define TIMER2_SET_POSTSCALER_VALUE(value) T2CONbits.TOUTPS = value

/* User defined datatype section */

typedef enum{
    
    TIMER2_PRESCALER_FREQ_DIV_1,
    TIMER2_PRESCALER_FREQ_DIV_4,
    TIMER2_PRESCALER_FREQ_DIV_16,

}timer2_prescaler_value_t;

typedef enum{
    
    TIMER2_POSTSCALER_FREQ_DIV_1,
    TIMER2_POSTSCALER_FREQ_DIV_2,
    TIMER2_POSTSCALER_FREQ_DIV_3,
    TIMER2_POSTSCALER_FREQ_DIV_4,
    TIMER2_POSTSCALER_FREQ_DIV_5,
    TIMER2_POSTSCALER_FREQ_DIV_6,
    TIMER2_POSTSCALER_FREQ_DIV_7,
    TIMER2_POSTSCALER_FREQ_DIV_8,
    TIMER2_POSTSCALER_FREQ_DIV_9,
    TIMER2_POSTSCALER_FREQ_DIV_10,
    TIMER2_POSTSCALER_FREQ_DIV_11,
    TIMER2_POSTSCALER_FREQ_DIV_12,
    TIMER2_POSTSCALER_FREQ_DIV_13,
    TIMER2_POSTSCALER_FREQ_DIV_14,
    TIMER2_POSTSCALER_FREQ_DIV_15,
    TIMER2_POSTSCALER_FREQ_DIV_16,

}timer2_postscaler_value_t;

typedef struct{
    
#ifdef TIMER1_INTERRUPT_FEATURE_ENABLE
    void (*Interrupt_Handler)(void);
    
#ifdef PRIORITY_FEATURE_ENABLED
    uint8 priority:  1;
    uint8 reserved:  1;
#endif
#else
    uint8 reserved:  2;
#endif
    uint8 prescaler_value                     :2;
    uint8 postscaler_value                    :4;
    uint8 preloaded_value;
    
}Timer2_t;

/* Function declaration section */

STD_ReturnType Timer2_Init(Timer2_t *timer2);
STD_ReturnType Timer2_Deinit(Timer2_t *timer2);
STD_ReturnType Timer2_Read(Timer2_t *timer2, uint8 *ticks);
STD_ReturnType Timer2_Write(Timer2_t *timer2, uint8 value);




#endif	/* TIMER2_H */

