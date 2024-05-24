/* 
 * File:   keypad.c
 * Author: Alaa
 *
 * Created on April 11, 2024, 3:23 PM
 */




/* Includes section */
#include "keypad.h"
/* Macros section */
/* Marco-like functions section */
/* User defined datatype section */
/* variable definition section */
keypad_t keypad = {

    .rows[0].PORT = PORTD_INDEX,.rows[0].PIN = PIN0,.rows[0].direction = OUTPUT, .rows[0].logic = LOW,
    .rows[1].PORT = PORTD_INDEX,.rows[1].PIN = PIN1,.rows[1].direction = OUTPUT, .rows[1].logic = LOW,
    .rows[2].PORT = PORTD_INDEX,.rows[2].PIN = PIN2,.rows[2].direction = OUTPUT, .rows[2].logic = LOW,
    .rows[3].PORT = PORTD_INDEX,.rows[3].PIN = PIN3,.rows[3].direction = OUTPUT, .rows[3].logic = LOW,
    
    .cols[0].PORT = PORTD_INDEX,.cols[0].PIN = PIN0,.cols[0].direction =  INPUT, 
    .cols[1].PORT = PORTD_INDEX,.cols[1].PIN = PIN1,.cols[1].direction =  INPUT, 
    .cols[2].PORT = PORTD_INDEX,.cols[2].PIN = PIN2,.cols[2].direction =  INPUT, 
    .cols[3].PORT = PORTD_INDEX,.cols[3].PIN = PIN3,.cols[3].direction =  INPUT,     
};
/* Function definition section */


uint8 keypad_buttons[KEYPAD_ROWS_NUMBER][KEYPAD_COLS_NUMBER] = {
    {'7', '8', '9', '/'},
    {'4', '5', '6', '*'},
    {'1', '2', '3', '-'},
    {'C', '0', '=', '+'}
};

STD_ReturnType keypad_init(const keypad_t *keypad){

    STD_ReturnType ret = E_NOT_OK;
    if (NULL == keypad){
        ret = E_NOT_OK;
    }
    else{
        uint8 row_counter = 0, column_counter = 0;
        for (row_counter = 0; row_counter < KEYPAD_ROWS_NUMBER; row_counter++){
            ret = gpio_pin_init(&(keypad->rows[row_counter]));
        }
        for (column_counter = 0; column_counter < KEYPAD_COLS_NUMBER; column_counter++){
            ret = gpio_pin_direction_init(&(keypad->rows[column_counter]));
        }        
    }
    return ret;    
}

STD_ReturnType keypad_read_value(const keypad_t *keypad, uint8 *value){

    STD_ReturnType ret = E_NOT_OK;
    if (NULL == keypad){
        ret = E_NOT_OK;
    }
    else{
        logic_t read_logic = LOW;
        uint8 row_counter = 0, column_counter = 0, temp_counter = 0;
        for (row_counter = 0; row_counter < KEYPAD_ROWS_NUMBER; row_counter++){
            for (temp_counter = 0; temp_counter < KEYPAD_ROWS_NUMBER; temp_counter++){
                ret = gpio_pin_logic_write(&(keypad->rows[temp_counter]), LOW);
            }
            ret = gpio_pin_logic_write(&(keypad->rows[row_counter]), HIGH);
            for (column_counter = 0; column_counter < KEYPAD_ROWS_NUMBER; column_counter++){
                ret = gpio_pin_logic_read(&(keypad->rows[column_counter]), &read_logic);
                if (HIGH == read_logic){
                    *value = keypad_buttons[row_counter][column_counter];
                }
            }
        }
    }
    return ret;        
}

