/*
 * pwm.h
 *
 *  Created on: Oct 13, 2019
 *      Author: adamp
 */

#ifndef PWM_H_
#define PWM_H_

/* DEFINES */
#define SYSTEM_CLOCK    3000000             //[Hz] system_msp432p401r.c
#define CALC_PERIOD  (SYSTEM_CLOCK / 8) * (0.05)  //calc # of ticks in period

int global_flag;

void timer_A0_config(uint16_t period);

void TA0_0_IRQHandler(void);

void config_pwm_gpio(void);

void toggle_gpio(int flag);

#endif /* PWM_H_ */
