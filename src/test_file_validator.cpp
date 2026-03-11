#include <string>

#include "test_file_validator.hpp"
#include "validation_error.hpp"
#include "validation_error_type.hpp"


ValidationResult TestFileValidator::validate(const std::vector<ParsedCommand>& commands)
{
    ValidationResult result;
    for( const ParsedCommand& command : commands)
    {
        const std::string commandName = command.getCommandName();
        if(commandName == "SET_VOLTAGE")
        {
            validateSetVoltage(command,result);
        }
        else if(commandName =="CHECK_THRESHOLD")
        {
            validateCheckThreshold(command,result);
        }
        else // unknown command
        {
            result.addError(ValidationError(
                command.getLineNumber(),
                command.getOriginalLine(),
                "Unknown command, " + commandName,
                ValidationErrorType::UNKNOWN_COMMAND));
        }
    }

    return result;
}


void TestFileValidator::validateSetVoltage(const ParsedCommand& command,ValidationResult& result)
{
    const std::vector<std::string>& arguments = command.getArguments();
    
    if(arguments.size() != 1)
    {
        result.addError(
            ValidationError(
                command.getLineNumber(),
                command.getOriginalLine(),
                "SET_VOLTAGE expects exactly 1 argument.",
                ValidationErrorType::INVALID_ARGUMENT_COUNT));
        return;
    }
    if (!isValidNumber(arguments[0]))
    {
        result.addError(
            ValidationError(
                command.getLineNumber(),
                command.getOriginalLine(),
                "SET_VOLTAGE argument must be a valid number.",
                ValidationErrorType::INVALID_NUMBER));
    }
}


void TestFileValidator::validateCheckThreshold(const ParsedCommand& command, ValidationResult& result)
{
    const std::vector<std::string>& arguments = command.getArguments();

    if (arguments.size() != 2)
    {
        result.addError(
            ValidationError(
                command.getLineNumber(),
                command.getOriginalLine(),
                "CHECK_THRESHOLD expects exactly 2 arguments.",
                ValidationErrorType::INVALID_ARGUMENT_COUNT));
        return;
    }

    if (!isValidNumber(arguments[0]) || !isValidNumber(arguments[1]))
    {
        result.addError(
            ValidationError(
                command.getLineNumber(),
                command.getOriginalLine(),
                "CHECK_THRESHOLD arguments must be valid numbers.",
                ValidationErrorType::INVALID_NUMBER));
        return;
    }

    double minValue = std::stod(arguments[0]);
    double maxValue = std::stod(arguments[1]);

    if (minValue > maxValue)
    {
        result.addError(
            ValidationError(
                command.getLineNumber(),
                command.getOriginalLine(),
                "CHECK_THRESHOLD requires min value to be less than or equal to max value.",
                ValidationErrorType::SEMANTIC_ERROR));
    }
}

bool TestFileValidator::isValidNumber(const std::string& value)
{
 try
    {
        size_t processedCharacters = 0;
        std::stod(value, &processedCharacters);
        return processedCharacters == value.size();
    }
    catch (...)
    {
        return false;
    }
}