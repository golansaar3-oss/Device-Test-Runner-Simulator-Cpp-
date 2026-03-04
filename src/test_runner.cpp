#include "test_runner.hpp"
#include <iostream>
#include <exception>

TestRunner::TestRunner() : currentState(State::IDLE), device(),setVoltageStep(8.0),checkThresholdStep(4.9,5.1),steps{ &setVoltageStep, &checkThresholdStep}
{

}

void TestRunner::Start()
{
    if (currentState != State::IDLE)
    {
        std::cout << "System is in state: " << to_string(currentState)
          << ", must be in IDLE\n";
        return;
    }
    currentState = State::RUNNING;
    run();
}

void TestRunner:: run()
{
    try
    {
        for (TestStep* step : steps)
        {
            std::cout << step->name();
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