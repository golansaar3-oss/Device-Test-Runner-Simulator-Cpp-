#pragma once

#include "state.hpp"
#include "set_voltage_step.hpp"
#include "check_threshold_step.hpp"
#include <array>
#include "device_simulator.hpp"


class TestRunner
{
public:
    TestRunner();
    void Start();
    State getState() const;

private:
    void run();
    State currentState;
    DeviceSimulator device;
    SetVoltageStep setVoltageStep;
    CheckThresholdStep checkThresholdStep;
    std::array<TestStep*,2> steps;


};
