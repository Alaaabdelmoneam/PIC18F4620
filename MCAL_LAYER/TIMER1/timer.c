/* 
 * File:   timer.c
 * Author: Alaa
 *
 * Created on May 8, 2024, 2:53 PM
 */




/* Includes section */
#include "timer.h"
/* Macros section */
/* Marco-like functions section */
/* User defined datatype section */
/* Function declaration section */

#ifdef TIMER1_INTERRUPT_FEATURE_ENABLE
static void (*Timer1_Interrupt_Handler)(void) = NULL ;
static void write(uint16 value);
#endif

static inline void timer1_select_mode(Timer1_t *timer);
static uint16 timer1_preload;

STD_ReturnType Timer1_Init(Timer1_t *timer1){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == timer1){
        ret = E_NOT_OK;
    }
    else{
        TIMER1_DISABLE();
#ifdef TIMER1_INTERRUPT_FEATURE_ENABLE
        TIMER1_INTERRUPT_FLAG_CLEAR();
        TIMER3_INTERRUPT_ENABLE();
        
        Timer1_Interrupt_Handler = timer1->Interrupt_Handler;
#ifdef PRIORITY_FEATURE_ENABLED
        TIMER1_INTERRUPT_PRIORITY_SET(timer1->priority);
        INTERRUPT_PRIORITY_FEATURE_ENABLE;
        if(PRIORITY_LOW == timer1->priority){
            INTERRUPT_PRIORITY_LOW_ENABLE;
        }
        else if(PRIORITY_HIGH == timer1->priority){
            INTERRUPT_PRIORITY_HIGH_ENABLE;
        }
        else{ /* do nothing */};
#else
        INTERRUPT_GENERAL_FEATURE_ENABLE;
        INTERRUPT_PERIPHERAL_FEATURE_ENABLE;
#endif
        
#endif
        TIMER1_SET_PRESCALER_VALUE(timer1->prescaler_value);
        if(TIMER1_OSC_ENABLED == timer1->oscilator_status){
            TIMER1_ENABLE_OSC();
        }
        else if (TIMER1_OSC_DISABLED == timer1->oscilator_status){
            TIMER1_DISABLE_OSC();
        }
        else{/* do nothing */};
        if(TIMER1_READ_WRITE_8_BIT == timer1->timer_bit_operation_mode){
            TIMER1_ENABLE_8_BIT_MODE();
        }
        else if (TIMER1_READ_WRITE_16_BIT == timer1->timer_bit_operation_mode){
            TIMER1_ENABLE_16_BIT_MODE();
        }
        else{/* do nothing */};
        timer1_select_mode(timer1);
        write(timer1->preloaded_value);
        timer1_preload = timer1->preloaded_value;

        TIMER1_ENABLE();
        return ret;
        
    }
}

STD_ReturnType Timer1_Deinit(Timer1_t *timer1){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == timer1){
        ret = E_NOT_OK;
    }
    else{
        TIMER1_DISABLE();
    }
    return ret;
}

STD_ReturnType Timer1_Read(Timer1_t *timer1, uint16 *ticks){
    STD_ReturnType ret = E_NOT_OK;
    uint8 temp_low = 0, temp_high = 0;
    if ((NULL == timer1) || (NULL == ticks)){
        ret = E_NOT_OK;
    }
    else{
        temp_low  = TMR0L;
        temp_high = TMR0H;
        *ticks = ((uint16)temp_low) | ((uint16)temp_high) ;
//        if(TIMER1_READ_WRITE_8_BIT == timer1->timer_bit_operation_mode){
//            *ticks = TMR0L;
//        }
//        else if (TIMER1_READ_WRITE_16_BIT == timer1->timer_bit_operation_mode){
//            uint8 temp = TMR0L;
//            *ticks = ((uint16)temp) | ((uint16)TMR0H) ;
//        }
//        else(){/* do nothing */};
    }
    return ret;
}

STD_ReturnType Timer1_Write(Timer1_t *timer1, uint16 value){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == timer1){
        ret = E_NOT_OK;
    }
    else{
//        if(TIMER1_READ_WRITE_8_BIT == timer1->timer_bit_operation_mode){
//            TMR0L = (uint8)value;
//        }
//        else if (TIMER1_READ_WRITE_16_BIT == timer1->timer_bit_operation_mode){
//        TMR0H = (uint8)(value >> 8);
//        TMR0L = (uint8)(value);
//        }
//        else(){/* do nothing */};
        TMR0H = (uint8)(value >> 8);
        TMR0L = (uint8)(value);
    }
    return ret;
}

#ifdef TIMER1_INTERRUPT_FEATURE_ENABLE
void Timer1_ISR(void){
    TIMER1_INTERRUPT_FLAG_CLEAR();
    /* MCAL Code context*/
    write(timer1_preload);
    if(Timer1_Interrupt_Handler){Timer1_Interrupt_Handler();}
}
#endif

static void write(uint16 value){
    TMR0H = (uint8)(value >> 8);
    TMR0L = (uint8)(value);
    
}

static inline void timer1_select_mode(Timer1_t *timer){
    if(TIMER1_TIMER_MODE_ENABLED == timer->timer_or_counter_mode){
    TIMER1_TIMER_MODE_ENABLE();
    }
    else if (TIMER1_COUNTER_MODE_ENABLED == timer->timer_or_counter_mode){
        TIMER1_COUNTER_MODE_ENABLE();
        if(TIMER1_COUNTER_MODE_SYNCHRONIZED == timer->counter_mode_synchronization_status){
            TIMER1_COUNTER_MODE_ENABLE_SYNCHRONIZATION();
        }
        else if (TIMER1_COUNTER_MODE_UNSYNCHRONIZED == timer->counter_mode_synchronization_status){
            TIMER1_COUNTER_MODE_DISABLE_SYNCHRONIZATION();
        }
        else{/* do nothing */};
    }
    else{/* do nothing */};
}