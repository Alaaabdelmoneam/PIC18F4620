/* 
 * File:   MCAL_INTERRUPT_MANAGER.c
 * Author: Alaa
 *
 * Created on April 20, 2024, 2:49 PM
 */

#include "MCAL_INTERRUPT_MANAGER.h"
#include "MCAL_EXTERNAL_INTERRUPT.h"

static volatile uint8 RB4_Flag = 1, RB5_Flag = 1, RB6_Flag = 1, RB7_Flag = 1;

#ifdef PRIORITY_FEATURE_ENABLED

void __interrupt() Interrupt_High_Manager(){
    if ((INTERRUPT_ENABLED == INTCONbits.INT0IE) && (INTERRUPT_OCCURED == INTCONbits.INT0IF))
    {
        ISR0();
    }
    else{/* do nothing */}
    if ((INTERRUPT_ENABLED == INTCON3bits.INT1IE) && (INTERRUPT_OCCURED == INTCON3bits.INT1IF))
    {
        ISR1();
    }
    else{/* do nothing */}


    
}

void __interrupt(low_priority) Interrupt_Low_Manager(){
    if ((INTERRUPT_ENABLED == INTCON3bits.INT2IE) && (INTERRUPT_OCCURED == INTCON3bits.INT2IF))
    {
        ISR2();
    }
    else{/* do nothing */}
    if ((INTERRUPT_ENABLED == INTCONbits.RBIE) && (INTERRUPT_OCCURED == INTCONbits.RBIF) && (HIGH == PORTBbits.RB4) && (1 == RB4_Flag))
    {
        RB0_ISR(RISING_EDGE);
    }
    else{RB4_Flag = 0;}
    if ((INTERRUPT_ENABLED == INTCONbits.RBIE) && (INTERRUPT_OCCURED == INTCONbits.RBIF) && (LOW == PORTBbits.RB4) && (1 == RB4_Flag))
    {
        RB0_ISR(FALLING_EDGE);
    }
    else{/* do nothing */}
    if ((INTERRUPT_ENABLED == INTCONbits.RBIE) && (INTERRUPT_OCCURED == INTCONbits.RBIF) && (HIGH == PORTBbits.RB5) && (1 == RB5_Flag))
    {
        RB1_ISR(RISING_EDGE);
    }
    else{RB5_Flag = 0;}
    if ((INTERRUPT_ENABLED == INTCONbits.RBIE) && (INTERRUPT_OCCURED == INTCONbits.RBIF) && (LOW == PORTBbits.RB5) && (1 == RB5_Flag))
    {
        RB1_ISR(FALLING_EDGE);
    }
    else{/* do nothing */}
    if ((INTERRUPT_ENABLED == INTCONbits.RBIE) && (INTERRUPT_OCCURED == INTCONbits.RBIF) && (HIGH == PORTBbits.RB6) && (1 == RB6_Flag))
    {
        RB2_ISR(RISING_EDGE);
    }
    else{RB6_Flag = 0;}
    if ((INTERRUPT_ENABLED == INTCONbits.RBIE) && (INTERRUPT_OCCURED == INTCONbits.RBIF) && (LOW == PORTBbits.RB6) && (1 == RB6_Flag))
    {
        RB2_ISR(FALLING_EDGE);
    }
    else{/* do nothing */}
    if ((INTERRUPT_ENABLED == INTCONbits.RBIE) && (INTERRUPT_OCCURED == INTCONbits.RBIF) && (HIGH == PORTBbits.RB7) && (1 == RB7_Flag))
    {
        RB3_ISR(RISING_EDGE);
    }
    else{RB7_Flag = 0;}
    if ((INTERRUPT_ENABLED == INTCONbits.RBIE) && (INTERRUPT_OCCURED == INTCONbits.RBIF) && (LOW == PORTBbits.RB7) && (1 == RB7_Flag))
    {
        RB3_ISR(FALLING_EDGE);
    }
    else{/* do nothing */}
    RB4_Flag = 1;
    RB5_Flag = 1;
    RB6_Flag = 1;
    RB7_Flag = 1;

}
#else
void __interrupt() Interrupt_Manager(){
    if ((INTERRUPT_ENABLED == INTCONbits.INT0IE) && (INTERRUPT_OCCURED == INTCONbits.INT0IF))
    {
        ISR0();
    }
    else{/* do nothing */}
    if ((INTERRUPT_ENABLED == INTCON3bits.INT1IE) && (INTERRUPT_OCCURED == INTCON3bits.INT1IF))
    {
        ISR1();
    }
    else{/* do nothing */}
    if ((INTERRUPT_ENABLED == INTCON3bits.INT2IE) && (INTERRUPT_OCCURED == INTCON3bits.INT2IF))
    {
        ISR2();
    }
    else{/* do nothing */}
    if ((INTERRUPT_ENABLED == INTCONbits.RBIE) && (INTERRUPT_OCCURED == INTCONbits.RBIF))
    {
//        RBx_ISR();
        RB3_ISR(FALLING_EDGE);
    }
    else{/* do nothing */}
    
    if ((INTERRUPT_ENABLED == PIE1bits.ADIE) && (INTERRUPT_OCCURED == PIR1bits.ADIF))
    {
        ADC_ISR1();
    }
    else{/* do nothing */}

    if ((INTERRUPT_ENABLED == INTCONbits.TMR0IE) && (INTERRUPT_OCCURED == INTCONbits.T0IF))
    {
        Timer0_ISR();
//        var++;
    }
    else{/* do nothing */}
    if ((INTERRUPT_ENABLED == PIE1bits.TMR1IE) && (INTERRUPT_OCCURED == PIR1bits.TMR1IF))
    {
        Timer1_ISR();
//        var++;
    }
    else{/* do nothing */}
    
    if ((INTERRUPT_ENABLED == PIE1bits.TMR2IE) && (INTERRUPT_OCCURED == PIR1bits.TMR2IF))
    {
        Timer2_ISR();
//        var++;
    }
    else{/* do nothing */}
    
    if ((INTERRUPT_ENABLED == PIE2bits.TMR3IE) && (INTERRUPT_OCCURED == PIR2bits.TMR3IF))
    {
        Timer3_ISR();
//        var++;
    }
    else{/* do nothing */}
    
    
}
#endif