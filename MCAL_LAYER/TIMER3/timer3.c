/* 
 * File:   timer3.c
 * Author: Alaa
 *
 * Created on May 10, 2024, 1:09 PM
 */
/* Includes section */
#include "timer3.h"
/* Macros section */
/* Marco-like functions section */
/* User defined datatype section */
/* Function declaration section */
/* Function definition section */


#ifdef TIMER3_INTERRUPT_FEATURE_ENABLE
static void (*Timer3_Interrupt_Handler)(void) = NULL ;
static void write(uint16 value);
#endif

static inline void timer3_select_mode(Timer3_t *timer);
static uint16 timer3_preload;


STD_ReturnType Timer3_Init(Timer3_t *timer3){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == timer3){
        ret = E_NOT_OK;
    }
    else{
        TIMER3_DISABLE();
#ifdef TIMER3_INTERRUPT_FEATURE_ENABLE
        TIMER3_INTERRUPT_FLAG_CLEAR();
        TIMER3_INTERRUPT_ENABLE();
        
        Timer3_Interrupt_Handler = timer3->Interrupt_Handler;
#ifdef PRIORITY_FEATURE_ENABLED
        TIMER3_INTERRUPT_PRIORITY_SET(timer3->priority);
        INTERRUPT_PRIORITY_FEATURE_ENABLE;
        if(PRIORITY_LOW == timer3->priority){
            INTERRUPT_PRIORITY_LOW_ENABLE;
        }
        else if(PRIORITY_HIGH == timer3->priority){
            INTERRUPT_PRIORITY_HIGH_ENABLE;
        }
        else{ /* do nothing */};
#else
        INTERRUPT_GENERAL_FEATURE_ENABLE;
        INTERRUPT_PERIPHERAL_FEATURE_ENABLE;
#endif
        
#endif
        TIMER3_SET_PRESCALER_VALUE(timer3->prescaler_value);

        if(TIMER3_READ_WRITE_8_BIT == timer3->timer_bit_operation_mode){
            TIMER3_ENABLE_8_BIT_MODE();
        }
        else if (TIMER3_READ_WRITE_16_BIT == timer3->timer_bit_operation_mode){
            TIMER3_ENABLE_16_BIT_MODE();
        }
        else{/* do nothing */};
        timer3_select_mode(timer3);
        write(timer3->preloaded_value);
        timer3_preload = timer3->preloaded_value;
        /* set CCP configuration */ 
        switch(timer3->timer1_timer3_CCP_enables){
            case (TIMER1_CCP1_CCP2):
                TIMER1_ENABLE_CLK_CCP1_CCP2();
                break;
            case (TIMER1_CCP1_TIMER3_CCP2):
                TIMER1_ENABLE_CLK_CCP1_TIMER3_ENABLE_CLK_CCP2();
                break;
            case (TIMER3_CCP1_CCP2):
                TIMER3_ENABLE_CLK_CCP1_CCP2();
                break;
            default:{/* do nothing*/}
        }
        TIMER3_ENABLE();
        return ret;
    }
    return ret;
}


STD_ReturnType Timer3_Deinit(Timer3_t *timer3){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == timer3){
        ret = E_NOT_OK;
    }
    else{
        TIMER3_DISABLE();
    }
    return ret;
}


STD_ReturnType Timer3_Read(Timer3_t *timer3, uint16 *ticks){
    STD_ReturnType ret = E_NOT_OK;
    uint8 temp_low = 0, temp_high = 0;
    if ((NULL == timer3) || (NULL == ticks)){
        ret = E_NOT_OK;
    }
    else{
        temp_low  = TMR3L;
        temp_high = TMR3H;
        *ticks = ((uint16)temp_low) | ((uint16)temp_high) ;
    }
    return ret;
}

STD_ReturnType Timer3_Write(Timer3_t *timer3, uint16 value){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == timer3){
        ret = E_NOT_OK;
    }
    else{
        TMR3H = (uint8)(value >> 8);
        TMR3L = (uint8)(value);
    }
    return ret;
}

#ifdef TIMER3_INTERRUPT_FEATURE_ENABLE
void Timer3_ISR(void){
    TIMER3_INTERRUPT_FLAG_CLEAR();
    /* MCAL Code context*/
    write(timer3_preload);
    if(Timer3_Interrupt_Handler){Timer3_Interrupt_Handler();}
}
#endif

static void write(uint16 value){
    TMR3H = (uint8)(value >> 8);
    TMR3L = (uint8)(value);
    
}

static inline void timer3_select_mode(Timer3_t *timer){
    if(TIMER3_TIMER_MODE_ENABLED == timer->timer_or_counter_mode){
    TIMER3_TIMER_MODE_ENABLE();
    }
    else if (TIMER3_COUNTER_MODE_ENABLED == timer->timer_or_counter_mode){
        TIMER3_COUNTER_MODE_ENABLE();
        if(TIMER3_COUNTER_MODE_SYNCHRONIZED == timer->counter_mode_synchronization_status){
            TIMER3_COUNTER_MODE_ENABLE_SYNCHRONIZATION();
        }
        else if (TIMER3_COUNTER_MODE_UNSYNCHRONIZED == timer->counter_mode_synchronization_status){
            TIMER3_COUNTER_MODE_DISABLE_SYNCHRONIZATION();
        }
        else{/* do nothing */};
    }
    else{/* do nothing */};
}