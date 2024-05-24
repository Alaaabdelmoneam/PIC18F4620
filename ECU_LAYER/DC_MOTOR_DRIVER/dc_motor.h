/* 
 * File:   dc_motor.h
 * Author: Alaa
 *
 * Created on March 11, 2024, 1:57 PM
 */

#ifndef DC_MOTOR_H
#define	DC_MOTOR_H

/* Includes section */

#include "dc_motor_cfg.h"
#include "../../MCAL_LAYER/GPIO/HAL_GPIO.h"
/* Macros section */
#define MOTOR_OFF 0x00
#define MOTOR_ON  0x01

#define MOTOR_LEFT  0x02
#define MOTOR_RIGHT 0x03

typedef struct {
    uint8 port        :3;
    uint8 pin         :3;
    uint8 logic       :1;
    uint8 motor_index :1;
}motor_pin_t;

typedef struct {
    motor_pin_t motor_pins[2];
}motor_t;

STD_ReturnType motor_initialize(const motor_t * motor);
STD_ReturnType motor_turn_right(const motor_t * motor);
STD_ReturnType motor_turn_left(const motor_t * motor);
STD_ReturnType motor_turn_off (const motor_t * motor);

#endif	/* DC_MOTOR_H */

