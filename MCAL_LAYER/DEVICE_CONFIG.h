/* 
 * File:   DEVICE_CONFIG.h
 * Author: Alaa
 *
 * Created on February 20, 2024, 5:09 PM
 */

#ifndef DEVICE_CONFIG_H
#define	DEVICE_CONFIG_H
#define _XTAL_FREQ 8000000.0

#ifdef	__cplusplus
extern "C" {
#endif

#define ARCHITECTURE_8BIT

#if defined ARCHITECTURE_8BIT
#define HWREG(REG)  *((volatile unsigned char*)REG)
#elif defined ARCHITECTURE_16BIT
#define HWREG(REG)  *((volatile unsigned short*)REG)
#elif defined ARCHITECTURE_32BIT
#define HWREG(REG)  *((volatile unsigned char*)REG)

#endif
/* Includes section */
/* Macros section */
/* Marco-like functions section */
/* User defined datatype section */
/* Function declaration section */

#ifdef	__cplusplus
}
#endif

#endif	/* DEVICE_CONFIG_H */

