#pragma once

#include <vector>

#include "validation_result.hpp"
#include "parsed_command.hpp"
class TestFileValidator
{
public:
    static ValidationResult validate(const std::vector<ParsedCommand>& commands);

private:
    static void validateSetVoltage(const ParsedCommand& command,ValidationResult& result);
    static void validateCheckThreshold(const ParsedCommand& command, ValidationResult& result);
    static bool isValidNumber(const std::string& value);

};