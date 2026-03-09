#pragma once

#include <string>
#include "step_result.hpp"

class DeviceSimulator;

class TestStep
{
public:
    virtual ~TestStep() = default;

    virtual StepResult execute(DeviceSimulator& device) = 0;
    virtual std::string name() const = 0;

};