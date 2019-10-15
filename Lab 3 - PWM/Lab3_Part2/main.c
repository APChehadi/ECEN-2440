#include "msp.h"
#include "pwm.h"
#include <stdio.h>
#include <stdlib.h>


void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	global_flag = 0;

	__NVIC_EnableIRQ(TA0_0_IRQn);
    __NVIC_SetPriority(TA0_0_IRQn, 0);

	timer_A0_config(CALC_PERIOD);
	config_pwm_gpio();

	while(1) {
	    toggle_gpio(global_flag);
	}
}
