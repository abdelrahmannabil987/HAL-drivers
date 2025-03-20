# LED Matrix HAL Driver for STM32  
A fully functional HAL (Hardware Abstraction Layer) driver to control an 8x8 LED matrix using STM32 microcontrollers. This project provides easy initialization and dynamic pattern display on the matrix using GPIO pins and the SysTick timer.

---

## 🧩 Features

- Control of 8x8 LED matrix (rows and columns).
- Real-time scanning display using multiplexing.
- Customizable GPIO pin configurations.
- Modular code structure for easy integration.
- Suitable for STM32F1 series (tested on STM32F103).

---

## 📂 File Structure

| File                    | Description                                            |
|------------------------|--------------------------------------------------------|
| `main.c`               | Application entry, example to initialize and display   |
| `LEDMTRX_interface.h`  | Public interface (init & display functions)            |
| `LEDMTRX_config.h`     | Pin configuration (PORT, PIN)                          |
| `LEDMTRX_program.c`    | Implementation of matrix control and scanning logic    |
| `GPIO_interface.h`     | GPIO HAL abstraction layer                             |
| `STICK_interface.h`    | SysTick HAL abstraction for delays                     |
| `RCC_interface.h`      | Clock control HAL                                      |
| `README.md`            | Documentation and usage guide                          |

---

## ⚙️ Hardware Setup

- **Matrix Type**: 8x8 LED matrix.
- **Wiring**:  
  - Rows connected to GPIOA Pins 1-8  
  - Columns connected to GPIOB Pins 0,1,5,6,7,8,9,10  
- **Note**: You can change the pin mapping in `LEDMTRX_config.h`.

Example of pin configuration:
```c
#define LEDMTRX_ROW0_PIN	GPIOA,1
#define LEDMTRX_ROW1_PIN	GPIOA,2
...
#define LEDMTRX_COL0_PIN	GPIOB,0
#define LEDMTRX_COL1_PIN	GPIOB,1
...
```

---

## 🛠️ Getting Started

### 1. Clone Repository
```bash
git clone https://github.com/yourusername/LEDMatrix_HAL_Driver.git
```

### 2. Configure Your STM32 Project
- Use STM32CubeIDE, KEIL, or any STM32-compatible IDE.
- Add all `.c` and `.h` files to your project.
- Ensure system clock and GPIO clocks are enabled in `main.c`.

---

## 🚀 Usage Guide

### 1. Initialize the LED Matrix
Call this function once to configure the GPIO pins:
```c
HLEDMTRX_voidInit();
```

### 2. Display Data on the Matrix
Prepare an array of 8 bytes, each byte represents 8 rows of one column (bit = LED ON/OFF):
```c
u8 DataArray[8] = {0, 0, 0, 191, 191, 0, 0, 0};  // Example pattern
HLEDMTRX_voidDisplay(DataArray);
```

This function runs an infinite loop, scanning and displaying the pattern on the matrix.

---

## 📜 How It Works

1. **Multiplexing Technique**:  
   Each column is activated one at a time while setting the row values according to the pattern. This is repeated quickly to give the illusion that all LEDs are ON simultaneously.

2. **Timing**:  
   A 2.5ms delay is used for each column using the SysTick timer for precise timing and stable display.

3. **Functions**:  
   - `DisableAllColumns()`: Turns off all columns before switching.
   - `SetRowValues(u8 value)`: Sets row pins based on bits in the value.

---

## 💡 Example: Custom Pattern

To show a horizontal line in the middle of the matrix:
```c
u8 LinePattern[8] = {
  0b00000000,
  0b00000000,
  0b00000000,
  0b11111111,
  0b11111111,
  0b00000000,
  0b00000000,
  0b00000000
};
HLEDMTRX_voidDisplay(LinePattern);
```

---

## 🧑‍💻 Author

**Abdelrahman Nabil**  
📅 Date: 13 Mar 2025  
📝 Version: V01

