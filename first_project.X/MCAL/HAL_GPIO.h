/* 
 * File:   HAL_GPIO.h
 * Author: Alaa
 *
 * Created on October 29, 2023, 1:43 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/* includes section */

#include <pic18f4620.h>
#include "STD_TYPES.h"
#include "DEVICE_CONFIG.h"

/* Macros declaration */

#define MAX_PIN_NUMBER          8
#define MAX_PORT_NUMBER         5

/* Macro function declaration */

#define HWREG8(REG)                         *((volatile uint8 *)REG)
#define SET_BIT(REG,BIT_POSITION)           (*REG |=  (1 << BIT_POSITION)) 
#define TOGGLE_BIT(REG,BIT_POSITION)        (*REG ^=  (1 << BIT_POSITION)) 
#define CLEAR_BIT(REG,BIT_POSITION)         (*REG &= ~(1 << BIT_POSITION)) 
#define READ_BIT(REG,BIT_POSITION)          ((*REG) >> BIT_POSITION) 

/* data types definition */

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
    uint8 PORT  : 3;            /*@ref: port_index_t*/
    uint8 PIN   : 3;            /*@ref: pin_index_t*/ 
    uint8 dir   : 1;            /*@ref: direction_t*/ 
    uint8 logic : 1;            /*@ref: logic_t*/ 
}pin_config_t; 

/* function declaration */

Std_ReturnType gpio_pin_direction_initialize(const pin_config_t *_pin_config);
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config, direction_t *direction_status);
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config, logic_t logic);
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config, logic_t *logic);
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config);


Std_ReturnType gpio_port_direction_initialize(const port_index_t port, uint8 direction);
Std_ReturnType gpio_port_get_direction_status(const port_index_t port, uint8 *direction_status);
Std_ReturnType gpio_port_write_logic(const port_index_t port, uint8 logic);
Std_ReturnType gpio_port_read_logic(const port_index_t port, uint8 *logic);
Std_ReturnType gpio_port_toggle_logic(const port_index_t port);

#endif	/* HAL_GPIO_H */
