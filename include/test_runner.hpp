#pragma once

#include "state.hpp"
#include "device_simulator.hpp"
#include "test_plan.hpp"

class TestRunner
{
public:
    explicit TestRunner(TestPlan plan);

    void start();
    State getState() const;

private:
    void run();
    
    State currentState;
    DeviceSimulator device;
    TestPlan plan;


};
