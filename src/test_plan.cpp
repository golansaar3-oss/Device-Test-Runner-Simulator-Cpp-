#include "test_plan.hpp"
#include <utility>

TestPlan::TestPlan(std::vector<std::unique_ptr<TestStep>> steps) : steps(std::move(steps))
{
}

const std::vector<std::unique_ptr<TestStep>>& TestPlan::getSteps() const
{
    return steps;
}

size_t TestPlan::size() const
{
    return steps.size();
}