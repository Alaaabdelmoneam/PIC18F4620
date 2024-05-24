/* 
 * File:   MCAL_INTERRUPT_MANAGER.h
 * Author: Alaa
 *
 * Created on April 20, 2024, 2:49 PM
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H

#include "MCAL_INTERRUPT_CONFIG.h"

//extern uint16 var;
void ISR0(void);
void ISR1(void);
void ISR2(void);
void RB0_ISR(uint8 level);
void RB1_ISR(uint8 level);
void RB2_ISR(uint8 level);
void RB3_ISR(uint8 level);
void ADC_ISR1();
void ADC_ISR2();
void ADC_ISR3();
void ADC_ISR4();
void Timer0_ISR(void);
void Timer1_ISR(void);
void Timer2_ISR(void);
void Timer3_ISR(void);

#endif	/* MCAL_INTERRUPT_MANAGER_H */

