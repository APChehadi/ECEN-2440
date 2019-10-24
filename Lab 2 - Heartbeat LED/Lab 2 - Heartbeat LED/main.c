#include "msp.h"
#include <stdio.h>

void delay(int ms)
{
    int c, d;

    for (c = 1; c <= ms; c++) {
        for (d = 1; d <= ms; d++) {}
    }
}

void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer

    P1->DIR |= 0x01;
    P1->OUT |= 0x01;

    while(1) {
        P1->OUT ^= 0x01;
        delay(300);

        P1->OUT ^= 0x01;
        delay(300);
    }
}
