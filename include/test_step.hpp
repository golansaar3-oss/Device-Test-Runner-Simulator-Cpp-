#pragma once

#include "step_result.hpp"

class DeviceSimulator;

class TestStep
{
public:
    virtual ~TestStep() = default;

    virtual StepResult execute(DeviceSimulator& device) = 0;
    virtual const char* name() const = 0;

};