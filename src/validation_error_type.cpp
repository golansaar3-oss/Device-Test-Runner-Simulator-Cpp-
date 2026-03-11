#include "validation_error_type.hpp"


std::string to_string(ValidationErrorType error)
{
    switch (error)
    {
    case ValidationErrorType::UNKNOWN_COMMAND:
        return "Unknown command";
    case ValidationErrorType::INVALID_ARGUMENT_COUNT:
        return "Invalid argument count";
    case ValidationErrorType::INVALID_NUMBER:
        return "Invalid number";
    case ValidationErrorType::SEMANTIC_ERROR:
        return "Semantic error";
            
    default:
        return "Unknown validation error";
    }
}