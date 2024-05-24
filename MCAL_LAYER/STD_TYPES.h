/* 
 * File:   STD_TYPES.h
 * Author: Alaa
 *
 * Created on February 20, 2024, 4:51 PM
 */

#ifndef STD_TYPES_H
#define	STD_TYPES_H

#ifdef	__cplusplus
extern "C" {
#endif

/* Includes section */

#include "STD_LIBS.h"
#include "COMPILER.h"

/* Macros section */
#define STD_HIGH        0X01
#define STD_LOW         0X00

#define TRUE            0X01
#define FALSE           0X00
    
#define STD_ON          0X01
#define STD_OFF         0X01

#define STD_ACTIVE      0X01
#define STD_IDLE        0X00

#define E_OK            (STD_ReturnType) 0x00
#define E_NOT_OK        (STD_ReturnType) 0X01

#define CONFIG_ENABLE   0x01
#define CONFIG_DISABLE  0x00
    
    
/* Marco-like functions section */
    
    
/* User defined datatype section */


//
//typedef union {
//struct {
//    unsigned LATC_REGISTER0 : 1;
//    unsigned LATC_REGISTER1 : 1;
//    unsigned LATC_REGISTER2 : 1;
//    unsigned LATC_REGISTER3 : 1;
//    unsigned LATC_REGISTER4 : 1;
//    unsigned LATC_REGISTER5 : 1;
//    unsigned LATC_REGISTER6 : 1;
//    unsigned LATC_REGISTER7 : 1;
//};
//uint8 LATC_REGISTER; 
//}LATC_REG;

typedef unsigned char uint8;
typedef signed char sint8;

typedef unsigned short uint16;
typedef signed short sint16;

typedef unsigned long  uint32;
typedef signed long  sint32;

typedef uint8 STD_ReturnType;



//typedef enum {
//    SPI_MASTER_MODE_FOSC_DIV_4,
//    SPI_MASTER_MODE_FOSC_DIV_16,
//    SPI_MASTER_MODE_FOSC_DIV_64,
//
//};
/* Function declaration section */


#ifdef	__cplusplus
}
#endif

#endif	/* STD_TYPES_H */

