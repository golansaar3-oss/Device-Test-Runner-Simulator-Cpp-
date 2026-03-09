#pragma once
#include "test_step.hpp"

class DeviceSimulator;

class CheckThresholdStep : public TestStep
{
public:
    CheckThresholdStep(double minVolt, double maxVolt);
    StepResult execute(DeviceSimulator& device) override;
    std::string name() const override;

private:
const double minVoltage;
const double maxVoltage;

};