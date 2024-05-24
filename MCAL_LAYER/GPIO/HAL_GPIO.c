/* 
 * File:   HAL_GPIO.c
 * Author: Alaa
 *
 * Created on February 20, 2024, 4:33 PM
 */
#include "HAL_GPIO.h"

#define MAX_PORT_NUMBER 5
#define MAX_PORT_PIN_NUMBER 8
volatile uint8* TRIS_REGISTERS[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
volatile uint8* LAT_REGISTERS[] = {&LATA, &LATB, &LATC, &LATD, &LATE};
volatile uint8* PORT_REGISTERS[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};


#if GPIO_PIN_CONFIG == CONFIG_ENABLE

/**
 * 
 * @param pin 
 * @return status of the function
 *              E_OK    : function completed successfully
 *              E_NOT_OK: function didn't complete successfully
 */

STD_ReturnType gpio_pin_direction_init(const pin_config_t * pin){
    
    STD_ReturnType ret = E_OK;
//    int x = 5555;
//    TRISC = 0x80;
    
//    x = 10;
//    *((volatile uint8 *)0xF94) = 0x55;
    if (NULL == pin || pin->PORT > MAX_PORT_NUMBER - 1  || pin->PIN > MAX_PORT_PIN_NUMBER - 1 )
    {
        ret = E_NOT_OK;
    }
    else{
        switch (pin->direction){
            case OUTPUT:
                
                CLEAR_BIT(*(TRIS_REGISTERS[pin->PORT]),pin->PIN);
                break;
            case INPUT:
                SET_BIT(*(TRIS_REGISTERS[pin->PORT]),pin->PIN);
                break;
            default:
                ret = E_NOT_OK;
//                x =10;
        }
    }

 
    return ret;
    
}

/**
 * 
 * @param pin
 * @param direction 
 * @return status of the function
 *              E_OK    : function completed successfully
 *              E_NOT_OK: function didn't complete successfully
 */

STD_ReturnType gpio_pin_direction_get_status(const pin_config_t * pin, direction_t* direction ){
    
    STD_ReturnType ret = E_OK;
    
    if (NULL == pin || NULL == direction  || pin->PORT > MAX_PORT_NUMBER - 1  || pin->PIN > MAX_PORT_PIN_NUMBER - 1  )
    {
        ret = E_NOT_OK;
    }  
    else
    {
        *direction = READ_BIT(*(TRIS_REGISTERS[pin->PORT]), pin->PIN);
    }
    
   
    return ret;
}

/**
 * 
 * @param pin
 * @param logic
 * @return status of the function
 *              E_OK    : function completed successfully
 *              E_NOT_OK: function didn't complete successfully
 */


STD_ReturnType gpio_pin_logic_write(const pin_config_t * pin,  logic_t logic ){
    
    STD_ReturnType ret = E_OK;
    if (NULL == pin  || pin->PORT > MAX_PORT_NUMBER - 1 || pin->PIN > MAX_PORT_PIN_NUMBER - 1  )
    {
        ret = E_NOT_OK;
    }  
    else
    {
        switch (logic){
            case HIGH:
//                pin->logic = HIGH;
                SET_BIT(*(LAT_REGISTERS[pin->PORT]),pin->PIN);
                break;
            case LOW:
//                pin->logic = LOW;
                CLEAR_BIT(*(LAT_REGISTERS[pin->PORT]),pin->PIN);
                break;
            default:
                ret = E_NOT_OK;
        }
    }
    
    return ret;
}

/**
 * 
 * @param pin
 * @param logic
 * @return status of the function
 *              E_OK    : function completed successfully
 *              E_NOT_OK: function didn't complete successfully
 */

STD_ReturnType gpio_pin_logic_read(const pin_config_t * pin,  logic_t * logic ){
    
    STD_ReturnType ret = E_OK;
    
    if (NULL == pin || NULL == logic  || pin->PORT > MAX_PORT_NUMBER - 1  || pin->PIN > MAX_PORT_PIN_NUMBER - 1  )
    {
        ret = E_NOT_OK;
    }  
    else
    {
        *logic = READ_BIT(*(PORT_REGISTERS[pin->PORT]), pin->PIN);
    }
    
   
    return ret;
}

/**
 * 
 * @param pin
 * @return status of the function
 *              E_OK    : function completed successfully
 *              E_NOT_OK: function didn't complete successfully
 */

STD_ReturnType gpio_pin_logic_toggle(const pin_config_t * pin ){
    
    STD_ReturnType ret = E_OK;
    logic_t logic;
    if (NULL == pin  || pin->PORT > MAX_PORT_NUMBER - 1 || pin->PIN > MAX_PORT_PIN_NUMBER - 1 )
    {
        ret = E_NOT_OK;
    }  
    else
    {
        TOGGLE_BIT(*(LAT_REGISTERS[pin->PORT]), pin->PIN);
       
    }
    
    
    return ret;
}

STD_ReturnType gpio_pin_init(const pin_config_t * pin){
    
{
    
    STD_ReturnType ret = E_OK;
    
    if (NULL == pin || pin->PORT > MAX_PORT_NUMBER - 1  || pin->PIN > MAX_PORT_PIN_NUMBER - 1  )
    {
        ret = E_NOT_OK;
    }  
    else
    {
        gpio_pin_direction_init(pin);
        gpio_pin_logic_write(pin, LOW);
    }
    
    return ret;
}
    
}


#endif

#if GPIO_PORT_CONFIG == CONFIG_ENABLE
/**
 * 
 * @param port
 * @param direction
 * @return status of the function
 *              E_OK    : function completed successfully
 *              E_NOT_OK: function didn't complete successfully
 */

STD_ReturnType gpio_port_direction_init(port_index_t port, uint8 direction){
    
    STD_ReturnType ret = E_OK;
    
    if ( port > MAX_PORT_NUMBER - 1 )
    {
        ret = E_NOT_OK;
    }  
    else
    {
        *TRIS_REGISTERS[port] = direction;
    }
    
    
    return ret;
}

/**
 * 
 * @param port
 * @param port_direction
 * @return status of the function
 *              E_OK    : function completed successfully
 *              E_NOT_OK: function didn't complete successfully
 */

STD_ReturnType gpio_port_direction_get_status(port_index_t port, uint8* port_direction){
    
    STD_ReturnType ret = E_OK;
    
    if ( port > MAX_PORT_NUMBER - 1 || NULL == port_direction)
    {
        ret = E_NOT_OK;
    }  
    else
    {
        *port_direction = *TRIS_REGISTERS[port];
    }   
    
    
    return ret;
}

/**
 * 
 * @param port
 * @param port_logic
 * @return status of the function
 *              E_OK    : function completed successfully
 *              E_NOT_OK: function didn't complete successfully
 */

STD_ReturnType gpio_port_logic_write(port_index_t port, uint8 port_logic){
    
    STD_ReturnType ret = E_OK;
    
    if ( port > MAX_PORT_NUMBER - 1 )
    {
        ret = E_NOT_OK;
    }  
    else
    {
        *LAT_REGISTERS[port] = port_logic;
    }
    
    
    return ret;
}

/**
 * 
 * @param port
 * @param port_logic
 * @return status of the function
 *              E_OK    : function completed successfully
 *              E_NOT_OK: function didn't complete successfully
 */

STD_ReturnType gpio_port_logic_read(port_index_t port, uint8* port_logic){
    
    STD_ReturnType ret = E_OK;
    
    if ( port > MAX_PORT_NUMBER - 1 || NULL == port_logic)
    {
        ret = E_NOT_OK;
    }  
    else
    {
        *port_logic = *PORT_REGISTERS[port];
    }
    
    
    return ret;
}

/**
 * 
 * @param port
 * @return status of the function
 *              E_OK    : function completed successfully
 *              E_NOT_OK: function didn't complete successfully
 */

STD_ReturnType gpio_port_logic_toggle(port_index_t port){
    
    STD_ReturnType ret = E_OK;
    
    if ( port > MAX_PORT_NUMBER - 1 )
    {
        ret = E_NOT_OK;
    }  
    else
    {
        TOGGLE_PORT(*LAT_REGISTERS[port]);
    }
       
    
    
    return ret;
}

#endif
    