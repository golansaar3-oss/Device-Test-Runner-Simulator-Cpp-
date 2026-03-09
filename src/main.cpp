#include <iostream>
#include <memory>
#include <vector>
#include <utility>

#include "set_voltage_step.hpp"
#include "check_threshold_step.hpp"
#include "test_plan.hpp"
#include "test_runner.hpp"
#include "state.hpp"

int main()
{
    std::vector<std::unique_ptr<TestStep>> steps;

    steps.push_back(std::make_unique<SetVoltageStep>(5.0));
    steps.push_back(std::make_unique<CheckThresholdStep>(5.2 , 5.1));

    TestPlan plan(std::move(steps));
    TestRunner runner(std::move(plan));

    runner.start();

    std:: cout << "Final state: " << to_string(runner.getState()) << '\n';

    return 0;



}