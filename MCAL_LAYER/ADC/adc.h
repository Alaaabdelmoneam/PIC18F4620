/* 
 * File:   adc.h
 * Author: Alaa
 *
 * Created on April 30, 2024, 4:47 PM
 */

#ifndef ADC_H
#define	ADC_H


/* Includes section */
#include "adc_cfg.h"
#include "../../MCAL_LAYER/GPIO/HAL_GPIO.h"
#include <pic18f4620.h>
#include "../STD_TYPES.h"
#include "../interrupts/MCAL_INTERNAL_INTERRUPT.h"

/* Macros section */


#define CLEARED   0
#define TRIGGERED 1


#define CONVERSION_COMPLETED 1
#define CONVERSION_NOT_COMPLETED 0

#define RIGHT_JUSTIFIED  1
#define LEFT_JUSTIFIED   0

#define ADC_REFRENCE_VOLTAGE 1
#define ADC_SUPPLY_VOLTAGE   0

/* Marco-like functions section */

/* ADCON0 interfaces */
#define ADC_ENABLE()                                       ADCON0bits.ADON = 1
#define ADC_DISABLE()                                      ADCON0bits.ADON = 0

#define ADC_START_CONVERSION()                             ADCON0bits.GODONE = 1
#define ADC_CHECK_CONVERSION_STATUS()                     !(ADCON0bits.GO_DONE)

#define ADC_CHECK_CONVERSION_INTERRUPT_FLAG()              (PIR1bits.ADIF)
#define ADC_CLEAR_INTERRUPT_FLAG()                         (PIR1bits.ADIF = 0)

#define ADC_GET_DATA_LOWER()                               (ADRESL)
#define ADC_GET_DATA_HIGHER()                              (ADRESH)
#define ADC_GET_DATA_RIGHT_JUSTIFIED()                     (uint16)((ADRESL) | ((ADRESH) << 8))
#define ADC_GET_DATA_LEFT_JUSTIFIED()                      (uint16)(((ADRESL) | ((ADRESH) << 8)) >> 6)
/* ADCON1 interfaces */

#define ADC_USE_REFRENCE_VOLTAGE()                                  {ADCON1bits.VCFG0 = ADC_REFRENCE_VOLTAGE;\
                                                                     ADCON1bits.VCFG0 = ADC_REFRENCE_VOLTAGE;}

#define ADC_USE_SUPPLY_VOLTAGE()                                    {ADCON1bits.VCFG0 = ADC_SUPPLY_VOLTAGE;\
                                                                     ADCON1bits.VCFG0 = ADC_SUPPLY_VOLTAGE;}
                     
#define ADC_SET_SELECTED_CHANNEL(Channel_Number)                     ADCON0bits.CHS   = Channel_Number
#define ADC_SELECT_ACTIVATED_ANALOG_CHANNELS(Activated_Channels)     ADCON1bits.PCFG  = Activated_Channels

/* ADCON1 interfaces */

#define ADC_SET_DATA_RIGHT_JUSTIFIED()                               ADCON2bits.ADFM  = 1
#define ADC_SET_DATA_LEFT_JUSTIFIED()                                ADCON2bits.ADFM  = 0
#define ADC_SET_ACQUISITION_TIME(ACQUISITION_TIME)                   ADCON2bits.ACQT  = ACQUISITION_TIME
#define ADC_SET_CONVERSION_CLOCK(ADC_CONVERSION_CLOCK)               ADCON2bits.ADCS  = ADC_CONVERSION_CLOCK

//#define ADC_SELECT_CHANNEL(ANx)                            ADCON0bits.CHS = ANx
/* User defined datatype section */

typedef enum{
    AN_0,
    AN_1,
    AN_2,
    AN_3,
    AN_4,
    AN_5,
    AN_6,
    AN_7,
    AN_8,
    AN_9,
    AN_10,
    AN_11,
    AN_12,
}ANx_SELECTED_CHANNEL_t;

typedef enum{
    
    TAD_0,
    TAD_2,
    TAD_4,
    TAD_6,
    TAD_8,
    TAD_12,
    TAD_16,
    TAD_20
    
}ADC_AQUISITION_TIME_t;


typedef enum{
    
    FOSC_DIV_2,
    FOSC_DIV_8,
    FOSC_DIV_32,
    FOSC_RC,
    FOSC_DIV_4,
    FOSC_DIV_16,
    FOSC_DIV_64,
   
}ADC_CONVERSION_CLOCK_t;




/**
 * @brief: this enumeration iterates over all possible states of analog pins
 * ANx means that all channels from AN0 till ANx are used as analog
 * for example: AN12 means All channels from AN0 to AN12 are used as analog pins
 */
typedef enum{
    ALL_ANALOG = 2,
    FROM_AN0_TO_AN11,
    FROM_AN0_TO_AN10,
    FROM_AN0_TO_AN9,
    FROM_AN0_TO_AN8,
    FROM_AN0_TO_AN7,
    FROM_AN0_TO_AN6,
    FROM_AN0_TO_AN5,
    FROM_AN0_TO_AN4,
    FROM_AN0_TO_AN3,
    FROM_AN0_TO_AN2,
    FROM_AN0_TO_AN1,
    FROM_AN0_TO_AN0,
    ALL_DIGITAL,
}ANx_ACTIVATED_CHANNELS_t;

typedef struct{
#ifdef ADC_INTERRUPT_FEATURE_ENABLE
    void (* ADC_interrupt_handler)(void);
    
#ifdef PRIORITY_FEATURE_ENABLED
    Priority_t priority;
#endif //priority feature
    
#endif // Interrupt feature 
    ANx_ACTIVATED_CHANNELS_t ANx_ACTIVATED_CHANNELS;
    ADC_CONVERSION_CLOCK_t   ADC_CONVERSION_CLOCK;
    ADC_AQUISITION_TIME_t    ADC_AQUISITION_TIME;
    ANx_SELECTED_CHANNEL_t   ANx_SELECTED_CHANNEL;
    uint8 DATA_ALLIGNMENT_FORMAT         : 1;
    uint8 VOLTAGE_SOURCE_USED            : 1;
    uint8 RESERVED                       : 6;
}ADC_CONFIG_t;

/* Function declaration section */

//STD_ReturnType ADC_Select_Used_Channel(ANx_t Analog_channel_index);
//STD_ReturnType ADC_Select_Activated_channels(ANx_Activated_Channels_t activated_channels);

STD_ReturnType ADC_Init(const ADC_CONFIG_t* ADC);
STD_ReturnType ADC_Deinit(const ADC_CONFIG_t* ADC);
STD_ReturnType ADC_Select_Channel(const ADC_CONFIG_t* ADC, ANx_SELECTED_CHANNEL_t channel);
STD_ReturnType ADC_Start_Conversion(const ADC_CONFIG_t* ADC);
STD_ReturnType ADC_Get_Conversion_Status(const ADC_CONFIG_t* ADC, uint8* conversion_done);
STD_ReturnType ADC_Get_Conversion_Data(const ADC_CONFIG_t* ADC, uint16* conversion_data);
STD_ReturnType ADC_Conversion_Complete_Blocking_Operation(const ADC_CONFIG_t* ADC, 
                                                 ANx_SELECTED_CHANNEL_t channel,
                                                 uint16* conversion_data);
STD_ReturnType ADC_Conversion_Complete_Non_Blocking_Operation(const ADC_CONFIG_t* ADC, 
                                                 ANx_SELECTED_CHANNEL_t channel,
                                                 uint16* conversion_data);

#endif	/* ADC_H */

