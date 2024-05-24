/* 
 * File:   HAL_GPIO.h
 * Author: Alaa
 *
 * Created on February 20, 2024, 4:33 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

#ifdef	__cplusplus
extern "C" {
#endif

/* Includes section */
#include <pic18f4620.h>
//#include "C:\Program Files\Microchip\MPLABX\v6.15\packs\Microchip\PIC18Fxxxx_DFP\1.4.151\xc8\pic\include\proc\pic18f4620.h"
#include "../STD_TYPES.h"
#include "../DEVICE_CONFIG.h"
#include "hal_gpio_cfg.h"
/* Macros section */
//#define LATC                            HWREG(0xF8B)
//#define TRISC                           HWREG(0xF94)
#define BIT_MASK                          (uint8) 1
/* Marco-like functions section */
    
#define SET_BIT(REG,BIT_POSITION)      (REG |= (1 << BIT_POSITION))
#define CLEAR_BIT(REG,BIT_POSITION)    (REG &= ~(1 << BIT_POSITION))
#define TOGGLE_BIT(REG,BIT_POSITION)   (REG ^= (1 << BIT_POSITION))
#define READ_BIT(REG,BIT_POSITION)     ((REG >> BIT_POSITION) & BIT_MASK )  
#define TOGGLE_PORT(PORT)              (PORT = ~PORT)
/* User defined datatype section */

typedef enum {
    LOW,
    HIGH
}logic_t;   

typedef enum {
    OUTPUT,
    INPUT
}direction_t;

typedef enum{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
}pin_index_t;

typedef enum{
    PORTA_INDEX,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX,
}port_index_t;

typedef struct{
    unsigned PORT      : 3;
    unsigned PIN       : 3;
    unsigned direction : 1;
    unsigned logic     : 1;
    
}pin_config_t;
/* Function declaration section */

STD_ReturnType gpio_pin_direction_init(const pin_config_t * pin); /* , direction_t direction */
STD_ReturnType gpio_pin_init(const pin_config_t * pin); 
STD_ReturnType gpio_pin_direction_get_status(const pin_config_t * pin, direction_t* direction );
STD_ReturnType gpio_pin_logic_write(const pin_config_t * pin,  logic_t logic );
STD_ReturnType gpio_pin_logic_read(const pin_config_t * pin,  logic_t * logic );
STD_ReturnType gpio_pin_logic_toggle(const pin_config_t * pin );

STD_ReturnType gpio_port_direction_init(port_index_t port, uint8 direction); 
STD_ReturnType gpio_port_direction_get_status(port_index_t port, uint8* port_logic); 
STD_ReturnType gpio_port_logic_write(port_index_t port, uint8 port_logic); 
STD_ReturnType gpio_port_logic_read(port_index_t port, uint8* port_logic); 
STD_ReturnType gpio_port_logic_toggle(port_index_t port); 

    
#ifdef	__cplusplus
}
#endif

#endif	/* HAL_GPIO_H */

