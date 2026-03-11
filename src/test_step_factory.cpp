#include <stdexcept>
#include <string>

#include "test_step_factory.hpp"
#include "set_voltage_step.hpp"
#include "check_threshold_step.hpp"

std::unique_ptr<TestStep> TestStepFactory::createStep(const ParsedCommand& command)
{
    const std::string& name = command.getCommandName();
    const std::vector<std::string>& args = command.getArguments();

    try
    {
        if (name == "SET_VOLTAGE")
        {
            double value = std::stod(args[0]);
            return std::make_unique<SetVoltageStep>(value);
        }
        else if( name == "CHECK_THRESHOLD")
        {
            double minValue = std::stod(args[0]);
            double maxValue = std::stod(args[1]);

            return std::make_unique<CheckThresholdStep>(minValue, maxValue);
        }

        throw std::runtime_error("Unknown command: " + name);
    }
    catch(const std::exception& e)
    {
       throw std::runtime_error(
            "Factory error at line " +
            std::to_string(command.getLineNumber()) +
            ": " +
            command.getOriginalLine() +
            " | " +
            e.what());
    }
    

}