/* 
 * File:   MCAL_INTERNAL_INTERRUPT.h
 * Author: Alaa
 *
 * Created on April 20, 2024, 2:48 PM
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H



/* Includes section */

#include "MCAL_INTERRUPT_CONFIG.h"


/* Macros section */
/* Marco-like functions section */

/* ADC Interrupts configurations */

#ifdef ADC_INTERRUPT_FEATURE_ENABLE

#ifdef PRIORITY_FEATURE_ENABLED
#define ADC_INTERRUPT_PRIORITY_HIGH()         IPR1bits.ADIP = 1
#define ADC_INTERRUPT_PRIORITY_LOW()          IPR1bits.ADIP = 0
#endif
#define ADC_INTERRUPT_ENABLE()                PIE1bits.ADIE = 1
#define ADC_INTERRUPT_DISABLE()               PIE1bits.ADIE = 0

#define ADC_INTERRUPT_FLAG()                  PIR1bits.ADIF
#define ADC_INTERRUPT_FLAG_CLEAR()            PIR1bits.ADIF = 0


/* Timer0 Interrupts configurations */


#ifdef TIMER0_INTERRUPT_FEATURE_ENABLE

#define TIMER0_INTERRUPT_ENABLE()        INTCONbits.TMR0IE = 1
#define TIMER0_INTERRUPT_DISABLE()       INTCONbits.TMR0IE = 0

#define TIMER0_INTERRUPT_FLAG_CLEAR()    INTCONbits.TMR0IF = 0
#define TIMER0_INTERRUPT_FLAG_CHECK()    INTCONbits.TMR0IF



    
#ifdef PRIORITY_FEATURE_ENABLED

#define TIMER0_INTERRUPT_PRIORITY_SET(PRIORITY) INTCON2bits.TMR0IP = PRIORITY

#endif
    
#endif

/* Timer1 Interrupts configurations */

#ifdef TIMER1_INTERRUPT_FEATURE_ENABLE

#define TIMER3_INTERRUPT_ENABLE()        PIE1bits.TMR1IE = 1
#define TIMER1_INTERRUPT_DISABLE()       PIE1bits.TMR1IE = 0

#define TIMER1_INTERRUPT_FLAG_CLEAR()    PIR1bits.TMR1IF = 0
#define TIMER1_INTERRUPT_FLAG_CHECK()    PIR1bits.TMR1IF


    
#ifdef PRIORITY_FEATURE_ENABLED

#define TIMER1_INTERRUPT_PRIORITY_SET(PRIORITY) IPR1.TMR1IP = PRIORITY

#endif
    
#endif

/* Timer2 Interrupts configurations */

#ifdef TIMER2_INTERRUPT_FEATURE_ENABLE

#define TIMER2_INTERRUPT_ENABLE()        PIE1bits.TMR2IE = 1
#define TIMER2_INTERRUPT_DISABLE()       PIE1bits.TMR2IE = 0

#define TIMER2_INTERRUPT_FLAG_CLEAR()    PIR1bits.TMR2IF = 0
#define TIMER2_INTERRUPT_FLAG_CHECK()    PIR1bits.TMR2IF


    
#ifdef PRIORITY_FEATURE_ENABLED

#define TIMER2_INTERRUPT_PRIORITY_SET(PRIORITY) IPR1.TMR2IP = PRIORITY

#endif
    
#endif

/* Timer3 Interrupts configurations */

#ifdef TIMER3_INTERRUPT_FEATURE_ENABLE

#define TIMER3_INTERRUPT_ENABLE()        PIE2bits.TMR3IE = 1
#define TIMER3_INTERRUPT_DISABLE()       PIE2bits.TMR3IE = 0

#define TIMER3_INTERRUPT_FLAG_CLEAR()    PIR2bits.TMR3IF = 0
#define TIMER3_INTERRUPT_FLAG_CHECK()    PIR2bits.TMR3IF


    
#ifdef PRIORITY_FEATURE_ENABLED

#define TIMER3_INTERRUPT_PRIORITY_SET(PRIORITY) IPR2.TMR3IP = PRIORITY

#endif
    
#endif

/* User defined datatype section */
/* Function declaration section */

//void ADC_Interrupt_Init();
//void ADC_Deinit();
//void ADC_Set_Priority();

#endif

#endif	/* MCAL_INTERNAL_INTERRUPT_H */

