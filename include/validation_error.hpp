#pragma once

#include <string>
#include <cstddef>

#include "validation_error_type.hpp"

class ValidationError
{
public:
    ValidationError(size_t lineNumber,
                    const std::string& originalLine,
                    const std::string& message,
                    ValidationErrorType errorType);
    
    size_t getLineNumber() const;
    const std::string& getOriginalLine() const;
    const std::string& getMessage() const;
    ValidationErrorType getErrorType() const;


private:
    size_t lineNumber;
    std::string originalLine;
    std::string message;
    ValidationErrorType errorType;

};