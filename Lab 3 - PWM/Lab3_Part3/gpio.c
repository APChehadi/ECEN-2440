/*
 * gpio.c
 *
 *  Created on: Oct 19, 2019
 *      Author: adamp
 */


#include "msp.h"
#include "gpio.h"
#include <stdio.h>
#include <stdlib.h>


// Config
void config_drv_gpio(void) {
    P2->DIR |= BIT5;
    P2->OUT |= BIT5;

    P2 -> DIR |= BIT4;
    P2 -> SEL0 |= BIT4;
    P2 -> SEL1 &= ~BIT4;
}

