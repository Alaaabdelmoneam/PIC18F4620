/* 
 * File:   timer.h
 * Author: Alaa
 *
 * Created on May 8, 2024, 2:53 PM
 */

#ifndef TIMER1_H
#define TIMER1_H

/* Includes section */
#include "timer_cfg.h"
#include "../GPIO/HAL_GPIO.h"
#include "../interrupts/MCAL_INTERNAL_INTERRUPT.h"
/* Macros section */

#define TIMER1_SYSTEM_RUNNING_ON_TMR1_OSC           0X01
#define TIMER1_SYSTEM_NOT_RUNNING_ON_TMR1_OSC       0X00

#define TIMER1_READ_WRITE_16_BIT 0x01
#define TIMER1_READ_WRITE_8_BIT  0x00

#define TIMER1_OSC_ENABLED  0x01
#define TIMER1_OSC_DISABLED 0x00

#define TIMER1_COUNTER_MODE_SYNCHRONIZED   0x00
#define TIMER1_COUNTER_MODE_UNSYNCHRONIZED 0x01

#define TIMER1_TIMER_MODE_ENABLED     0x00
#define TIMER1_COUNTER_MODE_ENABLED   0x01

#define TIMER1_ENABLED  0x01
#define TIMER1_DISABLED 0x00

/* Marco-like functions section */

#define TIMER1_CHECK_SYSTEM_RUNNING_ON_TMR1_OSC()   (T1CONbits.T1RUN)


#define TIMER1_SET_PRESCALER_VALUE(value) T1CONbits.T1CKPS = value

#define TIMER1_ENABLE_OSC()    T1CONbits.T1OSCEN = 0x01
#define TIMER1_DISABLE_OSC()   T1CONbits.T1OSCEN = 0x00



#define TIMER1_ENABLE_16_BIT_MODE()    T1CONbits.RD16 = 0x01
#define TIMER1_ENABLE_8_BIT_MODE()     T1CONbits.RD16 = 0x00

#define TIMER1_COUNTER_MODE_ENABLE_SYNCHRONIZATION()  T1CONbits.T1SYNC = 0x00
#define TIMER1_COUNTER_MODE_DISABLE_SYNCHRONIZATION() T1CONbits.T1SYNC = 0x01

#define TIMER1_COUNTER_MODE_ENABLE()  T1CONbits.TMR1CS = 0x01
#define TIMER1_TIMER_MODE_ENABLE()    T1CONbits.TMR1CS = 0x00

#define TIMER1_ENABLE()   T1CONbits.TMR1ON = 0x01
#define TIMER1_DISABLE()  T1CONbits.TMR1ON = 0x00

/* User defined datatype section */

typedef enum{
    
    TIMER1_PRESCALER_FREQ_DIV_1,
    TIMER1_PRESCALER_FREQ_DIV_2,
    TIMER1_PRESCALER_FREQ_DIV_4,
    TIMER1_PRESCALER_FREQ_DIV_8,

}timer1_prescaler_value_t;

typedef struct{
    
#ifdef TIMER1_INTERRUPT_FEATURE_ENABLE
    void (*Interrupt_Handler)(void);
    
#ifdef PRIORITY_FEATURE_ENABLED
    uint8 priority:  1;
#endif
    
#endif
    uint16 preloaded_value;
    uint8 prescaler_value                     :2;
    uint8 oscilator_status                    :1;
    uint8 counter_mode_synchronization_status :1;
    uint8 timer_or_counter_mode               :1;
    uint8 reserved                            :2;
    uint8 timer_bit_operation_mode            :1;
    
}Timer1_t;

/* Function declaration section */

STD_ReturnType Timer1_Init(Timer1_t *timer1);
STD_ReturnType Timer1_Deinit(Timer1_t *timer1);
STD_ReturnType Timer1_Read(Timer1_t *timer1, uint16 *ticks);
STD_ReturnType Timer1_Write(Timer1_t *timer1, uint16 value);

#endif	/* TIMER1_H */

