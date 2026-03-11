#include "validation_result.hpp"



void ValidationResult::addError(const ValidationError& error)
{
    errors.push_back(error);
}

bool ValidationResult::isValid() const
{
    return errors.empty();
}

const std::vector<ValidationError>& ValidationResult::getErrors() const
{
    return errors;
}