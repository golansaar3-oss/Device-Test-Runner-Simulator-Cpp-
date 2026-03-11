#include <utility>
#include <stdexcept>

#include "load_result.hpp"

LoadResult::LoadResult(bool success,
            std::optional<TestPlan> plan,
            ValidationResult validationResult,
            std::string message) :
            success(success),
            plan(std::move(plan)),
            validationResult(std::move(validationResult)),
            message(std::move(message))
{

}

bool LoadResult::isSuccess() const
{
    return success;
}

bool LoadResult::hasPlan() const
{
    return plan.has_value();
}
TestPlan LoadResult::takePlan()
{
    if(!plan.has_value())
    {
        throw std::runtime_error("LoadResult does not contain a TestPlan");
    }
    TestPlan extractedPlan = std::move(plan.value());
    plan.reset();
    return extractedPlan;
}

const ValidationResult& LoadResult::getValidationResult() const
{
    return validationResult;
}

const std::string& LoadResult::getMessage() const
{
    return message;
}