
# Thévenin and Norton Equivalent Circuit Calculator

## Project Overview

This project implements an electrical circuit calculator in C for determining Thévenin and Norton equivalent values for two predefined DC resistive circuit configurations.

The program applies fundamental circuit analysis principles, including Ohm's law, voltage division, parallel resistance and source equivalence.

It provides a console-based interface for entering electrical parameters, performing calculations and displaying the equivalent voltage, current and resistance.

## Features

- Thévenin equivalent voltage calculation
- Thévenin equivalent resistance calculation
- Norton equivalent current calculation
- Norton equivalent resistance calculation
- Support for two predefined circuit configurations
- Voltage divider and parallel resistance calculations
- Input validation for numerical values
- Interactive circuit selection menu
- Repeated calculations without restarting
- Supporting circuit documentation and test data

## Project Structure

```text
thevenin-norton-circuit-calculator/
├── src/
│   └── circuit_calculator.c
├── docs/
│   ├── README.md
│   ├── thevenin-norton-circuit-overview.pdf
│   ├── circuit-calculator-flowchart.pdf
│   └── circuit-calculator-test-data.xlsx
├── README.md
├── .gitignore
└── LICENSE
```

The `src/` directory contains the C implementation.

The `docs/` directory contains the circuit overview, program flowchart and testing evidence.

## How It Works

### 1. Circuit Selection

The program supports two predefined circuit configurations.

**Circuit 1 — Voltage-Source Circuit**

A voltage source connected to two resistors forming a voltage divider, with the output taken across R1.

**Circuit 2 — Current-Source Circuit**

A current source feeding two parallel resistors.

The user selects the required configuration and enters the electrical parameters.

### 2. Thévenin Equivalent Voltage

For the voltage-source configuration, the Thévenin voltage is calculated using:

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

For the supported circuit configurations, the equivalent resistance is calculated using:

```text
Rt = (R1 × R2) / (R1 + R2)
```

### 4. Norton Equivalent Current

The Norton current is calculated using:

```text
In = Vt / Rt
```

For the current-source configuration, the Norton current equals the specified source current.

### 5. Norton Equivalent Resistance

The Thévenin and Norton equivalent resistances are equal:

```text
Rn = Rt
```

## Example Calculation

Consider the voltage-source configuration with:

```text
Supply voltage = 12 V
R1 = 1000 Ω
R2 = 2000 Ω
```

### Thévenin Voltage

```text
Vt = 12 × 1000 / (1000 + 2000)
Vt = 4 V
```

### Equivalent Resistance

```text
Rt = (1000 × 2000) / (1000 + 2000)
Rt = 666.667 Ω
```

### Norton Current

```text
In = 4 / 666.667
In = 0.006 A
```

### Norton Resistance

```text
Rn = 666.667 Ω
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

The program displays an interactive menu for selecting a circuit configuration and entering the required electrical values.

## Testing

The calculator was developed with supporting calculation test data to evaluate its results.

Testing includes:

1. Thévenin voltage calculations
2. Equivalent resistance calculations
3. Norton current calculations
4. Norton resistance calculations
5. Input validation
6. Different circuit parameter values

The original testing spreadsheet is available in the project documentation.

## Documentation

Supporting project files are available in the [documentation folder](docs/README.md).

### Circuit Overview

[View Thévenin and Norton Circuit Overview](docs/thevenin-norton-circuit-overview.pdf)

Original circuit analysis documentation supporting the implemented configurations.

### Program Flowchart

[View Program Flowchart](docs/circuit-calculator-flowchart.pdf)

Flowchart illustrating the program's calculation process and logical structure.

### Calculation Test Data

[View Calculation Test Data](docs/circuit-calculator-test-data.xlsx)

Spreadsheet containing calculation testing evidence.

## Limitations

- Only two predefined circuit configurations are supported.
- The program does not analyse arbitrary electrical networks.
- Components are assumed to be ideal.
- Calculations are limited to DC resistive circuits.
- Numerical inputs must be positive.
- Calculations use single-precision floating-point arithmetic.
- The program operates through a console interface without circuit simulation or graphical editing.

## Skills Demonstrated

- C programming
- Electrical circuit analysis
- Thévenin and Norton equivalent circuits
- Ohm's law and voltage division
- Parallel resistance calculations
- Mathematical problem-solving
- Functions and modular programming
- Input validation and error handling
- Software testing and verification
- Technical documentation
