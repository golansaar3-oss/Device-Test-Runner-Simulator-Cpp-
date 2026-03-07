# Device Test Runner Simulator

A small C++ project that implements a finite state machine (FSM) based device test runner.

The project simulates a device and executes a sequence of test steps such as setting a voltage and verifying it is within a threshold.

## Architecture

The system is built around a simple finite state machine controlling the
execution of test steps.

### Finite State Machine

<p align="center">
  <img src="diagrams/FSM.svg" width="600">
</p>

The runner starts in `IDLE`.  
When `Start()` is called it transitions to `RUNNING` and executes all test steps.
The final state depends on the result of the executed steps.

### Class Design

<p align="center">
  <img src="diagrams/ClassUML.svg" width="700">
</p>

`TestRunner` orchestrates execution while each `TestStep`
implements a specific test operation.

## Features

- FSM-based test execution (IDLE → RUNNING → PASSED / FAILED / ERROR)
- Abstract `TestStep` interface
- Concrete test steps:
  - `SetVoltageStep`
  - `CheckThresholdStep`
- Deterministic design (no dynamic allocation)

## Project Structure

diagrams/ - FSM and class UML diagrams
include/ – header files  
src/ – implementation files  

## Build
Compile using `g++`:

## Version

Current version: **V1**

In this version the test steps are defined directly inside `TestRunner`.  
Future versions will support loading test definitions from configuration files.

## Purpose

This project was created as a practice exercise to improve:

- C++ class design
- finite state machine implementation
- modular system architecture
- deterministic programming style commonly used in embedded systems