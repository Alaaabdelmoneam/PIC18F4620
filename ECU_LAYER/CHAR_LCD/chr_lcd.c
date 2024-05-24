/* 
 * File:   chr_lcd.c
 * Author: Alaa
 *
 * Created on April 13, 2024, 6:20 PM
 */


#include "chr_lcd.h"

static STD_ReturnType lcd_send_8bits(chr_lcd_8bit_t *lcd, uint8 data_command);
static STD_ReturnType lcd_send_4bits(chr_lcd_4bit_t *lcd, uint8 data_command);
static STD_ReturnType lcd_8bits_send_enable(chr_lcd_8bit_t *lcd);
static STD_ReturnType lcd_4bits_send_enable(chr_lcd_4bit_t *lcd);

static STD_ReturnType lcd_4bits_set_cursor(chr_lcd_4bit_t *lcd, uint8 row, uint8 column);
static STD_ReturnType lcd_8bits_set_cursor(chr_lcd_8bit_t *lcd, uint8 row, uint8 column);

chr_lcd_4bit_t lcd1 = {
    .lcd_rs.PORT = PORTC_INDEX, .lcd_rs.PIN = PIN2, .lcd_rs.direction = OUTPUT, .lcd_rs.logic = LOW,
    .lcd_en.PORT = PORTC_INDEX, .lcd_en.PIN = PIN3, .lcd_en.direction = OUTPUT, .lcd_en.logic = LOW,
    .lcd_data[0].PORT = PORTD_INDEX, .lcd_data[0].PIN = PIN0, .lcd_data[0].direction = OUTPUT, .lcd_data[0].logic = LOW,
    .lcd_data[1].PORT = PORTD_INDEX, .lcd_data[1].PIN = PIN1, .lcd_data[1].direction = OUTPUT, .lcd_data[1].logic = LOW,
    .lcd_data[2].PORT = PORTD_INDEX, .lcd_data[2].PIN = PIN2, .lcd_data[2].direction = OUTPUT, .lcd_data[2].logic = LOW,
    .lcd_data[3].PORT = PORTD_INDEX, .lcd_data[3].PIN = PIN3, .lcd_data[3].direction = OUTPUT, .lcd_data[3].logic = LOW,
};

chr_lcd_8bit_t lcd2 = {
    .lcd_rs.PORT = PORTC_INDEX, .lcd_rs.PIN = PIN6, .lcd_rs.direction = OUTPUT, .lcd_rs.logic = LOW,
    .lcd_en.PORT = PORTC_INDEX, .lcd_en.PIN = PIN7, .lcd_en.direction = OUTPUT, .lcd_en.logic = LOW,
    .lcd_data[0].PORT = PORTD_INDEX, .lcd_data[0].PIN = PIN0, .lcd_data[0].direction = OUTPUT, .lcd_data[0].logic = LOW,
    .lcd_data[1].PORT = PORTD_INDEX, .lcd_data[1].PIN = PIN1, .lcd_data[1].direction = OUTPUT, .lcd_data[1].logic = LOW,
    .lcd_data[2].PORT = PORTD_INDEX, .lcd_data[2].PIN = PIN2, .lcd_data[2].direction = OUTPUT, .lcd_data[2].logic = LOW,
    .lcd_data[3].PORT = PORTD_INDEX, .lcd_data[3].PIN = PIN3, .lcd_data[3].direction = OUTPUT, .lcd_data[3].logic = LOW,
    .lcd_data[4].PORT = PORTD_INDEX, .lcd_data[4].PIN = PIN4, .lcd_data[4].direction = OUTPUT, .lcd_data[4].logic = LOW,
    .lcd_data[5].PORT = PORTD_INDEX, .lcd_data[5].PIN = PIN5, .lcd_data[5].direction = OUTPUT, .lcd_data[5].logic = LOW,
    .lcd_data[6].PORT = PORTD_INDEX, .lcd_data[6].PIN = PIN6, .lcd_data[6].direction = OUTPUT, .lcd_data[6].logic = LOW,
    .lcd_data[7].PORT = PORTD_INDEX, .lcd_data[7].PIN = PIN7, .lcd_data[7].direction = OUTPUT, .lcd_data[7].logic = LOW,
};



STD_ReturnType lcd_4bit_initialize(const chr_lcd_4bit_t * lcd){
    STD_ReturnType ret = E_OK;
    if (NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_init(&(lcd->lcd_rs));
        ret = gpio_pin_init(&(lcd->lcd_en));
        for (uint8 counter = 0; counter < 4 ; counter++){
            ret = gpio_pin_init(&(lcd->lcd_data[counter]));
        }
        __delay_ms(20);
        lcd_4bit_send_command(lcd, LCD_8BIT_MODE_2LINES);
        __delay_ms(5);
        lcd_4bit_send_command(lcd, LCD_8BIT_MODE_2LINES);
        __delay_us(50);
        lcd_4bit_send_command(lcd, LCD_8BIT_MODE_2LINES);
        lcd_4bit_send_command(lcd, LCD_CLEAR);
        lcd_4bit_send_command(lcd, LCD_RETURN_HOME);
        lcd_4bit_send_command(lcd, LCD_ENTRY_MODE);
        lcd_4bit_send_command(lcd, LCD_CURSOR_OFF_DISPLAY_ON);
        lcd_4bit_send_command(lcd, LCD_4BIT_MODE_2LINES);
        lcd_4bit_send_command(lcd, 0x80);
    }
    return ret;
}

STD_ReturnType lcd_4bit_send_command(const chr_lcd_4bit_t * lcd, uint8 command){
    STD_ReturnType ret = E_OK;
    if (NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_logic_write(&(lcd->lcd_rs),LOW);
        ret = lcd_send_4bits(lcd,command >> 4);
        ret = lcd_4bits_send_enable(lcd);
        ret = lcd_send_4bits(lcd,command);
        ret = lcd_4bits_send_enable(lcd);
    }
    return ret;
}

STD_ReturnType lcd_4bit_send_chr_data(const chr_lcd_4bit_t * lcd, uint8 data){
    STD_ReturnType ret = E_OK;
    if (NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_logic_write(&(lcd->lcd_rs),HIGH);
        ret = lcd_send_4bits(lcd,data >> 4);
        ret = lcd_4bits_send_enable(lcd);
        ret = lcd_send_4bits(lcd,data);
        ret = lcd_4bits_send_enable(lcd);
    }
    return ret;
}

STD_ReturnType lcd_4bit_send_str_data(const chr_lcd_4bit_t * lcd, uint8 *str){
    STD_ReturnType ret = E_OK;
    if (NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        while(*str){
            lcd_4bit_send_chr_data(lcd,*str++);
        }
    }
    return ret;
}

STD_ReturnType lcd_4bit_send_chr_data_position(const chr_lcd_4bit_t * lcd, uint8 data, uint8 row, uint8 column){
    STD_ReturnType ret = E_OK;
    if (NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        ret = lcd_4bits_set_cursor(lcd,row,column);
        ret = lcd_4bit_send_chr_data(lcd,data);
    }
    return ret;
}

STD_ReturnType lcd_4bit_send_str_data_position(const chr_lcd_4bit_t * lcd, uint8 *str, uint8 row, uint8 column){
    STD_ReturnType ret = E_OK;
    if (NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        ret = lcd_4bits_set_cursor(lcd,row,column);
        ret = lcd_4bit_send_str_data(lcd,str);
    }
    return ret;

}

STD_ReturnType lcd_4bit_send_chr_custom_position(const chr_lcd_4bit_t * lcd, uint8 chr[], uint8 row, uint8 column, uint8 memory_position){
    STD_ReturnType ret = E_OK;
    uint8 l_counter = 0;
    if (NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        ret = lcd_4bits_set_cursor(lcd,row,column);
        ret = lcd_4bit_send_command(lcd,LCD_CGRAM_START + 8 * memory_position);
        for (l_counter = 0; l_counter < 8; l_counter++){
            lcd_4bit_send_chr_data(lcd,chr[l_counter]);
        }
        ret = lcd_4bit_send_chr_data_position(lcd,memory_position, row, column);
    }
    return ret;

}


STD_ReturnType lcd_8bit_initialize(const chr_lcd_8bit_t * lcd){
    STD_ReturnType ret = E_OK;
    if (NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_init(&(lcd->lcd_rs));
        ret = gpio_pin_init(&(lcd->lcd_en));
        for (uint8 counter = 0; counter < 8 ; counter++){
            ret = gpio_pin_init(&(lcd->lcd_data[counter]));
        }
        __delay_ms(20);
        lcd_8bit_send_command(lcd, LCD_8BIT_MODE_2LINES);
        __delay_ms(5);
        lcd_8bit_send_command(lcd, LCD_8BIT_MODE_2LINES);
        __delay_us(50);
        lcd_8bit_send_command(lcd, LCD_8BIT_MODE_2LINES);
        lcd_8bit_send_command(lcd, LCD_CLEAR);
        lcd_8bit_send_command(lcd, LCD_RETURN_HOME);
        lcd_8bit_send_command(lcd, LCD_ENTRY_MODE);
        lcd_8bit_send_command(lcd, LCD_CURSOR_OFF_DISPLAY_ON);
        lcd_8bit_send_command(lcd, LCD_8BIT_MODE_2LINES);
        lcd_8bit_send_command(lcd, 0x80);
        
        
        
    }
    return ret;

}

STD_ReturnType lcd_8bit_send_command(const chr_lcd_8bit_t * lcd, uint8 command){
    STD_ReturnType ret = E_OK;
    if (NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_logic_write(&(lcd->lcd_rs),LOW);
        ret = lcd_send_8bits(lcd,command);
        ret = lcd_8bits_send_enable(lcd);
    }
    return ret;

}

STD_ReturnType lcd_8bit_send_chr_data(const chr_lcd_8bit_t * lcd, uint8 data){
    STD_ReturnType ret = E_OK;
    if (NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_logic_write(&(lcd->lcd_rs),HIGH);
        ret = lcd_send_8bits(lcd,data);
        ret = lcd_8bits_send_enable(lcd);
    }
    return ret;

}

STD_ReturnType lcd_8bit_send_str_data(const chr_lcd_8bit_t * lcd, uint8 *str){
    STD_ReturnType ret = E_OK;
    if (NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        while(*str){
            lcd_8bit_send_chr_data(lcd,*str++);
        }
    }
    return ret;

}

STD_ReturnType lcd_8bit_send_chr_data_position(const chr_lcd_8bit_t * lcd, uint8 data, uint8 row, uint8 column){
    STD_ReturnType ret = E_OK;
    if (NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        ret = lcd_8bits_set_cursor(lcd, row, column);
        ret = lcd_8bit_send_chr_data(lcd,data);
    }
    return ret;

}

STD_ReturnType lcd_8bit_send_str_data_position(const chr_lcd_8bit_t * lcd, uint8 *str, uint8 row, uint8 column){
    STD_ReturnType ret = E_OK;
    if (NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        ret = lcd_8bits_set_cursor(lcd,row,column);
        while(*str){
            lcd_8bit_send_chr_data(lcd,*str++);
        }    }
    return ret;

}

STD_ReturnType lcd_8bit_send_chr_custom_position(const chr_lcd_8bit_t * lcd, uint8 chr[], uint8 row, uint8 column, uint8 memory_position){
    STD_ReturnType ret = E_OK;
    uint8 l_counter = 0;
    if (NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        ret = lcd_8bit_send_command(lcd,LCD_CGRAM_START + 8 * memory_position);
        for (l_counter = 0; l_counter < 8; l_counter++){
            lcd_8bit_send_chr_data(lcd,chr[l_counter]);
        }
        ret = lcd_8bit_send_chr_data_position(lcd,memory_position, row, column);
    }
    return ret;

}

static STD_ReturnType lcd_send_4bits(chr_lcd_4bit_t *lcd, uint8 data_command){
    STD_ReturnType ret;
    for (uint8 counter = 0; counter < 4 ; counter++){
        ret = gpio_pin_logic_write(&(lcd->lcd_data[counter]),(data_command >> counter) & (uint8)0x01);
    }
    return ret;

}

static STD_ReturnType lcd_send_8bits(chr_lcd_8bit_t *lcd, uint8 data_command){
    STD_ReturnType ret;
    for (uint8 counter = 0; counter < 8 ; counter++){
        ret = gpio_pin_logic_write(&(lcd->lcd_data[counter]),(data_command >> counter) & (uint8)0x01);
    }
    return ret;

}

static STD_ReturnType lcd_4bits_send_enable(chr_lcd_4bit_t *lcd){
    STD_ReturnType ret;
    ret = gpio_pin_logic_write(&(lcd->lcd_en), HIGH);
    __delay_us(5);
    ret = gpio_pin_logic_write(&(lcd->lcd_en), LOW);
    return ret;
}

static STD_ReturnType lcd_8bits_send_enable(chr_lcd_8bit_t *lcd){
    STD_ReturnType ret;
    ret = gpio_pin_logic_write(&(lcd->lcd_en), HIGH);
    __delay_us(5);
    ret = gpio_pin_logic_write(&(lcd->lcd_en), LOW);
    return ret;
}

static STD_ReturnType lcd_8bits_set_cursor(chr_lcd_8bit_t *lcd, uint8 row, uint8 column){
    STD_ReturnType ret;
    
    switch (row){
        case ROW1:
            lcd_8bit_send_command(lcd, 0x80 + column); break;
        case ROW2:
            lcd_8bit_send_command(lcd, 0xc0 + column); break;
        case ROW3:
            lcd_8bit_send_command(lcd, 0x94 + column); break;
        case ROW4:
            lcd_8bit_send_command(lcd, 0xd4 + column); break;
        default:;
    }
    return ret;
}

static STD_ReturnType lcd_4bits_set_cursor(chr_lcd_4bit_t *lcd, uint8 row, uint8 column){
    STD_ReturnType ret;
    
    switch (row){
        case ROW1:
            lcd_4bit_send_command(lcd, 0x80 + column); break;
        case ROW2:
            lcd_4bit_send_command(lcd, 0xc0 + column); break;
        case ROW3:
            lcd_4bit_send_command(lcd, 0x94 + column); break;
        case ROW4:
            lcd_4bit_send_command(lcd, 0xd4 + column); break;
        default:;
    }
    
    return ret;
}


STD_ReturnType convert_int_to_str(uint32 number, uint8 *str){
    STD_ReturnType ret = E_OK;
    if (NULL == str){
        ret = E_NOT_OK;
    }
    else{
        memset(str, '\0', 4);
        sprintf(str, "%i", number);
    }
    return ret;
}

STD_ReturnType convert_short_to_str(uint16 number, uint8 *str){ /* modified to overwrite */
    STD_ReturnType ret = E_OK;
    uint8 tmp_str[6] = {0};
    uint8 counter = 0;
    if (NULL == str){
        ret = E_NOT_OK;
    }
    else{
        memset(str, ' ', 5);
        str[5] = '\0';
        sprintf((char *)tmp_str, "%i", number);
        while('\0' != tmp_str[counter]){
            str[counter] = tmp_str[counter];
            counter++;
        }
    }
    return ret;
}

STD_ReturnType convert_byte_to_str(uint8 number , uint8 *str){
    STD_ReturnType ret = E_OK;
    if (NULL == str){
        ret = E_NOT_OK;
    }
    else{
        memset(str, '\0', 11);
        sprintf(str, "%i", number);
    }
    return ret;
}

