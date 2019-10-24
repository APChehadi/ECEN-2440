#include "msp.h"
#include "pwm.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	config_i2c();
	config_drv2605L();

	config_pwm_timer();
    start_pwm(90);

    while(1) {
        // blah
    }

    stop_pwm();
}
