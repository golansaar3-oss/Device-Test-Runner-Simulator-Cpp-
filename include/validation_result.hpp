#pragma once

#include <vector>

#include "validation_error.hpp"

class ValidationResult
{
public:
    void addError(const ValidationError& error);
    bool isValid() const;
    const std::vector<ValidationError>& getErrors() const;


private:
    std::vector<ValidationError> errors;

};