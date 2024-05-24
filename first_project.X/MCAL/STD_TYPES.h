/* 
 * File:   STD_TYPES.h
 * Author: Alaa
 *
 * Created on October 29, 2023, 1:47 PM
 */

#ifndef STD_TYPES_H
#define	STD_TYPES_H

/* includes section*/
#include "COMPILER.h"
#include "STD_LIBS.h"

/* macros definition section*/

#define STD_LOW         0
#define STD_HIGH        1

#define STD_OFF         0
#define STD_ON          1

#define E_OK             (Std_ReturnType)0
#define E_NOT_OK         (Std_ReturnType)1

#define STD_IDLE        0
#define STD_ACTIVE      1

/* Data types declarations*/

typedef unsigned char   uint8;
typedef uint8  Std_ReturnType;
typedef unsigned short uint16;
typedef unsigned long  uint32;
typedef signed char     sint8;
typedef signed short   sint16;
typedef signed long    sint32;


#endif	/* STD_TYPES_H */

