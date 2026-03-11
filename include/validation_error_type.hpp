#pragma once
#include <string>

enum class ValidationErrorType
{
    UNKNOWN_COMMAND,
    INVALID_ARGUMENT_COUNT,
    INVALID_NUMBER,
    SEMANTIC_ERROR

};

std::string to_string(ValidationErrorType error);