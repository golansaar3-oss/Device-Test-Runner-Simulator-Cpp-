# Device Test Runner Simulator

A C++ project that implements a **finite state machine (FSM) based device test runner**.

The system simulates a device and executes a sequence of test steps such as setting a voltage and verifying that it is within a threshold.  
Test steps are now loaded from an external configuration file and processed through a structured loading pipeline.

---

# Architecture

The system is built around two main concepts:

1. **Finite State Machine (FSM)** controlling test execution
2. **Test Plan Loading Pipeline** responsible for reading, parsing, validating, and constructing test steps

---

# Finite State Machine

<p align="center">
  <img src="diagrams/FSM.svg" width="600">
</p>

The runner starts in `IDLE`.

When `start()` is called:

```
IDLE → RUNNING
```

The runner executes each step in the loaded `TestPlan`.

The final state depends on the result of the executed steps:

```
RUNNING → PASSED
RUNNING → FAILED
RUNNING → ERROR
```

---

# Class Design

<p align="center">
  <img src="diagrams/ClassUML.svg" width="700">
</p>

### Execution Layer

- **TestRunner**  
  Executes a `TestPlan` using the FSM.

- **TestPlan**  
  Holds a sequence of `TestStep` objects.

- **TestStep (abstract)**  
  Interface implemented by concrete test steps.

- **Concrete Steps**
  - `SetVoltageStep`
  - `CheckThresholdStep`

---

# Test Plan Loading Pipeline

Test plans are now loaded from configuration files using a modular pipeline.

```
Configuration File
        ↓
TestFileReader
        ↓
TestFileParser
        ↓
TestFileValidator
        ↓
TestStepFactory
        ↓
TestPlanLoader
        ↓
TestPlan
        ↓
TestRunner
```

### Components

**TestFileReader**
- Reads raw lines from the configuration file.

**TestFileParser**
- Converts raw lines into structured `ParsedCommand` objects.

**TestFileValidator**
- Performs syntax and semantic validation.
- Detects:
  - unknown commands
  - invalid argument counts
  - invalid numbers
  - semantic errors (e.g. invalid threshold ranges)

**TestStepFactory**
- Creates concrete `TestStep` objects from validated commands.

**TestPlanLoader**
- Orchestrates the full loading process.
- Returns a `LoadResult` containing:
  - success/failure status
  - validation errors
  - constructed `TestPlan`

---

# Example Test Plan

Example `testConfig.txt`:

```
# Example test configuration

SET_VOLTAGE 5.0
CHECK_THRESHOLD 4.9 5.1

SET_VOLTAGE 3.3
CHECK_THRESHOLD 3.2 3.4
```

Lines starting with `#` are treated as comments and ignored.

---

# Features

- FSM-based test execution  
  `IDLE → RUNNING → PASSED / FAILED / ERROR`

- External configuration file support

- Modular loading pipeline:
  - Reader
  - Parser
  - Validator
  - Factory
  - Loader

- Validation error reporting with line numbers

- Abstract `TestStep` interface for extensibility

- Clear separation of responsibilities following **SOLID principles**

---

# Project Structure

```
diagrams/      FSM and class UML diagrams
include/       header files
src/           implementation files
testConfig.txt example test configuration
```

---

# Build

Compile using `g++`:

```
g++ -std=c++17 -Iinclude src/*.cpp -o main.exe
```

Run:

```
./main.exe
```

---

# Version

Current version: **V2**

### V1
- Test steps defined directly inside `TestRunner`.

### V2
- Added configuration file support.
- Implemented Reader → Parser → Validator → Factory → Loader pipeline.
- Introduced structured validation and error reporting.

---

# Purpose

This project was created as a practice exercise to improve:

- C++ class design
- finite state machine implementation
- modular system architecture
- parsing and validation pipelines
- clean separation of responsibilities
- deterministic programming style commonly used in embedded systems