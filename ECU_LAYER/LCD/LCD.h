/* 
 * File:   LCD.h
 * Author: Alaa
 *
 * Created on March 20, 2024, 5:19 PM
 */

#ifndef LCD_H
#define	LCD_H

#include "LCD_CFG.h"

#define SEG_PIN_0 0
#define SEG_PIN_1 1
#define SEG_PIN_2 2
#define SEG_PIN_3 3

typedef enum{
    COMMON_ANODE,
    COMMON_CATHODE
}segment_t;

typedef struct{
    pin_config_t lcd_pins[4];
    segment_t segment_type;
}lcd_t;

STD_ReturnType lcd_init(lcd_t* lcd);
STD_ReturnType lcd_write(lcd_t* lcd, char number);


#endif	/* LCD_H */

