# LED Fade on STM32F407

A first STM32 project: an LED that fades smoothly in and out using hardware PWM.

## What it does

- Timer **TIM3, channel 3** generates the PWM signal on pin **PB0**.
- The timer is set up with a prescaler of 83 and a period of 999, giving 1000 duty-cycle steps.
- The main loop ramps the duty cycle from 0 to 999 and back to 0 in 2 ms steps, so each fade takes about 2 seconds.

There is also a small helper module, [`Core/Src/led_control.c`](Core/Src/led_control.c), for switching groups of GPIO LEDs on, off or toggling them. The fade demo itself does not use it.

## Hardware and tools

- MCU: STM32F407VG
- Toolchain: STM32CubeIDE (`fade.ioc` holds the CubeMX configuration)

## Known rough edges

This repo has leftovers from an earlier STM32H7 project: STM32H7 startup and HAL configuration files are present, and `led_control.h` includes the H7 HAL header. The `Inc/`, `Src/` and `Startup/` folders at the top level also appear to duplicate `Core/`. Cleaning these up is a good next step. This project has not been build-verified, so treat it as a reference rather than a drop-in template.
