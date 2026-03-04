#include "set_voltage_step.hpp"
#include "device_simulator.hpp"
#include <exception>
#include <iostream>



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

const char *SetVoltageStep::name() const
{
    return "SetVoltageStep";
}

