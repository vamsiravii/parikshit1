/*
 * led_control.c
 *
 *  Created on: Nov 8, 2025
 *      Author: chalam
 */
#include "led_control.h"
#include <stdlib.h>

LED* initialise_leds(uint8_t n, GPIO_TypeDef **ports, uint16_t *pins) {
    LED *arr = malloc(n * sizeof(LED));
    for(uint8_t i = 0; i < n; i++) {
        arr[i].led_no = i;
        arr[i].gpio_port = ports[i];
        arr[i].gpio_pin = pins[i];
        arr[i].status = malloc(sizeof(uint8_t));
        *(arr[i].status) = 0;
        HAL_GPIO_WritePin(ports[i], pins[i], GPIO_PIN_RESET);
    }
    return arr;
}

void set_led(LED *led) {
    *(led->status) = 1;
    HAL_GPIO_WritePin(led->gpio_port, led->gpio_pin, GPIO_PIN_SET);
}

void reset_led(LED *led) {
    *(led->status) = 0;
    HAL_GPIO_WritePin(led->gpio_port, led->gpio_pin, GPIO_PIN_RESET);
}

void toggle_led(LED *led) {
    *(led->status) = !(*(led->status));
    HAL_GPIO_TogglePin(led->gpio_port, led->gpio_pin);
}

void deinit_leds(LED *arr, uint8_t n) {
    for(uint8_t i = 0; i < n; i++) free(arr[i].status);
    free(arr);
}


