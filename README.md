
# Thévenin and Norton Equivalent Circuit Calculator

## Project Overview

This project implements an electrical circuit calculator in C for determining Thévenin and Norton equivalent values for two predefined DC resistive circuit configurations.

The program applies fundamental circuit analysis principles, including Ohm's law, voltage division, parallel resistance and source equivalence.

It provides a console-based interface for entering circuit parameters, performing calculations and displaying the equivalent voltage, current and resistance values.

## Features

- Thévenin equivalent voltage calculation
- Thévenin equivalent resistance calculation
- Norton equivalent current calculation
- Norton equivalent resistance calculation
- Support for two predefined circuit configurations
- Voltage divider and parallel resistance calculations
- Input validation for positive numerical values
- Interactive menu for selecting circuit configurations
- Repeated calculations without restarting the program
- Console output displaying calculated electrical quantities

## Project Structure

```text
thevenin-norton-circuit-calculator/
├── src/
│   └── circuit_calculator.c
├── README.md
├── .gitignore
└── LICENSE
```

The `src/` directory contains the C implementation of the circuit calculator.

## How It Works

### 1. Circuit Selection

The program provides two circuit configurations:

**Circuit 1 — Voltage-Source Circuit**

A voltage source connected to two resistors forming a voltage divider, with the output taken across R1.

**Circuit 2 — Current-Source Circuit**

A current source feeding two parallel resistors.

The user selects a configuration and enters the required electrical values.

### 2. Thévenin Equivalent Voltage

For the voltage-source circuit, the Thévenin voltage is determined using the voltage divider equation:

```text
Vt = V × R1 / (R1 + R2)
```

Where:

- Vt = Thévenin equivalent voltage (V)
- V = Supply voltage (V)
- R1 = First resistance (Ω)
- R2 = Second resistance (Ω)

For the current-source configuration:

```text
Vt = I × Rt
```

Where I is the supply current.

### 3. Thévenin Equivalent Resistance

For both supported configurations, the equivalent resistance is calculated using the parallel resistance formula:

```text
Rt = (R1 × R2) / (R1 + R2)
```

The resistance calculation is based on the circuit configurations implemented in the program.

### 4. Norton Equivalent Current

The Norton equivalent current is calculated using:

```text
In = Vt / Rt
```

For the current-source configuration, the Norton current equals the specified source current.

### 5. Norton Equivalent Resistance

The Thévenin and Norton equivalent resistances are equal:

```text
Rn = Rt
```

This relationship allows the program to determine equivalent voltage-source and current-source representations.

## Example Calculation

Consider the voltage-source configuration with the following inputs:

```text
Supply voltage = 12 V
R1 = 1000 Ω
R2 = 2000 Ω
```

The calculated Thévenin voltage is:

```text
Vt = 12 × 1000 / (1000 + 2000)
Vt = 4 V
```

Equivalent resistance:

```text
Rt = (1000 × 2000) / (1000 + 2000)
Rt = 666.667 Ω
```

Norton current:

```text
In = 4 / 666.667
In = 0.006 A
```

Norton resistance:

```text
Rn = 666.667 Ω
```

### Expected Program Output

```text
Vt: 4.000 V
Rt: 666.667 ohms
In: 0.006 A
Rn: 666.667 ohms
```

## Building and Running

The program is written in C and can be compiled using GCC.

### Compile

From the repository root:

```bash
gcc -std=c11 src/circuit_calculator.c -o circuit_calculator
```

### Run

On Linux or macOS:

```bash
./circuit_calculator
```

On Windows:

```powershell
.\circuit_calculator.exe
```

### Program Menu

The program displays:

```text
Thevenin / Norton Equivalent Calculator

1. Voltage-source circuit
2. Current-source circuit
0. Exit
```

Select a circuit configuration and enter the requested supply and resistance values.

The program displays the calculated equivalent values and returns to the menu.

## Input Validation

The calculator checks that:

- The selected menu option is valid
- Numerical inputs are positive
- Invalid or non-numeric inputs are rejected
- Additional characters are not accepted as part of a valid numerical input

Invalid numerical values prompt the user to enter a valid positive number.

## Limitations

- Only two predefined circuit configurations are supported.
- The calculator does not analyse arbitrary circuit networks.
- Components are assumed to be ideal.
- Calculations are limited to DC resistive circuit analysis.
- Input values must be positive.
- Results use single-precision floating-point arithmetic.
- The program does not provide a graphical circuit editor or simulation environment.

## Skills Demonstrated

- C programming
- Electrical circuit analysis
- Thévenin and Norton equivalent circuits
- Ohm's law and voltage division
- Parallel resistance calculations
- Functions and modular programming
- Pointers and parameter passing
- Input validation and error handling
- Mathematical problem-solving
- Software development for engineering applications
