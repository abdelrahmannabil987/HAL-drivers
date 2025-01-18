# DC Motor Control Interface (Header File)

## Overview

This repository contains a header file for a DC motor control interface, designed for use in embedded systems applications. The interface simplifies motor control through the use of standard H-bridge configurations. 

By abstracting the motor control logic into functions, this module ensures safe and efficient operation of DC motors, protecting the microcontroller (MCU) from high currents and enabling bidirectional motor control with a simple setup.

---

## Features

- **Clockwise Rotation (CW):** Drive the motor in a clockwise direction using `DC_MOTOR_voidCW()`.
- **Counterclockwise Rotation (CCW):** Drive the motor in a counterclockwise direction using `DC_MOTOR_voidCCW()`.
- **Motor Stop:** Instantly stop the motor using `DC_MOTOR_voidSTOP()`.
- **H-Bridge Safety:** Includes recommendations for using an H-bridge circuit to protect the MCU and enable bidirectional motor control.

---

## Getting Started

### Requirements

- Microcontroller with GPIO pins (e.g., STM32, AVR, PIC).
- H-bridge circuit (recommended).
- DC motor.

---
