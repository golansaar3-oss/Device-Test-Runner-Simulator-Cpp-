#include <iostream>
#include <string>

#include "test_plan_loader.hpp"
#include "test_runner.hpp"
#include "state.hpp"
#include "validation_error_type.hpp"

int main()
{
    const std::string filePath = "testConfig.txt";

    LoadResult loadResult = TestPlanLoader::loadFromFile(filePath);

    if (!loadResult.isSuccess())
    {
        std::cout << "Failed to load test plan.\n";

        if (!loadResult.getMessage().empty())
        {
            std::cout << loadResult.getMessage() << '\n';
        }

        const ValidationResult& validationResult = loadResult.getValidationResult();

        if (!validationResult.isValid())
        {
            for (const ValidationError& error : validationResult.getErrors())
            {
                std::cout << "Line " << error.getLineNumber() << ": "
                          << error.getOriginalLine() << '\n';

                std::cout << "Error type: "
                          << to_string(error.getErrorType()) << '\n';

                std::cout << "Message: "
                          << error.getMessage() << "\n\n";
            }
        }

        return 1;
    }

    TestRunner runner(loadResult.takePlan());
    runner.start();

    std::cout << "Final state: " << to_string(runner.getState()) << '\n';

    return 0;
}