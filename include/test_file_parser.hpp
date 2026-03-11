#pragma once

#include <vector>
#include <string>

#include "parsed_command.hpp"
class TestFileParser
{
public:
    static std::vector<ParsedCommand> parse(const std::vector<std::string>& lines);


private:
    static bool isIgnorableLine(const std::string& line);
    static std::vector<std::string> tokenize(const std::string& line);

};