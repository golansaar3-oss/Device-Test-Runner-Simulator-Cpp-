#pragma once

#include <memory>

#include "test_step.hpp"
#include "parsed_command.hpp"


class TestStepFactory
{
public:       
    
    static std::unique_ptr<TestStep> createStep(const ParsedCommand& command);

};