#include <exception>
#include <iostream>

#include "set_voltage_step.hpp"
#include "device_simulator.hpp"


SetVoltageStep::SetVoltageStep(double voltage) : targetVoltage(voltage)
{
    
}


StepResult SetVoltageStep::execute(DeviceSimulator& device)
{
    try
    {
        device.setVoltage(targetVoltage);
        return StepResult::PASS;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return StepResult::ERROR;
    }
    
}

std::string SetVoltageStep::name() const
{
    return "SetVoltageStep";
}

