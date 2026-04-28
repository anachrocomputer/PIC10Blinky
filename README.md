![Static Badge](https://img.shields.io/badge/MCU-PIC10F322-green "MCU:PIC10F322")
![Static Badge](https://img.shields.io/badge/IDE-MPLAB_X_V6.20-green "IDE:MPLAB_X_V6.20")

# PIC10Blinky #

Blink an LED on the Microchip PIC10F322.
Specifically, the SOT23-6 version.

## Pinout ##

| Pin | Function | Connection            |
|-----|----------|-----------------------|
| 1   | RA0      | LED via 330R resistor |
| 2   | Vss      | GND                   |
| 3   | RA1      |                       |
| 4   | RA2      |                       |
| 5   | Vdd      | +5V                   |
| 6   | RA3/MCLR |                       |

Programmer is connected to pins 1 (ICSPDAT), 2 (GND), 3 (ICSPCLK), 5 (+5V) and 6 (/MCLR).

## Toolchain ##

Microchip MPLAB X V6.20 and xc8 V3.10.

