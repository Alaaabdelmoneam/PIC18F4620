/* 
 * File:   MCAL_EXTERNAL_INTERRUPT.h
 * Author: Alaa
 *
 * Created on April 20, 2024, 2:49 PM
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

#include "MCAL_INTERRUPT_CONFIG.h"

#define INT0_EXTERNAL_INTERRUPT 0
#define INT1_EXTERNAL_INTERRUPT 1
#define INT2_EXTERNAL_INTERRUPT 2

#ifdef  INTx_FEATURE_ENABLE
#define INT0_FEATURE_ENABLE       (INTCONbits.INT0IE = 1)
#define INT0_FEATURE_DISABLE      (INTCONbits.INT0IE = 0)
#define INT0_FLAG_CLEAR           (INTCONbits.INT0IF = 0)
#define INT0_RISING_EDGE_ENABLE   (INTCON2bits.INTEDG0 = 1)
#define INT0_FALLING_EDGE_ENABLE  (INTCON2bits.INTEDG0 = 0)


#define INT1_FEATURE_ENABLE            (INTCON3bits.INT1E  = 1)
#define INT1_FEATURE_DISABLE           (INTCON3bits.INT1IE = 0)
#define INT1_FLAG_CLEAR                (INTCON3bits.INT1IF = 0)
#define INT1_RISING_EDGE_ENABLE        (INTCON2bits.INTEDG1 = 1)
#define INT1_FALLING_EDGE_ENABLE       (INTCON2bits.INTEDG1 = 0)

#define INT2_FEATURE_ENABLE            (INTCON3bits.INT2IE  = 1)
#define INT2_FEATURE_DISABLE           (INTCON3bits.INT2IE = 0)
#define INT2_FLAG_CLEAR                (INTCON3bits.INT2IF = 0)
#define INT2_RISING_EDGE_ENABLE        (INTCON2bits.INTEDG2 = 1)
#define INT2_FALLING_EDGE_ENABLE       (INTCON2bits.INTEDG2 = 0)

#ifdef PRIORITY_FEATURE_ENABLED

#define INT1_PRIORITY_SET(PRIORITY)    (INTCON3bits.INT1IP = PRIORITY) 
#define INT2_PRIORITY_SET(PRIORITY)    (INTCON3bits.INT2IP = PRIORITY) 

#endif
#endif


#ifdef RBx_FEATURE_ENABLE

#define INTERRUT_RBx_FEATURE_ENABLE       (INTCONbits.RBIE  = 1)
#define INTERRUT_RBx_FEATURE_DISABLE      (INTCONbits.RBIE  = 0)
#define INTERRUT_RBx_FLAG_CLEAR           (INTCONbits.RBIF  = 0)


#ifdef PRIORITY_FEATURE_ENABLED 

#define INTERRUT_RBx_PRIORITY_SET(PRIORITY)       (INTCON2bits.RBIP = PRIORITY)

#endif

#endif

typedef enum {
    INT0_INTERRUPT,
    INT1_INTERRUPT,        
    INT2_INTERRUPT,
}INTx_source_t;

typedef enum {
    FALLING_EDGE,
    RISING_EDGE
}INTx_Edge_t;

typedef struct {
    INTx_source_t source;
    pin_config_t pin;
#ifdef PRIORITY_FEATURE_ENABLED
    Priority_t priority;
#endif
    INTx_Edge_t edge;
    void (* callback)(void);
    
}Interrupt_INTx_t;


typedef struct{
    pin_config_t pin;
#ifdef PRIORITY_FEATURE_ENABLED
    Priority_t priority;
#endif
    void (* callback)(void);
}Interrupt_RBx_t;

STD_ReturnType INTx_init(const Interrupt_INTx_t *INTx);
STD_ReturnType INTx_Deinit(const Interrupt_INTx_t *INTx);

STD_ReturnType RBx_init(const Interrupt_RBx_t *INTx);
STD_ReturnType RBx_Deinit(const Interrupt_RBx_t *INTx);

#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

