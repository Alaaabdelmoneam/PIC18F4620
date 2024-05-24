
/* 
 * File:   MCAL_INTERNAL_INTERRUPT.c
 * Author: Alaa
 *
 * Created on April 20, 2024, 2:48 PM
 */



/* Includes section */

#include "MCAL_INTERNAL_INTERRUPT.h"
#include "../../ECU_LAYER/LED/LED.h"
/* Macros section */
/* Global variables section */
void (*ADC_Callback)(void) = NULL;

#ifdef PRIORITY_FEATURE_ENABLED

#endif

/* Marco-like functions section */
/* User defined datatype section */
/* Function declaration section */
/* Function definition section */


//void ADC_ISR();

//void ADC_Init(){
//    
//}
//void ADC_Deinit();
//void ADC_Set_Priority();