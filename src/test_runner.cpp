#include <iostream>
#include <exception>
#include <utility>

#include "test_runner.hpp"
#include "step_result.hpp"
#include "state.hpp"
TestRunner::TestRunner(TestPlan plan) : currentState(State::IDLE), device(), plan(std::move(plan))
{
}

void TestRunner::start()
{
    if (currentState != State::IDLE)
    {
        
        std::cout << "System is in state: " << to_string(currentState)
          << ", must be in IDLE\n";
        currentState = State::ERROR;
        return;
    }
    currentState = State::RUNNING;
    run();
}

void TestRunner::run()
{
    try
    {
        for (const auto& step : plan.getSteps())
        {
            std::cout << "Running step: " << step->name() << '\n';
            
            StepResult result = step->execute(device);
            if(result == StepResult::FAIL)
            {
                currentState = State::FAILED;
                return;
            }
            if(result == StepResult::ERROR)
            {
                currentState = State::ERROR;
                return;
            }
        
        }
        currentState = State::PASSED;
    }

    catch(const std::exception& e)
    {
        currentState = State::ERROR;
        std::cerr << e.what() << '\n';
    }
     
}

State TestRunner::getState() const
{
    return currentState;
}