/*
 * pwm.c
 *
 *  Created on: Sep 27, 2019
 *      Author: adamp
 */

#include "msp.h"
#include "pwm.h"
#include <stdio.h>
#include <stdlib.h>


/* Configure TIMER_A0 to produce PWM waveform
 * -TODO: reset R (timer counter) register
 * -TODO: select SMCLK (3MHz) in the CTL register
 * -TODO: select reset/set output mode for T0.1 timer using CCTL[1]
 */
void config_pwm_timer(void) {
    TIMER_A0 -> R = 0x00;
    TIMER_A0 -> CTL |= TIMER_A_CTL_TASSEL_2;
    TIMER_A0 -> CCTL[1] |= TIMER_A_CCTLN_OUTMOD_7;
}


/* -TODO: Start PWM signal on Pin XX at duty_cycle 100kHz,
 *  Note: the DRV2605L PWM input frequency is XXXX
 * -TODO: calculate and set the amount of ticks needed in CCR
 * -TODO: enable/start timer (UP mode)
 * -TODO: Counting and then reset
 * @param uint8_t duty_cycle: 0-100, percentage of time ON
 */
void start_pwm(uint8_t duty_cycle) {
    TIMER_A0 -> CCR[0] = CALC_PERIOD;
    TIMER_A0 -> CCR[1] = CALC_PERIOD * duty_cycle / 100;
    TIMER_A0 -> CTL |= TIMER_A_CTL_MC__UP;
}


// Stop Mode: clear all Mode Control bits, MC, in TAxCTL register
void stop_pwm(void) {
    TIMER_A0 -> CTL |= 0x02;
}


// Config P2.4 to output TA0.1 waveform
void config_pwm_gpio(void) {
    P2 -> DIR |= BIT4;
    P2 -> SEL0 |= BIT4;
    P2 -> SEL1 &= ~BIT4;
}
