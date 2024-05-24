/* 
 * File:   chr_lcd.h
 * Author: Alaa
 *
 * Created on April 13, 2024, 6:20 PM
 */

#ifndef CHR_LCD_H
#define	CHR_LCD_H


#include "chr_lcd_cfg.h"
#include "../../MCAL_LAYER/GPIO/HAL_GPIO.h"

#define ROW1 1
#define ROW2 2
#define ROW3 3
#define ROW4 4


#define LCD_CLEAR                  0x01
#define LCD_RETURN_HOME            0x02
#define LCD_ENTRY_MODE             0x06
#define LCD_CURSOR_OFF_DISPLAY_ON  0x0C
#define LCD_CURSOR_OFF_DISPLAY_OFF 0x08
#define LCD_CURSOR_ON_BLINK_ON     0x0F
#define LCD_CURSOR_ON_BLINK_OFF    0x0E
#define LCD_CURSOR_ON_BLINK_OFF    0x0E
#define LCD_DISPLAY_SHIFT_RIGHT    0x1C
#define LCD_DISPLAY_SHIFT_LEFT     0x18
#define LCD_8BIT_MODE_2LINES       0x38
#define LCD_4BIT_MODE_2LINES       0x28
#define LCD_CGRAM_START            0x40
#define LCD_DDRAM_START            0x80



typedef struct {
    pin_config_t lcd_rs;
    pin_config_t lcd_en;
    pin_config_t lcd_data[4];
}chr_lcd_4bit_t;

typedef struct {
    pin_config_t lcd_rs;
    pin_config_t lcd_en;
    pin_config_t lcd_data[8];
}chr_lcd_8bit_t;


STD_ReturnType lcd_4bit_initialize(const chr_lcd_4bit_t * lcd);
STD_ReturnType lcd_4bit_send_command(const chr_lcd_4bit_t * lcd, uint8 command);
STD_ReturnType lcd_4bit_send_chr_data(const chr_lcd_4bit_t * lcd, uint8 data);
STD_ReturnType lcd_4bit_send_str_data(const chr_lcd_4bit_t * lcd, uint8 *str);
STD_ReturnType lcd_4bit_send_chr_data_position(const chr_lcd_4bit_t * lcd, uint8 data, uint8 row, uint8 column);
STD_ReturnType lcd_4bit_send_str_data_position(const chr_lcd_4bit_t * lcd, uint8 *str, uint8 row, uint8 column);
STD_ReturnType lcd_4bit_send_chr_custom_position(const chr_lcd_4bit_t * lcd, uint8 chr[], uint8 row, uint8 column, uint8 memory_position);

STD_ReturnType lcd_8bit_initialize(const chr_lcd_8bit_t * lcd);
STD_ReturnType lcd_8bit_send_command(const chr_lcd_8bit_t * lcd, uint8 command);
STD_ReturnType lcd_8bit_send_chr_data(const chr_lcd_8bit_t * lcd, uint8 data);
STD_ReturnType lcd_8bit_send_str_data(const chr_lcd_8bit_t * lcd, uint8 *str);
STD_ReturnType lcd_8bit_send_chr_data_position(const chr_lcd_8bit_t * lcd, uint8 data, uint8 row, uint8 column);
STD_ReturnType lcd_8bit_send_str_data_position(const chr_lcd_8bit_t * lcd, uint8 *str, uint8 row, uint8 column);
STD_ReturnType lcd_8bit_send_chr_custom_position(const chr_lcd_8bit_t * lcd, uint8 chr[], uint8 row, uint8 column, uint8 memory_position);

STD_ReturnType convert_int_to_str(uint32 number, uint8 *str);
STD_ReturnType convert_short_to_str(uint16 number, uint8 *str);
STD_ReturnType convert_byte_to_str(uint8 number , uint8 *str);


#endif	/* CHR_LCD_H */

