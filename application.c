/* 
 * File:   application.c
 * Author: Alaa
 *
 * Created on February 20, 2024, 4:10 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "application.h"
#include "ECU_LAYER/RELAY/RELAY.h"
#include "ECU_LAYER/LCD/LCD.h"
#include "MCAL_LAYER/TIMER2/timer2.h"
#include "MCAL_LAYER/TIMER3/timer3.h"
#include <string.h>
#include <math.h>











volatile uint16 var = 0;
volatile uint32 freq = 0;
//led_t led = {

//    .PIN = PIN0, .PORT = PORTC_INDEX, .state = LOW
//};
//
pin_config_t pin = {
    .PIN = PIN0, .PORT = PORTC_INDEX, .direction = INPUT,
};
pin_config_t pin1 = {
    .PIN = PIN4, .PORT = PORTA_INDEX, .direction = OUTPUT, .logic = LOW
};
pin_config_t pin2 = {
    .PIN = PIN4, .PORT = PORTC_INDEX, .direction = OUTPUT, .logic = HIGH
};

void led_toggle_callback(void){
    var++;
    if(var % 2 == 0){
        gpio_pin_logic_toggle(&pin2);
        var = 0;
    }
//    gpio_pin_logic_toggle(&pin);
//    
//
//    if (0 == var % 10 ){
//        var = 0;
//        gpio_pin_logic_toggle(&pin);
//    }

}
void freq_calc(void){
    freq = TMR0L + 256*var;
    TMR0L = 0;
    var = 0;
}
//timer0_t timer0 = {
//    .Interrupt_Handler = led_toggle_callback,
//    .counter_mode = TRUE,
//    .counter_rising_edge = TRUE,
//    .prescaler_enable = FALSE,
//    .prescaler_value = PRESCALER_FREQ_DIV_256,
//    .timer_8bit_mode = FALSE,
//    .preload_value = 0,
//};
//
// 

//
//void timer1_init_timer(void){
//    Timer1_t timer1;
//    timer1.Interrupt_Handler = led_toggle_callback;
////    timer1.priority = ;
////    timer1.oscillator_status = TIMER1_OSC_ENABLED;
//    timer1.preloaded_value = 0;
//    timer1.prescaler_value = TIMER1_PRESCALER_FREQ_DIV_8;
//    timer1.timer_bit_operation_mode = TIMER1_READ_WRITE_8_BIT;
//    timer1.timer_or_counter_mode = TIMER1_TIMER_MODE_ENABLED;
//    Timer1_Init(&timer1);
////    timer1.counter_mode_synchronization_status = ;
//}
//
void timer1_init_counter(void){
    Timer1_t timer1;
    timer1.Interrupt_Handler = NULL;
//    timer1.priority = PRIORITY_LOW;
//    timer1.oscilator_status = TIMER1_OSC_ENABLED;
    timer1.preloaded_value = 0;
    timer1.prescaler_value = TIMER1_PRESCALER_FREQ_DIV_1;
    timer1.timer_bit_operation_mode = TIMER1_READ_WRITE_16_BIT;
    timer1.timer_or_counter_mode = TIMER1_COUNTER_MODE_ENABLED;
    timer1.counter_mode_synchronization_status = TIMER1_COUNTER_MODE_SYNCHRONIZED;
    Timer1_Init(&timer1);
}

void timer2_init(void){
    Timer2_t timer;
    timer.Interrupt_Handler = led_toggle_callback;
    timer.postscaler_value  = TIMER2_POSTSCALER_FREQ_DIV_1;
    timer.prescaler_value   = TIMER2_PRESCALER_FREQ_DIV_1;
    timer.preloaded_value   = 0x00;
    Timer2_Init(&timer);
}


void timer3_init(void){
    Timer3_t timer;
    timer.Interrupt_Handler = led_toggle_callback;
    timer.prescaler_value   = TIMER3_PRESCALER_FREQ_DIV_1;
    timer.preloaded_value   = 64000;
    timer.counter_mode_synchronization_status = TIMER3_COUNTER_MODE_UNSYNCHRONIZED;
    timer.timer1_timer3_CCP_enables = TIMER1_CCP1_CCP2;
    timer.timer_bit_operation_mode = TIMER3_READ_WRITE_8_BIT;
    timer.timer_or_counter_mode = TIMER3_COUNTER_MODE_ENABLED;

    Timer3_Init(&timer);
}

int main(int argc, char** argv) {
    STD_ReturnType ret = E_NOT_OK;
//    timer1_init_counter();
//    led_initialize(&led);
    gpio_pin_init(&pin);
    gpio_pin_init(&pin1);
    gpio_pin_init(&pin2);
    gpio_pin_logic_write(&pin2,HIGH);
//    timer2_init();
    timer3_init();
//    Timer0_Init(&timer0);
//    TIMER0_ENABLE_8_bit();
//    Timer0_Write(&timer0,1000);
//    Timer0_Read(&timer0,&var);
    while(TRUE){
//        freq = TMR0L + 256*var;
//        TMR0L = 0;
//        var = 0;
//        __delay_ms(1000);
//      

    }
    return (EXIT_SUCCESS);
}














//void ADC_CallBack(void){
//    STD_ReturnType ret = E_NOT_OK;
////    led_toggle(&led);
////    var++;
//    switch(req){
//        case 0:
//            ret = ADC_Get_Conversion_Data(&ADC_1,&data1);
//            break;
//        case 1:
//            ret = ADC_Get_Conversion_Data(&ADC_1,&data2);
//            break;
////        case 2:
////            ret = ADC_Get_Conversion_Data(&ADC_1,&data3);
////            break;
////        case 3:
////            ret = ADC_Get_Conversion_Data(&ADC_1,&data4);
////            break;
//        case 2:
//            ret = ADC_Get_Conversion_Data(&ADC_1,&data3);
//            data3 =  (uint8)((((float)data3)/10.0f)*4.88f) ;
//            if (data3 < 20 ){motor_turn_right(&motor_1);}
//            else if((data3 >= 20 ) && (data3 < 30)){motor_turn_left(&motor_1);}
//            else{motor_turn_off(&motor_1);}
//            break;
//        case 3:
//            ret = ADC_Get_Conversion_Data(&ADC_1,&data4);
//            data4 =  (uint8)((((float)data4)/10.0f)*4.88f) ;
//            if (data4 < 20 ){motor_turn_left(&motor_2);}
//            else if((data4 >= 20 ) && (data4 < 30)){motor_turn_right(&motor_2);}
//            else{motor_turn_off(&motor_2);} 
//            break;
//        default:{/* Nothing */};
//    }
//    
//}




//    while(1){
//        for (char tens_number = 0; tens_number < 10; tens_number++){
//            ret = gpio_port_logic_write(PORTC_INDEX, seven_segment_number_codes[tens_number]);
//            for (char unit_number = 0; unit_number < 10; unit_number++){
//            ret = gpio_port_logic_write(PORTD_INDEX, seven_segment_number_codes[unit_number]);
//            __delay_ms(250);
//            }
//            __delay_ms(250);
//        }
//    }
//    
//    STD_ReturnType ret = E_NOT_OK;
//    ret = motor_initialize(&motor1);
//    ret = motor_initialize(&motor2);
//    
//    while(1){
//        ret = motor_turn_right(&motor1);
//        ret = motor_turn_right(&motor2);
//        __delay_ms(3000);
//        ret = motor_turn_left(&motor1);
//        ret = motor_turn_left(&motor2);
//        __delay_ms(3000);
//        ret = motor_turn_off(&motor1);
//        ret = motor_turn_off(&motor2);
//        __delay_ms(3000);
//        ret = motor_turn_right(&motor1);
//        ret = motor_turn_left(&motor2);
//        __delay_ms(3000);
//        ret = motor_turn_left(&motor1);
//        ret = motor_turn_right(&motor2);
//        __delay_ms(3000);
//        ret = motor_turn_off(&motor1);
//        ret = motor_turn_off(&motor2);
//        __delay_ms(3000);
//    }

    //motor_t motor1 = {
//    .motor_pins[0].port = PORTC_INDEX,
//    .motor_pins[0].pin = PIN0,
//    .motor_pins[0].logic = LOW,
//    .motor_pins[0].motor_index = 0,
//    
//    .motor_pins[1].port = PORTC_INDEX,
//    .motor_pins[1].pin = PIN1,
//    .motor_pins[1].logic = LOW,
//    .motor_pins[1].motor_index = 0,
//    
//    
//};
//
//motor_t motor2 = {
//    .motor_pins[0].port = PORTC_INDEX,
//    .motor_pins[0].pin = PIN2,
//    .motor_pins[0].logic = LOW,
//    .motor_pins[0].motor_index = 1,
//
//    .motor_pins[1].port = PORTC_INDEX,
//    .motor_pins[1].pin = PIN3,
//    .motor_pins[1].logic = LOW,
//    .motor_pins[1].motor_index = 1,
//
//    
//};


//    while(1){
//        for (char counter = 0; counter < 10; counter++){
//            ret = gpio_port_logic_write(PORTC_INDEX, counter);
//            __delay_ms(250);
//        }
//    }


/*decimal number */
//        for (char counter = 0; counter < 100; counter++){
//            ret = gpio_port_logic_write(PORTC_INDEX, (counter % 10)<< 4 |  (counter / 10) );
//            __delay_ms(250);
//        }


//keypad_init(&keypad);
//    uint8 value = 0;
//    while(1){
//        keypad_read_value(&keypad, &value);
//    }
//    lcd_t lcd1 = {
//    .segment_type = COMMON_CATHODE,
//    .lcd_pins = {pin0, pin1, pin2, pin3}
//    };
//    STD_ReturnType ret = E_NOT_OK;
//    lcd_init(&lcd1);
//    while(1){
//        
//    }




/**
 * main EEPROM
 */
//    STD_ReturnType ret;
//    ret = EEPROM_Write(0x3FF,0x55);
//
//
//    while(1){
//        ret = EEPROM_Write(counter,counter);
//        __delay_ms(1000);
//        ret = EEPROM_Read(counter, &data);
//        counter++;
//    }


/* was before main*/
//volatile uint8* LAT_REGISTERS[] = {&LATA, &LATB, &LATC, &LATD, &LATE};
//volatile uint8* PORT_REGISTERS[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};
//void fun(void);
//void fun1(void);
//void fun2(void);
//int var = 0;
//led_t led1 = {
//    .PIN   = PIN0,
//    .PORT  = PORTC_INDEX,
//    .state = LOW
//};
//
//led_t led2 = {
//    .PIN   = PIN1,
//    .PORT  = PORTC_INDEX,
//    .state = LOW
//};
//
//led_t led3 = {
//    .PIN   = PIN2,
//    .PORT  = PORTC_INDEX,
//    .state = LOW
//};
//
//
//
//
//Interrupt_RBx_t RB4_INT = {
//    .pin.PIN = PIN4,
//    .pin.PORT = PORTB_INDEX,
//    .pin.direction = INPUT,
//    .callback = fun,
//    .priority = PRIORITY_LOW
//};
//
//Interrupt_RBx_t RB5_INT = {
//    .pin.PIN = PIN5,
//    .pin.PORT = PORTB_INDEX,
//    .pin.direction = INPUT,
//    .callback = fun,
//    .priority = PRIORITY_LOW
//};
//Interrupt_RBx_t RB6_INT = {
//    .pin.PIN = PIN6,
//    .pin.PORT = PORTB_INDEX,
//    .pin.direction = INPUT,
//    .callback = fun,
//    .priority = PRIORITY_LOW
//};
//Interrupt_RBx_t RB7_INT = {
//    .pin.PIN = PIN7,
//    .pin.PORT = PORTB_INDEX,
//    .pin.direction = INPUT,
//    .callback = fun,
//    .priority = PRIORITY_LOW
//};
//
//
//
//
//
//
//
//
//Interrupt_INTx_t  x = {
//    .pin.PIN = PIN0,
//    .pin.PORT = PORTB_INDEX,
//    .pin.direction = INPUT,
//    .edge = FALLING_EDGE,
//    .callback = fun,
//    .priority = PRIORITY_HIGH,
//    .source = INT0_INTERRUPT
//};
//
//Interrupt_INTx_t  y = {
//    .pin.PIN = PIN1,
//    .pin.PORT = PORTB_INDEX,
//    .pin.direction = INPUT,
//    .edge = RISING_EDGE,
//    .callback = fun1,
//    .priority = PRIORITY_HIGH,
//    .source = INT1_INTERRUPT
//};
//
//Interrupt_INTx_t  z = {
//    .pin.PIN = PIN2,
//    .pin.PORT = PORTB_INDEX,
//    .pin.direction = INPUT,
//    .edge = FALLING_EDGE,
//    .callback = fun2,
//    .priority = PRIORITY_LOW,
//    .source = INT2_INTERRUPT
//};
//
//void fun(void){
//    led_toggle(&led1);
//    var++;
//}
//void fun1(void){
//    led_toggle(&led1);
//    var++;
//}
//void fun2(void){
//    led_toggle(&led1);
//    var++;
//}
////
////pin_config_t pin0 = {
////    .PIN  = PIN0,
////    .PORT = PORTC_INDEX,
////    .direction = OUTPUT,
////    .logic = LOW
////};
////
////pin_config_t pin1 = {
////    .PIN  = PIN1,
////    .PORT = PORTC_INDEX,
////    .direction = OUTPUT,
////    .logic = LOW
////};
////
////pin_config_t pin2 = {
////    .PIN  = PIN2,
////    .PORT = PORTC_INDEX,
////    .direction = OUTPUT,
////    .logic = LOW
////};
////
////pin_config_t pin3 = {
////    .PIN  = PIN3,
////    .PORT = PORTC_INDEX,
////    .direction = OUTPUT,
////    .logic = LOW
////};
////
////
////
////
////uint8 seven_segment_number_codes[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
////extern keypad_t keypad;
////extern chr_lcd_4bit_t lcd1;
////extern chr_lcd_8bit_t lcd2;
//uint8 data;
//uint8 counter;



/* was in main*/

//    int (*ptrfun)(void) = fun;

//    ret = led_initialize(&led1);
//    ret = led_initialize(&led2);
//    ret = led_initialize(&led3);
//    *(LAT_REGISTERS[2]) = 0x07;
//    *(PORT_REGISTERS[2]) = 0x07;
//    ret = RBx_init(&RB4_INT);
//    ret = RBx_init(&RB5_INT);
//    ret = RBx_init(&RB7_INT);
//    ret = RBx_init(&RB6_INT);

//    INTx_init(&x);
//    INTx_init(&y);
//    INTx_init(&z);

//    uint8 counter = 0;
//    ret = lcd_4bit_initialize(&lcd1);
//    ret = lcd_8bit_initialize(&lcd2);
//    ret = lcd_8bit_send_str_data_position(&lcd2,"Embedded Diploma",1,1);
//    ret = lcd_4bit_send_str_data_position(&lcd1,"Hello Alaa",1,5);
//    
//    ret = gpio_pin_logic_write(&(lcd2.lcd_rs),HIGH);
//    uint8 data_command = 'A';
//    /**
//     * @brief send bits 
//     * @param argc
//     * @param argv
//     * @return 
//     */
//    for (uint8 counter = 0; counter < 8 ; counter++){
//        ret = gpio_pin_logic_write(&(lcd2.lcd_data[counter]),(data_command >> counter) & (uint8)0x01);
//    }
//    /**
//     * @brief enable
//     * @param argc
//     * @param argv
//     * @return 
//     */
//    ret = gpio_pin_logic_write(&(lcd2.lcd_en), HIGH);
//    __delay_us(5);
//    ret = gpio_pin_logic_write(&(lcd2.lcd_en), LOW);    
//    while(1){
//        for(counter = 0; counter <= 2; counter++){
//            ret = lcd_4bit_send_str_data_position(&lcd1,"Fuck you!",2,5+counter);
//            ret = lcd_4bit_send_chr_data_position(&lcd1,' ',2,5+counter);    
//        }
//        ret = lcd_4bit_send_str_data_position(&lcd1,"   ",2,14); // 14 = 5 + len("Fuck you!") + 3 loops
//        // you can instead clear all or just use a count down loop using the counter variable 
//        
//    }

//
//ADC_Init(&ADC_1);
//    motor_initialize(&motor_1);
//    motor_initialize(&motor_2);
////    ADC_Init(&ADC_2);
////    ADC_Init(&ADC_3);
////    ADC_Init(&ADC_4);
//    led_initialize(&led);
//    lcd_4bit_initialize(&lcd1);
//    char* str = "Value:";
//    
//    lcd_4bit_send_str_data_position(&lcd1,str,1,1);
//    lcd_4bit_send_str_data_position(&lcd1,str,2,1);
//    lcd_4bit_send_str_data_position(&lcd1,str,3,1);
//    lcd_4bit_send_str_data_position(&lcd1,str,4,1);
//    while(TRUE){
//        req = 0;
//        ADC_Conversion_Complete_Non_Blocking_Operation(&ADC_1,AN_0,&data1);
//        ret = convert_short_to_str(data1,value);
//        ret = lcd_4bit_send_str_data_position(&lcd1,value,1,7);
////        for(uint8 counter = 0; counter < 5; counter++){ret |= lcd_4bit_send_chr_data_position(&lcd1,value[counter], 1, 7+counter);}
//        
//        req = 1;
//        ADC_Conversion_Complete_Non_Blocking_Operation(&ADC_1,AN_1,&data2);
//        ret = convert_short_to_str(data2,value);
//        ret = lcd_4bit_send_str_data_position(&lcd1,value,2,7);
////        for(uint8 counter = 0; counter < 5; counter++){ret |= lcd_4bit_send_chr_data_position(&lcd1,value[counter], 2, 7+counter);}
//        
////        req = 2;
////        ADC_Conversion_Complete_Non_Blocking_Operation(&ADC_1,AN_2,&data3);
////        ret = convert_short_to_str(data3,value);
////        ret = lcd_4bit_send_str_data_position(&lcd1,value,3,7);
//////        for(uint8 counter = 0; counter < 5; counter++){ret |= lcd_4bit_send_chr_data_position(&lcd1,value[counter], 3, 7+counter);}
////        
////        req = 3;
////        ADC_Conversion_Complete_Non_Blocking_Operation(&ADC_1,AN_3,&data4);
////        ret = convert_short_to_str(data4,value);
////        ret = lcd_4bit_send_str_data_position(&lcd1,value,4,7);
//
//        
//        req = 2;
//        ADC_Conversion_Complete_Non_Blocking_Operation(&ADC_1,AN_4,&data3);
//        ret = convert_short_to_str(data3,value);
//        ret = lcd_4bit_send_str_data_position(&lcd1,value,3,7);
//
////        for(uint8 counter = 0; counter < 5; counter++){ret |= lcd_4bit_send_chr_data_position(&lcd1,value[counter], 3, 7+counter);}
//        
//        req = 3;
//        ADC_Conversion_Complete_Non_Blocking_Operation(&ADC_1,AN_5,&data4);
//        ret = convert_short_to_str(data4,value);
//        ret = lcd_4bit_send_str_data_position(&lcd1,value,4,7);
//        
//
////        for(uint8 counter = 0; counter < 5; counter++){ret |= lcd_4bit_send_chr_data_position(&lcd1,value[counter], 4, 7+counter);}
//        
////        ret = lcd_4bit_send_str_data_position(&lcd1,value,2,7);
////        ADC_Conversion_Complete_Blocking_Operation(&ADC_1,AN_2,&data3);
////        ret = convert_short_to_str(data3,value);
////        ret = lcd_4bit_send_str_data_position(&lcd1,value,3,7);
////        ADC_Conversion_Complete_Blocking_Operation(&ADC_1,AN_3,&data4);
////        ret = convert_short_to_str(data4,value);
////        ret = lcd_4bit_send_str_data_position(&lcd1,value,4,7);
////        __delay_ms(2000);
////        ret = lcd_4bit_send_str_data_position(&lcd1,"      ",1,7);
////        ret = lcd_4bit_send_str_data_position(&lcd1,"      ",2,7);
////        ret = lcd_4bit_send_str_data_position(&lcd1,"      ",3,7);
////        ret = lcd_4bit_send_str_data_position(&lcd1,"      ",4,7);
//void ADC_CallBack(void);
//
//
//motor_t motor_1 = {
//    .motor_pins[0].logic = LOW, .motor_pins[0].motor_index = 0, .motor_pins[0].pin = PIN4, .motor_pins[0].port = PORTD_INDEX,
//    .motor_pins[1].logic = LOW, .motor_pins[1].motor_index = 0, .motor_pins[1].pin = PIN5, .motor_pins[1].port = PORTD_INDEX,
//};
//
//
//motor_t motor_2 = {
//    .motor_pins[0].logic = LOW, .motor_pins[0].motor_index = 1, .motor_pins[0].pin = PIN6, .motor_pins[0].port = PORTD_INDEX,
//    .motor_pins[1].logic = LOW, .motor_pins[1].motor_index = 1, .motor_pins[1].pin = PIN7, .motor_pins[1].port = PORTD_INDEX,
//};
//
//chr_lcd_4bit_t lcd1 = {
//    .lcd_rs.PORT = PORTC_INDEX, .lcd_rs.PIN = PIN1, .lcd_rs.direction = OUTPUT, .lcd_rs.logic = LOW,
//    .lcd_en.PORT = PORTC_INDEX, .lcd_en.PIN = PIN2, .lcd_en.direction = OUTPUT, .lcd_en.logic = LOW,
//    .lcd_data[0].PORT = PORTD_INDEX, .lcd_data[0].PIN = PIN0, .lcd_data[0].direction = OUTPUT, .lcd_data[0].logic = LOW,
//    .lcd_data[1].PORT = PORTD_INDEX, .lcd_data[1].PIN = PIN1, .lcd_data[1].direction = OUTPUT, .lcd_data[1].logic = LOW,
//    .lcd_data[2].PORT = PORTD_INDEX, .lcd_data[2].PIN = PIN2, .lcd_data[2].direction = OUTPUT, .lcd_data[2].logic = LOW,
//    .lcd_data[3].PORT = PORTD_INDEX, .lcd_data[3].PIN = PIN3, .lcd_data[3].direction = OUTPUT, .lcd_data[3].logic = LOW,
//};
//
//int var = 0;
//led_t led = {
//    .PIN = PIN0, .PORT = PORTC_INDEX, .state = LOW
//};
//
//
//
//ADC_CONFIG_t ADC_1 = {
//    .ADC_AQUISITION_TIME    = TAD_0,
//    .ADC_CONVERSION_CLOCK   = FOSC_DIV_2,
//    .ADC_interrupt_handler  = ADC_CallBack,
//    .ANx_ACTIVATED_CHANNELS = ALL_ANALOG,
//    .ANx_SELECTED_CHANNEL   = AN_0,
//    .DATA_ALLIGNMENT_FORMAT = RIGHT_JUSTIFIED,
//    .VOLTAGE_SOURCE_USED    = ADC_SUPPLY_VOLTAGE,
//};

//ADC_CONFIG_t ADC_2 = {
//    .ADC_AQUISITION_TIME    = TAD_0,
//    .ADC_CONVERSION_CLOCK   = FOSC_DIV_2,
//    .ADC_interrupt_handler  = ADC_CallBack,
//    .ANx_ACTIVATED_CHANNELS = ALL_ANALOG,
//    .ANx_SELECTED_CHANNEL   = AN_1,
//    .DATA_ALLIGNMENT_FORMAT = RIGHT_JUSTIFIED,
//    .VOLTAGE_SOURCE_USED    = ADC_SUPPLY_VOLTAGE,
//};
//
//ADC_CONFIG_t ADC_3 = {
//    .ADC_AQUISITION_TIME    = TAD_0,
//    .ADC_CONVERSION_CLOCK   = FOSC_DIV_2,
//    .ADC_interrupt_handler  = ADC_CallBack,
//    .ANx_ACTIVATED_CHANNELS = ALL_ANALOG,
//    .ANx_SELECTED_CHANNEL   = AN_2,
//    .DATA_ALLIGNMENT_FORMAT = RIGHT_JUSTIFIED,
//    .VOLTAGE_SOURCE_USED    = ADC_SUPPLY_VOLTAGE,
//};
//
//ADC_CONFIG_t ADC_4 = {
//    .ADC_AQUISITION_TIME    = TAD_0,
//    .ADC_CONVERSION_CLOCK   = FOSC_DIV_2,
//    .ADC_interrupt_handler  = ADC_CallBack,
//    .ANx_ACTIVATED_CHANNELS = ALL_ANALOG,
//    .ANx_SELECTED_CHANNEL   = AN_3,
//    .DATA_ALLIGNMENT_FORMAT = RIGHT_JUSTIFIED,
//    .VOLTAGE_SOURCE_USED    = ADC_SUPPLY_VOLTAGE,
//};
//
//uint16 data1,data2,data3,data4;
//uint8 temprature_sensor_reading_1, temprature_sensor_reading_2;
//uint8 motor_1_status = MOTOR_OFF, motor_2_status = MOTOR_OFF;
//char req = 0;
//char value[6];