#include "state.hpp"
#include <iostream>
#include "test_runner.hpp"

int main()
{
    TestRunner runner;

    runner.Start();

    std::cout << "Final state:" << to_string(runner.getState()) << std::endl;
    return 0;
    
}