/* 
 * File:   EEPROM.c
 * Author: Alaa
 *
 * Created on April 25, 2024, 9:04 AM
 */

#ifndef EEPROM_H
#define	EEPROM_H
/* Includes section */
#include "../interrupts/MCAL_INTERNAL_INTERRUPT.h"
#include <pic18f4620.h>
#include "../STD_TYPES.h"
/* Macros section */

/* Marco-like functions section */

#define CLEAR_EEPGD()                            EECON1bits.EEPGD     = 0
#define SET_EEPROM_DATA_REGISTER(data)           EEDATA               = data
#define SET_EEPROM_ADDRESS_LOW(address)          EEADR                = (uint8) (address & 0xFF)
#define SET_EEPROM_ADDRESS_HIGH(address)         EEADRH               = (uint8) ((address >> 8) & 0x03)
#define CLEAR_CFGS()                             EECON1bits.CFGS      = 0
#define SET_RD()                                 EECON1bits.RD        = 1
#define SET_WREN()                               EECON1bits.WREN      = 1
#define CLR_WREN()                               EECON1bits.WREN      = 0
#define SET_WR()                                 EECON1bits.WR        = 1
#define EEPROM_INITIALIZATION_SEQUENCE_START()   EECON2 = 0x55;EECON2 = 0xAA;
/* User defined datatype section */
/* Function declaration section */

STD_ReturnType EEPROM_Read(uint16 address,uint8 *data);
STD_ReturnType EEPROM_Write(uint16 address,uint8 data);

#endif	/* EEPROM_H */


