/* 
 * File:   timer3.h
 * Author: Alaa
 *
 * Created on May 10, 2024, 1:09 PM
 */

#ifndef TIMER3_H
#define	TIMER3_H

/* Includes section */

#include "timer3_cfg.h"
#include "../GPIO/HAL_GPIO.h"
#include "../interrupts/MCAL_INTERNAL_INTERRUPT.h"

/* Macros section */

#define TIMER3_READ_WRITE_16_BIT 0x01
#define TIMER3_READ_WRITE_8_BIT  0x00

#define TIMER3_CCP1_CCP2          0x10 
#define TIMER1_CCP1_TIMER3_CCP2   0x01 
#define TIMER1_CCP1_CCP2          0x00 


#define TIMER3_COUNTER_MODE_SYNCHRONIZED   0x00
#define TIMER3_COUNTER_MODE_UNSYNCHRONIZED 0x01

#define TIMER3_TIMER_MODE_ENABLED     0x00
#define TIMER3_COUNTER_MODE_ENABLED   0x01

#define TIMER3_ENABLED  0x01
#define TIMER3_DISABLED 0x00

/* Marco-like functions section */

#define TIMER3_SET_PRESCALER_VALUE(value) T3CONbits.T3CKPS = value

#define TIMER3_ENABLE_16_BIT_MODE()    T3CONbits.RD16 = 0x01
#define TIMER3_ENABLE_8_BIT_MODE()     T3CONbits.RD16 = 0x00

#define TIMER3_COUNTER_MODE_ENABLE_SYNCHRONIZATION()  T3CONbits.T3SYNC = 0x00
#define TIMER3_COUNTER_MODE_DISABLE_SYNCHRONIZATION() T3CONbits.T3SYNC = 0x01

#define TIMER3_ENABLE_CLK_CCP1_CCP2()   T3CONbits.T3CCP2 = 1

#define TIMER1_ENABLE_CLK_CCP1_CCP2()  {\
                                        T3CONbits.T3CCP2 = 0;\
                                        T3CONbits.T3CCP1 = 0;\
                                       }

#define TIMER1_ENABLE_CLK_CCP1_TIMER3_ENABLE_CLK_CCP2(){\
                                                        T3CONbits.T3CCP2 = 0;\
                                                        T3CONbits.T3CCP1 = 1;\
                                                       }

#define TIMER3_COUNTER_MODE_ENABLE()  T3CONbits.TMR3CS = 0x01
#define TIMER3_TIMER_MODE_ENABLE()    T3CONbits.TMR3CS = 0x00

#define TIMER3_ENABLE()   T3CONbits.TMR3ON = 0x01
#define TIMER3_DISABLE()  T3CONbits.TMR3ON = 0x00



/* User defined datatype section */


typedef enum{
    
    TIMER3_PRESCALER_FREQ_DIV_1,
    TIMER3_PRESCALER_FREQ_DIV_2,
    TIMER3_PRESCALER_FREQ_DIV_4,
    TIMER3_PRESCALER_FREQ_DIV_8,

}timer3_prescaler_value_t;

typedef struct{
    
#ifdef TIMER3_INTERRUPT_FEATURE_ENABLE
    void (*Interrupt_Handler)(void);
    
#ifdef PRIORITY_FEATURE_ENABLED
    uint8 priority  :1;
#else 
    uint8 reserved  :1;
    
#endif
    
#endif
    uint16 preloaded_value;
    uint8 prescaler_value                     :2;
    uint8 timer1_timer3_CCP_enables           :2;
    uint8 counter_mode_synchronization_status :1;
    uint8 timer_or_counter_mode               :1;
    uint8 timer_bit_operation_mode            :1;
    
}Timer3_t;

/* Function declaration section */

STD_ReturnType Timer3_Init(Timer3_t *timer3);
STD_ReturnType Timer3_Deinit(Timer3_t *timer3);
STD_ReturnType Timer3_Read(Timer3_t *timer3, uint16 *ticks);
STD_ReturnType Timer3_Write(Timer3_t *timer3, uint16 value);



#endif	/* TIMER3_H */

