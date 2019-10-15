#include "msp.h"
#include "pwm.h"
#include <stdio.h>
#include <stdlib.h>


void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	config_pwm_timer();
	config_pwm_gpio();
	start_pwm(50);

    int i;
	for(i=0; i<50; i++) {
	    // blah
	}

	stop_pwm();

}
