/* 
 * File:   adc.c
 * Author: Alaa
 *
 * Created on April 30, 2024, 4:47 PM
 */

#include "adc.h"
#include "../interrupts/MCAL_INTERNAL_INTERRUPT.h"
#include "../../MCAL_LAYER/interrupts/MCAL_INTERNAL_INTERRUPT.h"
#include "../../ECU_LAYER/LED/LED.h"

static void (*ADC_Interrupt_Handler)(void) = NULL;

led_t led = {
    .PIN = PIN0, .PORT = PORTC_INDEX, .state = LOW
};

static void inline ADC_Enable_Input_Channel(const ANx_SELECTED_CHANNEL_t channel);
static void inline ADC_Select_Voltage_Source(const ADC_CONFIG_t* ADC);
static void inline ADC_Select_Data_Display_Format(const ADC_CONFIG_t* ADC);
#ifdef PRIORITY_FEATURE_ENABLED
static void inline ADC_Select_priority(Priority_t priority);
#endif
static uint16 inline ADC_Get_Data(const ADC_CONFIG_t* ADC);

/**
 * @breif Initialize the ADC module
 * @param ADC
 * @return STD_ReturnType
 */
STD_ReturnType ADC_Init(const ADC_CONFIG_t* ADC){
    STD_ReturnType ret = E_OK;
    if (NULL == ADC){
        ret = E_NOT_OK;
    }
    else{
        /* Disable A/D feature */
        ADC_DISABLE();
        /* Choose used voltage resource */
        ADC_Select_Voltage_Source(ADC);
        /* Select activated analog channels */
        ADC_SELECT_ACTIVATED_ANALOG_CHANNELS(ADC->ANx_ACTIVATED_CHANNELS);
        ADC_Enable_Input_Channel(ADC->ANx_SELECTED_CHANNEL);
        /* Select the clock source */
        ADC_SET_CONVERSION_CLOCK(ADC->ADC_CONVERSION_CLOCK);
        /* Select the acquisition time*/
        ADC_SET_ACQUISITION_TIME(ADC->ADC_AQUISITION_TIME);
        /* Select the default channel */
        ADC_SET_SELECTED_CHANNEL(ADC->ANx_SELECTED_CHANNEL);
        /* set the callback function if interrupt feature is enabled */
#ifdef ADC_INTERRUPT_FEATURE_ENABLE
        /* Clear Flag */
        ADC_CLEAR_INTERRUPT_FLAG();
        ADC_Interrupt_Handler = ADC->ADC_interrupt_handler;
        ADC_INTERRUPT_ENABLE();
        /* set the priority if priority feature is enabled globally*/
        
#ifdef PRIORITY_FEATURE_ENABLED
        INTERRUPT_PRIORITY_FEATURE_ENABLE;
        ADC_Select_priority(ADC->priority);
        INTERRUPT_PRIORITY_HIGH_ENABLE;
        INTERRUPT_PRIORITY_LOW_ENABLE;
#else
        INTERRUPT_GENERAL_FEATURE_ENABLE;
        INTERRUPT_PERIPHERAL_FEATURE_ENABLE;
#endif
        
#endif
        /* set the data display format */
        ADC_Select_Data_Display_Format(ADC);
        /* Enable A/D feature */
        ADC_ENABLE();
        
    }
    return ret;
}

/**
 * @breif De-initialize the ADC module
 * @param ADC
 * @return STD_ReturnType
 */
STD_ReturnType ADC_Deinit(const ADC_CONFIG_t* ADC){
    STD_ReturnType ret = E_OK;
    if (NULL == ADC){
        ret = E_NOT_OK;
    }
    else{
        /* Disable A/D feature */
        ADC_DISABLE();
    }
    return ret;
}

/**
 * @breif Select the channel used for analog conversion
 * @param ADC
 * @param channel
 * @return STD_ReturnType
 */
STD_ReturnType ADC_Select_Channel(const ADC_CONFIG_t* ADC, ANx_SELECTED_CHANNEL_t channel){
    STD_ReturnType ret = E_OK;
    if (NULL == ADC){
        ret = E_NOT_OK;
    }
    else{
        ADC_SET_SELECTED_CHANNEL(channel);
        ADC_Enable_Input_Channel(channel);
    }
    return ret;
}

/**
 * @breif start converting the analog input
 * @param ADC
 * @return STD_ReturnType
 */
STD_ReturnType ADC_Start_Conversion(const ADC_CONFIG_t* ADC){
    STD_ReturnType ret = E_OK;
    if (NULL == ADC){
        ret = E_NOT_OK;
    }
    else{
        ADC_START_CONVERSION();
    }
    return ret;
}

/**
 * @breif check if the conversion completed or not
 * @param ADC
 * @param conversion_done
 * @return STD_ReturnType
 */
STD_ReturnType ADC_Get_Conversion_Status(const ADC_CONFIG_t* ADC, uint8* conversion_done){
    STD_ReturnType ret = E_OK;
    if ((NULL == ADC )|| (NULL == conversion_done)){
        ret = E_NOT_OK;
    }
    else{
        *conversion_done = (uint8) ADC_CHECK_CONVERSION_STATUS();
    }
    return ret;
}

/**
 * @breif Get data after conversion with polling of GO_DONE Flag
 * @param ADC
 * @param conversion_data
 * @return STD_ReturnType
 */
STD_ReturnType ADC_Get_Conversion_Data(const ADC_CONFIG_t* ADC, uint16* conversion_data){
    STD_ReturnType ret = E_OK;
    if ((NULL == ADC )|| (NULL == conversion_data)){
        ret = E_NOT_OK;
    }
    else{
        while (CONVERSION_NOT_COMPLETED == ADC_CHECK_CONVERSION_STATUS());
        *conversion_data = ADC_Get_Data(ADC);
    }
    return ret;
}


/**
 * @breif: complete ADC conversion, a combination of the ADC_Select_Channel,
 *         ADC_Get_Conversion_Status, and ADC_Get_Conversion_Data
 * @param ADC
 * @param channel
 * @param conversion_data
 * @return STD_ReturnType
 */
STD_ReturnType ADC_Conversion_Complete_Blocking_Operation(const ADC_CONFIG_t* ADC, 
                                                 ANx_SELECTED_CHANNEL_t channel,
                                                 uint16* conversion_data){
    STD_ReturnType ret = E_OK;
    if ((NULL == ADC )|| (NULL == conversion_data)){
        ret = E_NOT_OK;
    }
    else{
        ADC_INTERRUPT_DISABLE();
        ADC_Select_Channel(ADC,channel);
        ADC_Start_Conversion(ADC);
        ADC_Get_Conversion_Data(ADC,conversion_data);
        
    }
    return ret;
}

/**
 * @breif: complete ADC conversion, a combination of the ADC_Select_Channel,
 *         ADC_Get_Conversion_Status, and ADC_Get_Conversion_Data_Non_Blocking
 * @param ADC
 * @param channel
 * @param conversion_data
 * @return STD_ReturnType
 */
STD_ReturnType ADC_Conversion_Complete_Non_Blocking_Operation(const ADC_CONFIG_t* ADC, 
                                                 ANx_SELECTED_CHANNEL_t channel,
                                                 uint16* conversion_data){
    STD_ReturnType ret = E_OK;
    if ((NULL == ADC )|| (NULL == conversion_data)){
        ret = E_NOT_OK;
    }
    else{
        ADC_INTERRUPT_ENABLE();
        ADC_Select_Channel(ADC,channel);
        ADC_Start_Conversion(ADC);
        
    }
    return ret;
}

/**
 * @breif: helper function that enables a certain pin as input
 *         pin according to the passed parameter channel
 * @param channel
 */
static void inline ADC_Enable_Input_Channel(const ANx_SELECTED_CHANNEL_t channel){
    switch(channel){
        case AN_0:
            SET_BIT(TRISA,0);
            break;
        case AN_1:
            SET_BIT(TRISA,1);
            break;
        case AN_2:
            SET_BIT(TRISA,2);
            break;
        case AN_3:
            SET_BIT(TRISA,3);
            break;
        case AN_4:
            SET_BIT(TRISA,5);
            break;
        case AN_5:
            SET_BIT(TRISE,0);
            break;
        case AN_6:
            SET_BIT(TRISE,1);
            break;
        case AN_7:
            SET_BIT(TRISE,2);
            break;
        case AN_8:
            SET_BIT(TRISB,2);
            break;
        case AN_9:
            SET_BIT(TRISB,3);
            break;
        case AN_10:
            SET_BIT(TRISB,1);
            break;
        case AN_11:
            SET_BIT(TRISB,4);
            break;
        case AN_12:
            SET_BIT(TRISB,0);
            break;
        default:/* Nothing */;
    }
}

/**
 * @breif: helper function that selects a certain voltage
 *         source according to the VOLTAGE_SOURCE_USED member
 *         in the passed parameter ADC 
 * @param ADC
 */

static void inline ADC_Select_Voltage_Source(const ADC_CONFIG_t* ADC){
    if (ADC_SUPPLY_VOLTAGE == ADC->VOLTAGE_SOURCE_USED){
        ADC_USE_SUPPLY_VOLTAGE();
    }
    else{
        ADC_USE_REFRENCE_VOLTAGE();
    }
}

/**
 * @breif: helper function that selects a certain Display
 *         format according to the DATA_ALLIGNMENT_FORMAT member
 *         in the passed parameter ADC 
 * @param ADC
 */

static void inline ADC_Select_Data_Display_Format(const ADC_CONFIG_t* ADC){
    if (LEFT_JUSTIFIED == ADC->DATA_ALLIGNMENT_FORMAT){
        ADC_SET_DATA_LEFT_JUSTIFIED();
    }
    else{
        ADC_SET_DATA_RIGHT_JUSTIFIED();
    }
}

/**
 * @breif: helper function that gets the data according to the DATA_ALLIGNMENT_FORMAT
 *         member in the passed parameter ADC then uses the corresponding macro-like function
 * @param ADC
 */

static uint16 inline ADC_Get_Data(const ADC_CONFIG_t* ADC){
    if (LEFT_JUSTIFIED == ADC->DATA_ALLIGNMENT_FORMAT){
        return ADC_GET_DATA_LEFT_JUSTIFIED();
    }
    else{
        return ADC_GET_DATA_RIGHT_JUSTIFIED();
    }
}
#ifdef PRIORITY_FEATURE_ENABLED
static void inline ADC_Select_priority(Priority_t priority){
    if (PRIORITY_LOW == priority){
        ADC_INTERRUPT_PRIORITY_LOW();
    }
    else{
        ADC_INTERRUPT_PRIORITY_HIGH();
    }
}
#endif

#ifdef ADC_INTERRUPT_FEATURE_ENABLE

void ADC_ISR1(){
    ADC_INTERRUPT_FLAG_CLEAR();
//    led_toggle(&led);
    
    if (NULL != ADC_Interrupt_Handler){ADC_Interrupt_Handler();}
}
void ADC_ISR2(){
    ADC_INTERRUPT_FLAG_CLEAR();
//    led_toggle(&led);
    
    if (NULL != ADC_Interrupt_Handler){ADC_Interrupt_Handler();}
}
void ADC_ISR3(){
    ADC_INTERRUPT_FLAG_CLEAR();
//    led_toggle(&led);
    
    if (NULL != ADC_Interrupt_Handler){ADC_Interrupt_Handler();}
}
void ADC_ISR4(){
    ADC_INTERRUPT_FLAG_CLEAR();
//    led_toggle(&led);
    
    if (NULL != ADC_Interrupt_Handler){ADC_Interrupt_Handler();}
}

#endif