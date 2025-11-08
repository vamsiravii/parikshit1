/*
 * led_control.h
 *
 *  Created on: Nov 8, 2025
 *      Author: chalam
 */

#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include "stm32h7xx_hal.h"

typedef struct {
    uint8_t led_no;
    GPIO_TypeDef *gpio_port;
    uint16_t gpio_pin;
    uint8_t *status;
} LED;

LED* initialise_leds(uint8_t n, GPIO_TypeDef **ports, uint16_t *pins);
void set_led(LED *led);
void reset_led(LED *led);
void toggle_led(LED *led);
void deinit_leds(LED *arr, uint8_t n);

#endif
