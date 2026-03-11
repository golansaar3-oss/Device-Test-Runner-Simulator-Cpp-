#include "validation_error.hpp"


ValidationError::ValidationError(size_t lineNumber,
                    const std::string& originalLine,
                    const std::string& message,
                    ValidationErrorType errorType) : 
                    lineNumber(lineNumber),
                    originalLine(originalLine),
                    message(message),
                    errorType(errorType)
{
}

size_t ValidationError::getLineNumber() const
{
    return lineNumber;
}
const std::string& ValidationError::getOriginalLine() const
{
    return originalLine;
}

const std::string& ValidationError::getMessage() const
{
    return message;
}

ValidationErrorType ValidationError::getErrorType() const
{
    return errorType;
}