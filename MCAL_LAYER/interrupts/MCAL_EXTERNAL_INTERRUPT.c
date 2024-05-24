/* 
 * File:   MCAL_EXTERNAL_INTERRUPT.h
 * Author: Alaa
 *
 * Created on April 20, 2024, 2:49 PM
 */



#include "MCAL_EXTERNAL_INTERRUPT.h"
#include "../GPIO/HAL_GPIO.h"


pin_config_t pin1 = {
    .PIN = PIN0,
    .PORT = PORTC_INDEX,
    .direction = OUTPUT,
    .logic = LOW
};
pin_config_t pin2 = {
    .PIN = PIN1,
    .PORT = PORTC_INDEX,
    .direction = OUTPUT,
    .logic = LOW
};
pin_config_t pin3 = {
    .PIN = PIN2,
    .PORT = PORTC_INDEX,
    .direction = OUTPUT,
    .logic = LOW
};
volatile uint8* LAT_REGISTERS[] = {&LATA, &LATB, &LATC, &LATD, &LATE};



static void (*RB4_Interrupt_Handler)(void) = NULL;
static void (*RB5_Interrupt_Handler)(void) = NULL;
static void (*RB6_Interrupt_Handler)(void) = NULL;
static void (*RB7_Interrupt_Handler)(void) = NULL;


static void (*INT0_Interrupt_Handler)(void) = NULL;
static void (*INT1_Interrupt_Handler)(void) = NULL;
static void (*INT2_Interrupt_Handler)(void) = NULL;
static STD_ReturnType Set_INT0_Handler(void (*INTx_Interrupt_Handler)(void));
static STD_ReturnType Set_INT1_Handler(void (*INTx_Interrupt_Handler)(void));
static STD_ReturnType Set_INT2_Handler(void (*INTx_Interrupt_Handler)(void));

static STD_ReturnType Set_Interrupt_Handler(const Interrupt_INTx_t *INTx);
static STD_ReturnType INTx_Enable(const Interrupt_INTx_t *INTx);
static STD_ReturnType INTx_Disable(const Interrupt_INTx_t *INTx);
static STD_ReturnType INTx_Init_Pin(const Interrupt_INTx_t *INTx);
static STD_ReturnType INTx_Init_priority(const Interrupt_INTx_t *INTx);
static STD_ReturnType INTx_Init_Edge(const Interrupt_INTx_t *INTx);
static STD_ReturnType INTx_Clear_Flag(const Interrupt_INTx_t *INTx);

static STD_ReturnType RBx_Enable(const Interrupt_RBx_t *RBx);
static STD_ReturnType RBx_Disable(const Interrupt_RBx_t *RBx);
static STD_ReturnType RBx_Init_Pin(const Interrupt_RBx_t *RBx);
static STD_ReturnType RBx_Init_priority(const Interrupt_RBx_t *RBx);

/**
 * 
 * @param INTx
 * @return 
 */
STD_ReturnType INTx_init(const Interrupt_INTx_t *INTx){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == INTx){
        ret = E_NOT_OK;
    }
    else{
        
        /* de-initialize*/
        /* disable external Interrupt*/
        ret = INTx_Disable(INTx);
        /* Clear flag*/
        ret = INTx_Clear_Flag(INTx);
        /* initialize edge*/
        ret = Set_Interrupt_Handler(INTx);
        ret = INTx_Init_Edge(INTx);
        /* initialize pin*/
        ret = INTx_Init_Pin(INTx);
        /* initialize priority*/
#ifdef PRIORITY_FEATURE_ENABLED
        ret = INTx_Init_priority(INTx);
#endif
        /* Enable Interrupt*/
        ret = INTx_Enable(INTx);
        
        /* initialize */
    }
    return ret;
}

/**
 * 
 * @param INTx
 * @return 
 */
STD_ReturnType INTx_Deinit(const Interrupt_INTx_t *INTx){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == INTx){
        ret = E_NOT_OK;
    }
    else{
        ret = INTx_Disable(INTx);
    }
    return ret;
}


/**
 * 
 * @param INTx
 * @return 
 */
STD_ReturnType RBx_init(const Interrupt_RBx_t *RBx){
    
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == RBx){
        ret = E_NOT_OK;
    }
    else{
//#ifndef RBx_ALREADY_INITALIZED
//#define RBx_ALREADY_INITALIZED
        INTERRUT_RBx_FEATURE_DISABLE;
        INTERRUT_RBx_FLAG_CLEAR;
        
        #ifdef PRIORITY_FEATURE_ENABLED
        INTERRUPT_PRIORITY_FEATURE_ENABLE;
        INTERRUPT_PRIORITY_HIGH_ENABLE;
        INTERRUPT_PRIORITY_LOW_ENABLE;
        INTERRUT_RBx_PRIORITY_SET(RBx->priority);
        #else
        INTERRUPT_GENERAL_FEATURE_ENABLE;
        INTERRUPT_PERIPHERAL_FEATURE_ENABLE;
        #endif
        switch(RBx->pin.PIN)
        {
            case PIN4:
                RB4_Interrupt_Handler = RBx->callback;
                break;
            case PIN5:
                RB5_Interrupt_Handler = RBx->callback;
                break;
            case PIN6:
                RB6_Interrupt_Handler = RBx->callback;
                break;
            case PIN7:
                RB7_Interrupt_Handler = RBx->callback;
                break;
        }
        
        
        INTERRUT_RBx_FEATURE_ENABLE;
//#else
//        ret = E_OK;
//#endif        
    }
    return ret;
}

/**
 * 
 * @param INTx
 * @return 
 */
STD_ReturnType RBx_Deinit(const Interrupt_RBx_t *RBx){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == RBx){
        ret = E_NOT_OK;
    }
    else{
        RBx_Disable(RBx);
    }
    return ret;
}

static STD_ReturnType INTx_Enable(const Interrupt_INTx_t *INTx){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == INTx){
        ret = E_NOT_OK;
    }
    else{
        switch(INTx->source){
            case(INT0_INTERRUPT):
                #ifdef PRIORITY_FEATURE_ENABLED
                INTERRUPT_PRIORITY_FEATURE_ENABLE;
                INTERRUPT_PRIORITY_HIGH_ENABLE;
                INTERRUPT_PRIORITY_LOW_ENABLE;
                #else
                INTERRUPT_GENERAL_FEATURE_ENABLE;
                INTERRUPT_PERIPHERAL_FEATURE_ENABLE;
                #endif   
                INT0_FEATURE_ENABLE;
                ret = E_OK;
                break;
            case(INT1_INTERRUPT):
                #ifdef PRIORITY_FEATURE_ENABLED
                INTERRUPT_PRIORITY_FEATURE_ENABLE;
                INTERRUPT_PRIORITY_HIGH_ENABLE;
                INTERRUPT_PRIORITY_LOW_ENABLE;
                #else
                INTERRUPT_GENERAL_FEATURE_ENABLE;
                INTERRUPT_PERIPHERAL_FEATURE_ENABLE;
                #endif   
                INT1_FEATURE_ENABLE;
                ret = E_OK;
                break;
            case(INT2_INTERRUPT):
                #ifdef PRIORITY_FEATURE_ENABLED
                INTERRUPT_PRIORITY_FEATURE_ENABLE;
                INTERRUPT_PRIORITY_HIGH_ENABLE;
                INTERRUPT_PRIORITY_LOW_ENABLE;
                #else
                INTERRUPT_GENERAL_FEATURE_ENABLE;
                INTERRUPT_PERIPHERAL_FEATURE_ENABLE;
                #endif   
                INT2_FEATURE_ENABLE;
                ret = E_OK;
                break;
            default:
                ret = E_NOT_OK;
        }
    }
    return ret;
}

static STD_ReturnType INTx_Disable(const Interrupt_INTx_t *INTx){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == INTx){
        ret = E_NOT_OK;
    }
    else{
        switch(INTx->source){
            case(INT0_INTERRUPT):
                INT0_FEATURE_DISABLE;
                ret = E_OK;
                break;
            case(INT1_INTERRUPT):
                INT1_FEATURE_DISABLE;
                ret = E_OK;
                break;
            case(INT2_INTERRUPT):
                INT2_FEATURE_DISABLE;
                ret = E_OK;
                break;
            default:
                ret = E_NOT_OK;
        }
    }
    return ret;
}

static STD_ReturnType INTx_Init_Pin(const Interrupt_INTx_t *INTx){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == INTx){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_init(&(INTx->pin));
    }
    return ret;
}
#ifdef PRIORITY_FEATURE_ENABLED
static STD_ReturnType INTx_Init_priority(const Interrupt_INTx_t *INTx){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == INTx){
        ret = E_NOT_OK;
    }
    else{
        switch(INTx->source){
            case(INT1_INTERRUPT):
                
                if (INTx->priority == PRIORITY_LOW || INTx->priority == PRIORITY_HIGH){
                    INT1_PRIORITY_SET(INTx->priority);
                    ret = E_OK;
                }
                else{
                    /*Do nothing*/
                }
                break;
            case(INT2_INTERRUPT):
                if (INTx->priority == PRIORITY_LOW || INTx->priority == PRIORITY_HIGH){
                    INT2_PRIORITY_SET(INTx->priority);   
                    ret = E_OK;
                }
                else{
                    /*Do nothing*/
                }
                break;
            default:
                ret = E_NOT_OK;
        }
    }
    return ret;
}
#endif
static STD_ReturnType INTx_Init_Edge(const Interrupt_INTx_t *INTx){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == INTx){
        ret = E_NOT_OK;
    }
    else{
        switch(INTx->source){
            case(INT0_INTERRUPT):
                if(FALLING_EDGE == INTx->edge)
                {
                    INT0_FALLING_EDGE_ENABLE;
                    ret = E_OK;
                }
                else if (RISING_EDGE == INTx->edge){
                    INT0_RISING_EDGE_ENABLE;
                    ret = E_OK;
                }
                break;
                
            case(INT1_INTERRUPT):
                if(FALLING_EDGE == INTx->edge)
                {
                    INT1_FALLING_EDGE_ENABLE;
                    ret = E_OK;
                }
                else if (RISING_EDGE == INTx->edge){
                    INT1_RISING_EDGE_ENABLE;
                    ret = E_OK;
                }
                break;
            case(INT2_INTERRUPT):
                if(FALLING_EDGE == INTx->edge)
                {
                    INT2_FALLING_EDGE_ENABLE;
                    ret = E_OK;
                }
                else if (RISING_EDGE == INTx->edge){
                    INT2_RISING_EDGE_ENABLE;
                    ret = E_OK;
                }
                break;
            default:
                ret = E_NOT_OK;
        }
    }
    return ret;
}

static STD_ReturnType RBx_Enable(const Interrupt_RBx_t *RBx){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == RBx){
        ret = E_NOT_OK;
    }
    else{
        INTERRUT_RBx_FEATURE_ENABLE;
    }
    return ret;
}

static STD_ReturnType RBx_Disable(const Interrupt_RBx_t *RBx){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == RBx){
        ret = E_NOT_OK;
    }
    else{
        INTERRUT_RBx_FEATURE_DISABLE;
    }
    return ret;
}

static STD_ReturnType RBx_Init_Pin(const Interrupt_RBx_t *RBx){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == RBx){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_init(&(RBx->pin));
    }
    return ret;
}

#ifdef PRIORITY_FEATURE_ENABLED
static STD_ReturnType RBx_Init_priority(const Interrupt_RBx_t *RBx){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == RBx){
        ret = E_NOT_OK;
    }
    else{
        if (RBx->priority == PRIORITY_LOW || RBx->priority == PRIORITY_HIGH){
            INTERRUT_RBx_PRIORITY_SET(RBx->priority);
            ret = E_OK;
        }
    }
    return ret;
}
#endif

static STD_ReturnType INTx_Clear_Flag(const Interrupt_INTx_t *INTx){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == INTx){
        ret = E_NOT_OK;
    }
    else{
        switch(INTx->source){
            case(INT0_INTERRUPT):
                INT0_FLAG_CLEAR;
                ret = E_OK;
                break;
            case(INT1_INTERRUPT):
                INT1_FLAG_CLEAR;
                ret = E_OK;
                break;
            case(INT2_INTERRUPT):
                INT2_FLAG_CLEAR;
                ret = E_OK;
                break;
            default:
                ret = E_NOT_OK;
        }
    }
    return ret;
}

static STD_ReturnType Set_INT0_Handler(void (*INTx_Interrupt_Handler)(void)){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == INTx_Interrupt_Handler){
        ret = E_NOT_OK;
    }
    else{
        INT0_Interrupt_Handler = INTx_Interrupt_Handler;
        ret = E_OK;
    }
    return ret;
}
static STD_ReturnType Set_INT1_Handler(void (*INTx_Interrupt_Handler)(void)){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == INTx_Interrupt_Handler){
        ret = E_NOT_OK;
    }
    else{
        INT1_Interrupt_Handler = INTx_Interrupt_Handler;
        ret = E_OK;

    }
    return ret;
}
static STD_ReturnType Set_INT2_Handler(void (*INTx_Interrupt_Handler)(void)){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == INTx_Interrupt_Handler){
        ret = E_NOT_OK;
    }
    else{
        INT2_Interrupt_Handler = INTx_Interrupt_Handler;
        ret = E_OK;
    }
    return ret;
}
static STD_ReturnType Set_Interrupt_Handler(const Interrupt_INTx_t *INTx){
    STD_ReturnType ret = E_NOT_OK;
    if (NULL == INTx){
        ret = E_NOT_OK;
    }
    else{
        switch(INTx->source){
            case(INT0_INTERRUPT):
                ret = Set_INT0_Handler(INTx->callback);
                break;
            case(INT1_INTERRUPT):
                ret = Set_INT1_Handler(INTx->callback);
                break;
            case(INT2_INTERRUPT):
                ret = Set_INT2_Handler(INTx->callback);
                break;
            default:
                ret = E_NOT_OK;
        }
    }
    return ret;
}

void ISR0(void){
    /* flag clear */
    INT0_FLAG_CLEAR;
    /* MCAL context code */
    /* callback function */
    gpio_pin_logic_toggle(&pin1);
    __delay_ms(1000);
    gpio_pin_logic_toggle(&pin2);
    __delay_ms(1000);
    gpio_pin_logic_toggle(&pin3);
    __delay_ms(1000);
    if (INT0_Interrupt_Handler){gpio_pin_logic_write(&pin1,LOW);}
}
void ISR1(void){
    /* flag clear */
    INT1_FLAG_CLEAR;
    /* MCAL context code */
    /* callback function */
    gpio_pin_logic_toggle(&pin2);
    __delay_ms(1000);
    gpio_pin_logic_toggle(&pin3);
    __delay_ms(1000);
    gpio_pin_logic_toggle(&pin1);
    __delay_ms(1000);
    if (INT1_Interrupt_Handler){INT1_Interrupt_Handler;}
}
void ISR2(void){
    /* flag clear */
    INT2_FLAG_CLEAR;
    /* MCAL context code */
    /* callback function */
    gpio_pin_logic_toggle(&pin3);
    __delay_ms(1000);
    gpio_pin_logic_toggle(&pin1);
    __delay_ms(1000);
    gpio_pin_logic_toggle(&pin2);
    __delay_ms(1000);
    if (INT2_Interrupt_Handler){INT2_Interrupt_Handler;}
}

void RB0_ISR(uint8 level){
    /* flag clear */
    INTERRUT_RBx_FLAG_CLEAR;
    /* MCAL context code */
    /* callback function */
    if (HIGH == level){
        gpio_pin_logic_toggle(&pin3);
        __delay_ms(200);
        gpio_pin_logic_toggle(&pin3);
        __delay_ms(200);
        gpio_pin_logic_toggle(&pin1);
        __delay_ms(200);
        gpio_pin_logic_toggle(&pin1);
        __delay_ms(200);
        gpio_pin_logic_toggle(&pin2);
        __delay_ms(200);
        gpio_pin_logic_toggle(&pin2);
        __delay_ms(200);
    }
    else if (LOW == level){
        gpio_pin_logic_toggle(&pin3);
        __delay_ms(200);
        gpio_pin_logic_toggle(&pin3);
        __delay_ms(200);
        gpio_pin_logic_toggle(&pin1);
        __delay_ms(200);
        gpio_pin_logic_toggle(&pin1);
        __delay_ms(200);
        gpio_pin_logic_toggle(&pin2);
        __delay_ms(200);
        gpio_pin_logic_toggle(&pin2);
        __delay_ms(200);
    }
    
    if (RB4_Interrupt_Handler){RB4_Interrupt_Handler;}
}

void RB1_ISR(uint8 level){
    /* flag clear */
    INTERRUT_RBx_FLAG_CLEAR;
    /* MCAL context code */
    /* callback function */
    if (HIGH == level){
        gpio_pin_logic_toggle(&pin3);
        __delay_ms(100);
        gpio_pin_logic_toggle(&pin3);
        __delay_ms(100);
        gpio_pin_logic_toggle(&pin1);
        __delay_ms(100);
        gpio_pin_logic_toggle(&pin1);
        __delay_ms(100);
        gpio_pin_logic_toggle(&pin2);
        __delay_ms(100);
        gpio_pin_logic_toggle(&pin2);
        __delay_ms(100);
    }
    else if (LOW == level){
        gpio_pin_logic_toggle(&pin3);
        __delay_ms(100);
        gpio_pin_logic_toggle(&pin3);
        __delay_ms(100);
        gpio_pin_logic_toggle(&pin1);
        __delay_ms(100);
        gpio_pin_logic_toggle(&pin1);
        __delay_ms(100);
        gpio_pin_logic_toggle(&pin2);
        __delay_ms(100);
        gpio_pin_logic_toggle(&pin2);
        __delay_ms(100);
    }
    
    if (RB5_Interrupt_Handler){RB5_Interrupt_Handler;}
}

void RB2_ISR(uint8 level){
    /* flag clear */
    INTERRUT_RBx_FLAG_CLEAR;
    /* MCAL context code */
    /* callback function */
    if (HIGH == level){
        gpio_pin_logic_toggle(&pin3);
        __delay_ms(500);
        gpio_pin_logic_toggle(&pin3);
        __delay_ms(500);
        gpio_pin_logic_toggle(&pin1);
        __delay_ms(500);
        gpio_pin_logic_toggle(&pin1);
        __delay_ms(500);
        gpio_pin_logic_toggle(&pin2);
        __delay_ms(500);
        gpio_pin_logic_toggle(&pin2);
        __delay_ms(500);
    }
    else if (LOW == level){
        gpio_pin_logic_toggle(&pin3);
        __delay_ms(500);
        gpio_pin_logic_toggle(&pin3);
        __delay_ms(500);
        gpio_pin_logic_toggle(&pin1);
        __delay_ms(500);
        gpio_pin_logic_toggle(&pin1);
        __delay_ms(500);
        gpio_pin_logic_toggle(&pin2);
        __delay_ms(500);
        gpio_pin_logic_toggle(&pin2);
        __delay_ms(500);
    }
    if (RB6_Interrupt_Handler){RB6_Interrupt_Handler;}
}

void RB3_ISR(uint8 level){
    /* flag clear */
    INTERRUT_RBx_FLAG_CLEAR;
    /* MCAL context code */
    /* callback function */
    if (HIGH == level){
        gpio_pin_logic_toggle(&pin3);
        __delay_ms(400);
        gpio_pin_logic_toggle(&pin3);
        __delay_ms(400);
        gpio_pin_logic_toggle(&pin1);
        __delay_ms(400);
        gpio_pin_logic_toggle(&pin1);
        __delay_ms(400);
        gpio_pin_logic_toggle(&pin2);
        __delay_ms(400);
        gpio_pin_logic_toggle(&pin2);
        __delay_ms(400);
    }
    else if (LOW == level){
        gpio_pin_logic_toggle(&pin3);
        __delay_ms(400);
        gpio_pin_logic_toggle(&pin3);
        __delay_ms(400);
        gpio_pin_logic_toggle(&pin1);
        __delay_ms(400);
        gpio_pin_logic_toggle(&pin1);
        __delay_ms(400);
        gpio_pin_logic_toggle(&pin2);
        __delay_ms(400);
        gpio_pin_logic_toggle(&pin2);
        __delay_ms(400);
    }
    if (RB7_Interrupt_Handler){RB7_Interrupt_Handler;}
}