/* 
 * File:   timer.c
 * Author: Alaa
 *
 * Created on May 6, 2024, 3:01 PM
 */


/* Includes section */

#include "timer.h"

/* Macros section */

/* static variables section*/

#ifdef TIMER0_INTERRUPT_FEATURE_ENABLE
static void(*Timer0_ISR_Callback)(void) = NULL;
#endif
static void write(uint16 value);

static uint16 preload;
/* Marco-like functions section */
/* User defined datatype section */

/* Function declaration section */

STD_ReturnType Timer0_Init(timer0_t *timer0){

    STD_ReturnType ret = E_OK;
    if (NULL == timer0){
        ret = E_NOT_OK;
    }
    else{
        TIMER0_DISABLE();
#ifdef TIMER0_INTERRUPT_FEATURE_ENABLE
        TIMER0_INTERRUPT_FLAG_CLEAR();
#endif
        if (ENABLED == timer0->timer_8bit_mode){
            TIMER0_ENABLE_8_bit();
        }
        else{
            TIMER0_ENABLE_16_bit();
        }
        if (ENABLED == timer0->counter_mode){
            TIMER0_ENABLE_COUNTER_MODE();
            if (ENABLED == timer0->counter_rising_edge){
            TIMER0_COUNTER_RISING_EDGE();
            }
            else{
                TIMER0_COUNTER_FALLING_EDGE();
            }
        }
        
        else{
            TIMER0_ENABLE_TIMER_MODE();
        }   
        if (ENABLED == timer0->prescaler_enable){
            PRESCALER_ENABLE();
            PRESCALER_DIV_SET(timer0->prescaler_value);
        }
        else{
            PRESCALER_DISABLE();
        }   
#ifdef TIMER0_INTERRUPT_FEATURE_ENABLE
        Timer0_ISR_Callback = timer0->Interrupt_Handler;
        TIMER0_INTERRUPT_ENABLE();
#ifdef PRIORITY_FEATURE_ENABLED
        INTERRUPT_PRIORITY_FEATURE_ENABLE();
        TIMER0_INTERRUPT_PRIORITY_SET(timer0->priority);
        if(PRIORITY_LOW == timer0->priority){
            INTERRUPT_PRIORITY_LOW_ENABLE;
        }
        else{
            INTERRUPT_PRIORITY_HIGH_ENABLE;
        }
#else
        INTERRUPT_GENERAL_FEATURE_ENABLE;
        INTERRUPT_PERIPHERAL_FEATURE_ENABLE;
#endif
        Timer0_Write(timer0,timer0->preload_value);
        preload = timer0->preload_value;
        TIMER0_ENABLE();
    
#endif
    }
    return ret;
    
}

STD_ReturnType Timer0_Deinit(timer0_t *timer0){
    
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == timer0){
        ret = E_NOT_OK;
    }
    else{
        TIMER0_DISABLE();
    }    
    return ret;
}


STD_ReturnType Timer0_Read(timer0_t *timer0, uint16 *ticks){
//    TIMER0_DISABLE();
    STD_ReturnType ret = E_NOT_OK;
    uint8 temp_low = 0, temp_high = 0;
    if (NULL == timer0 || NULL == ticks){
        ret = E_NOT_OK;
    }
    else{
        if(timer0->timer_8bit_mode){
            *ticks = TMR0L;
        }
        else{
            temp_low  = TMR0L;
            temp_high = TMR0H;
            *ticks = ((uint16)temp_low) | ((uint16)temp_high) ;
        }
    }
    return ret;
}


STD_ReturnType Timer0_Write(timer0_t *timer0, uint16 value){
    
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == timer0){
        ret = E_NOT_OK;
    }
    else{
        if(timer0->timer_8bit_mode){
            TMR0L = (uint8)value;
        }
        else{
            TMR0H = (uint8)(value >> 8);
            TMR0L = (uint8)(value);
        }
     
    }
    return ret;
}

#ifdef TIMER0_INTERRUPT_FEATURE_ENABLE
void Timer0_ISR(void){
    TIMER0_INTERRUPT_FLAG_CLEAR();
    /* MCAL Code context*/
    write(preload);
    if(Timer0_ISR_Callback){Timer0_ISR_Callback();}
}
#endif

static void write(uint16 value){
    TMR0H = (uint8)(value >> 8);
    TMR0L = (uint8)(value);
}