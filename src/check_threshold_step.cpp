#include "check_threshold_step.hpp"
#include "device_simulator.hpp"

CheckThresholdStep::CheckThresholdStep(double minVolt, double maxVolt) : minVoltage(minVolt), maxVoltage(maxVolt)
{

}

StepResult CheckThresholdStep::execute(DeviceSimulator& device)
{
    const double measuredVoltage = device.readVoltage();
    if(measuredVoltage < minVoltage || measuredVoltage > maxVoltage)
        return StepResult::FAIL;

    return StepResult::PASS;
}

std::string CheckThresholdStep::name() const
{
    return "CheckThresholdStep";
}