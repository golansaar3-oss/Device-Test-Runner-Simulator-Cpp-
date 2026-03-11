#include "parsed_command.hpp"


ParsedCommand::ParsedCommand(size_t lineNumber,
                            const std::string& originalLine,
                            const std::string& commandName,
                            const std::vector<std::string>& arguments)
: lineNumber(lineNumber),
  originalLine(originalLine),
  commandName(commandName),
  arguments(arguments)
  {
  }

size_t ParsedCommand::getLineNumber() const
{
    return lineNumber;
}

const std::string& ParsedCommand::getOriginalLine() const
{
    return originalLine;
}

const std::string& ParsedCommand::getCommandName() const
{
    return commandName;
}

const std::vector<std::string>& ParsedCommand::getArguments() const
{
    return arguments;
}
