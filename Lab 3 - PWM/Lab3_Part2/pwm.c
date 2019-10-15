/*
 * pwm.c
 *
 *  Created on: Oct 13, 2019
 *      Author: adamp
 */


#include "msp.h"
#include "pwm.h"
#include <stdio.h>
#include <stdlib.h>


void timer_A0_config(uint16_t period){
    TIMER_A0 -> R = 0x00;
    TIMER_A0 -> CTL |= TIMER_A_CTL_TASSEL_2;

    TIMER_A0 -> CCTL[0] |= TIMER_A_CCTLN_CCIE;

    TIMER_A0 -> CCR[0] = period;

    TIMER_A0 -> CTL |= TIMER_A_CTL_ID__8;       // Divide clock by 8
    TIMER_A0 -> CTL |= TIMER_A_CTL_MC__UP;
}


// Config P2.4 to output TA0.1 waveform
void config_pwm_gpio(void) {
    P2 -> DIR |= BIT4;
    P2 -> SEL0 &= BIT4;
    P2 -> SEL1 &= ~BIT4;
}


void TA0_0_IRQHandler(void) {
    __disable_irq();

    if((TIMER_A0->CCTL[0] && TIMER_A_CCTLN_CCIFG) == 1) {
        global_flag = 1;
        TIMER_A0->CTL &= (~TIMER_A_CCTLN_CCIFG);
    }

    __enable_irq();
}


void toggle_gpio(int temp_flag) {
    if(temp_flag == 1) {
        P2 -> OUT ^= BIT4;
        global_flag = 0;
    }
}
