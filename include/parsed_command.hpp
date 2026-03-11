#pragma once
#include <string>
#include <vector>
#include <cstddef>

class ParsedCommand

{
public:
    ParsedCommand(size_t lineNumber,const std::string& originalLine, const std::string& commandName,const std::vector<std::string>& arguments);

    size_t getLineNumber() const;
    const std::string& getOriginalLine() const;
    const std::string& getCommandName() const;
    const std::vector<std::string>& getArguments() const;




private:
    size_t lineNumber;
    std::string commandName;
    std::string originalLine;
    std::vector<std::string> arguments;

};