# Device Test Runner Simulator

A small C++ project that implements a finite state machine (FSM) based device test runner.

The project simulates a device and executes a sequence of test steps such as setting a voltage and verifying it is within a threshold.

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