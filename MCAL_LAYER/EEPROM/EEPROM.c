/* 
 * File:   EEPROM.c
 * Author: Alaa
 *
 * Created on April 25, 2024, 9:04 AM
 */

/* Includes section */
#include "EEPROM.h"
#include "../interrupts/MCAL_INTERNAL_INTERRUPT.h"
#include <pic18f4620.h>
#include "../STD_TYPES.h"
/* Macros section */
/* Marco-like functions section */
/* User defined datatype section */
/* Function definition section */

/**
 * 
 * @param address
 * @param data
 * @return ret
 */
STD_ReturnType EEPROM_Write(uint16 address,uint8 data){
    STD_ReturnType ret = E_OK;
    SET_EEPROM_DATA_REGISTER(data);
    SET_EEPROM_ADDRESS_LOW(address);
    SET_EEPROM_ADDRESS_HIGH(address);
    CLEAR_EEPGD();
    CLEAR_CFGS();
    SET_WREN();
    
#ifdef PRIORITY_FEATURE_ENABLED
    uint8 Interrupt_High_Priority_Status = INTCONbits.GIEH;
    uint8 Interrupt_Low_Priority_Status  = INTCONbits.GIEL;
    INTERRUPT_PRIORITY_HIGH_DISABLE;
    INTERRUPT_PRIORITY_LOW_DISABLE;
#else 
    uint8 Interrupt_General_Status = INTCONbits.GIE;
    INTERRUPT_GENERAL_FEATURE_DISABLE;
#endif
    EEPROM_INITIALIZATION_SEQUENCE_START();
    SET_WR();
    while(EECON1bits.WR);
#ifdef PRIORITY_FEATURE_ENABLED
    if(INTERRUPT_ENABLED == Interrupt_High_Priority_Status){
        INTERRUPT_PRIORITY_HIGH_ENABLE;
    }
    else if(INTERRUPT_DISABLED == Interrupt_High_Priority_Status){
        INTERRUPT_PRIORITY_HIGH_DISABLE;
    }
    if(INTERRUPT_ENABLED == Interrupt_Low_Priority_Status){
        INTERRUPT_PRIORITY_LOW_ENABLE;
    }
    if(INTERRUPT_DISABLED == Interrupt_Low_Priority_Status){
        INTERRUPT_PRIORITY_LOW_DISABLE;
    }
    INTCONbits.GIEL;
#else 
    if(INTERRUPT_ENABLED == Interrupt_General_Status){
        INTERRUPT_GENERAL_FEATURE_ENABLE;
    }
    else if(INTERRUPT_DISABLED == Interrupt_General_Status){
        INTERRUPT_GENERAL_FEATURE_DISABLE;
    }
#endif
    CLR_WREN();
    return ret;
}

/**
 * 
 * @param address
 * @param data
 * @return ret
 */
STD_ReturnType EEPROM_Read(uint16 address,uint8 *data){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == data)
    {
        ret = E_NOT_OK;
    }
    else{
        SET_EEPROM_ADDRESS_HIGH(address);
        SET_EEPROM_ADDRESS_LOW(address);
        CLEAR_EEPGD();
        CLEAR_CFGS();
        SET_RD();
//        NOP();
//        NOP();
        while(1 == EECON1bits.RD);
        *data =  EEDATA;
        ret = E_OK;
    }
    return ret;
}