/*
 * drv2605l.c
 *
 *  Created on: Oct 16, 2019
 *      Author: adamp
 */

#include "msp.h"
#include "i2c.h"
#include "gpio.h"

#define DRV2605L        0x5A        // 7-bit address (8.5.3.1 note)

#define STATUS          0x00
#define MODE            0x01
#define GO              0x0C
#define CONTROL3        0x1D

#define MODE_PWM        0x03
#define MODE_STANDBY    (1 << 6)
#define GO_GO           0x01
#define LIBRARY         0x03


void config_drv2605L(void) {
    config_drv_gpio();              // configure EN pin

    int i;
    for(i = 0; i < 100000; i++);    // need to wait 250us before writing to it

    // COME OUT OF STANDBY MODE
    write_register(DRV2605L, MODE, MODE_STANDBY);

    // SET MODE REG TO 3
    write_register(DRV2605L, MODE, MODE_PWM);

    uint8_t mode_reg = read_register(DRV2605L, MODE);

    // SET CONTROL3 TO PWM
    write_register(DRV2605L, CONTROL3, STATUS);

    // SELECT LRA LIBRARY
    write_register(DRV2605L, LIBRARY, 0x06);

    mode_reg = read_register(DRV2605L, MODE);
    if(mode_reg != MODE_PWM) {
        P1 -> DIR |= BIT0;
        P1 -> OUT |= BIT0;          // indicate error occured
    }

    uint8_t control_three_reg = read_register(DRV2605L, CONTROL3);
    if(control_three_reg != 0x00) {
        P1 -> DIR |= BIT0;
        P1 -> OUT |= BIT0;          // indicate error occured
    }
}


