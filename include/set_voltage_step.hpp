#pragma once
#include "test_step.hpp"

class DeviceSimulator;

class SetVoltageStep : public TestStep
{
public:
    SetVoltageStep(double Voltage);
    StepResult execute(DeviceSimulator& device) override;
    const char* name() const override;

private:
    const double targetVoltage;
};