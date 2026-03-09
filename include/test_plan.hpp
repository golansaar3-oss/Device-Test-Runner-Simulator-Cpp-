#pragma once
#include <vector>
#include <memory>
#include "test_step.hpp"


class TestPlan
{

public:
    // Construct a test plan from a prepared list of steps
    explicit TestPlan(std::vector<std::unique_ptr<TestStep>> steps);

    // Access the steps(read only)
    const std::vector<std::unique_ptr<TestStep>>& getSteps() const;

    // number of steps in plan
    size_t size() const;

private:
        std::vector<std::unique_ptr<TestStep>> steps;

};