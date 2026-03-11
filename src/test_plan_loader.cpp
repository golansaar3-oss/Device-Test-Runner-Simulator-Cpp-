#include <exception>
#include <optional>
#include <vector>

#include "test_plan_loader.hpp"
#include "test_file_reader.hpp"
#include "test_file_parser.hpp"
#include "test_file_validator.hpp"
#include "test_step_factory.hpp"
#include "test_plan.hpp"

LoadResult TestPlanLoader::loadFromFile(const std::string& filePath)
{
    try
    {
        // read file
        std::vector<std::string> lines = TestFileReader::readLines(filePath);
        
        // parse commands
        std::vector<ParsedCommand> commands = TestFileParser::parse(lines);

        //validate commands
        ValidationResult validationResult = TestFileValidator::validate(commands);

        if(!validationResult.isValid())
        {
            return LoadResult(
                false,
                std::nullopt,
                validationResult,
                "Validation failed."
            );
        }

        // validation passed -> create steps
        std::vector<std::unique_ptr<TestStep>> steps;

        for(const ParsedCommand& command : commands)
        {
            steps.push_back(TestStepFactory::createStep(command));
        }

        // build test plan
        TestPlan plan(std::move(steps));

        // return success result
        return LoadResult(
            true,
            std::optional<TestPlan>(std::move(plan)),
            ValidationResult(),
            ""
        );
    }
    catch(const std::exception& e)
    {
       // File reading or factory failure
        return LoadResult(
            false,
            std::nullopt,
            ValidationResult(),
            e.what()
        );
    }
    
}