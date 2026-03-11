#pragma once
#include "test_plan.hpp"
#include "validation_result.hpp"

#include <string>
#include <vector>
#include <optional>

class LoadResult
{
public:
LoadResult(bool success,
            std::optional<TestPlan> plan,
            ValidationResult validationResult,
            std::string message);


bool isSuccess() const;
bool hasPlan() const;
TestPlan takePlan();

const ValidationResult& getValidationResult() const;
const std::string& getMessage() const;

private:
    bool success;
    std::optional<TestPlan> plan;
    ValidationResult validationResult;
    std::string message;


};