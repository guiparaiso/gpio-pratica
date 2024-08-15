/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int BTN = 16;
const int BLUE_LED = 12;
const int D =18;
const int C = 19;
const int B = 20;
const int A = 21;
const int pinArray[] = {D, C, B, A};

int main() {
    stdio_init_all();
    for (int i = 0; i < 4; i++) {
        gpio_init(pinArray[i]);
        gpio_set_dir(pinArray[i], GPIO_OUT);
    }
    gpio_init(BTN);
    gpio_init(BLUE_LED);
    gpio_set_dir(BTN, GPIO_IN);
    gpio_pull_up(BTN);
    gpio_set_dir(BLUE_LED, GPIO_OUT);
    while (true) {
        if(!gpio_get(BTN)) {
            printf("Button pressed\n");
            gpio_put(BLUE_LED, 1);
            for (int i = 0; i < 512; i++) {
                for (int j = 0; j < 4; j++) {
                    gpio_put(pinArray[j],1);
                    sleep_ms(10);
                    gpio_put(pinArray[j],0);
                }
            }
        } else {
            gpio_put(BLUE_LED, 0);
        }
    }
}
