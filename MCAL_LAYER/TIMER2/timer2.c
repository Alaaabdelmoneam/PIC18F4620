/* 
 * File:   timer2.c
 * Author: Alaa
 *
 * Created on May 10, 2024, 10:51 AM
 */

/* Includes section */

#include "timer2.h"

/* Macros section */



/* Marco-like functions section */

/* variable declaration section */

#ifdef TIMER2_INTERRUPT_FEATURE_ENABLE
static void (*Timer2_Interrupt_Handler)(void) = NULL ;
#endif
static uint8 timer2_preload;

/* User defined datatype section */

/* Function definition section */

STD_ReturnType Timer2_Init(Timer2_t *timer2){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == timer2){
        ret = E_NOT_OK;
    }
    else{
        /* disable peripheral */
        TIMER2_DISABLE();
#ifdef TIMER2_INTERRUPT_FEATURE_ENABLE
        TIMER2_INTERRUPT_FLAG_CLEAR();
        TIMER2_INTERRUPT_ENABLE();
        
        Timer2_Interrupt_Handler = timer2->Interrupt_Handler;
#ifdef PRIORITY_FEATURE_ENABLED
        TIMER2_INTERRUPT_PRIORITY_SET(timer2->priority);
        INTERRUPT_PRIORITY_FEATURE_ENABLE;
        if(PRIORITY_LOW == timer2->priority){
            INTERRUPT_PRIORITY_LOW_ENABLE;
        }
        else if(PRIORITY_HIGH == timer2->priority){
            INTERRUPT_PRIORITY_HIGH_ENABLE;
        }
        else{ /* do nothing */};
#else
        INTERRUPT_GENERAL_FEATURE_ENABLE;
        INTERRUPT_PERIPHERAL_FEATURE_ENABLE;
#endif
        
#endif        
        TIMER2_SET_PRESCALER_VALUE(timer2->prescaler_value);
        TIMER2_SET_POSTSCALER_VALUE(timer2->postscaler_value);
        TIMER2_WRITE(timer2->preloaded_value);
        TIMER2_ENABLE();

    }
    return ret;
}

STD_ReturnType Timer2_Deinit(Timer2_t *timer2){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == timer2){
        ret = E_NOT_OK;
    }
    else{
        TIMER2_DISABLE();
    }
    return ret;
}

STD_ReturnType Timer2_Read(Timer2_t *timer2, uint8 *ticks){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == timer2){
        ret = E_NOT_OK;
    }
    else{
        *ticks = TMR2;
    }
    return ret;
}

STD_ReturnType Timer2_Write(Timer2_t *timer2, uint8 value){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == timer2){
        ret = E_NOT_OK;
    }
    else{
        TIMER2_WRITE(value);
    }
    return ret;
}


#ifdef TIMER2_INTERRUPT_FEATURE_ENABLE
void Timer2_ISR(void){
    TIMER2_INTERRUPT_FLAG_CLEAR();
    /* MCAL Code context*/
    TIMER2_WRITE(timer2_preload);
    if(Timer2_Interrupt_Handler){Timer2_Interrupt_Handler();}
}
#endif

