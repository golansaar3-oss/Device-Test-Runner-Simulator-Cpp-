#include <sstream>
#include <cctype>

#include "test_file_parser.hpp"

std::vector<ParsedCommand> TestFileParser::parse(const std::vector<std::string>& lines)
{
    std::vector<ParsedCommand> commands;
    for (size_t i = 0; i< lines.size(); ++i)
    {
        const std::string& line = lines[i];
        if(isIgnorableLine(line))
        {
            continue;
        }
        std::vector<std::string> tokens = tokenize(line);

        if(tokens.empty())
        {
            continue;
        }

        const std::string& commandName = tokens[0];
        std::vector<std::string> arguments(tokens.begin() + 1, tokens.end());

        commands.emplace_back(i + 1, line, commandName, arguments);

    }

    return commands;
}


bool TestFileParser::isIgnorableLine(const std::string& line)
{
    size_t firstNonWhiteSpace = 0;

    // skip white spaces
    while(firstNonWhiteSpace < line.size() &&
            std::isspace(static_cast<unsigned char>(line[firstNonWhiteSpace])))
        {
            ++firstNonWhiteSpace;
        }
    
    if(firstNonWhiteSpace == line.size())
    {
        return true;
    }

    return line[firstNonWhiteSpace] == '#';
}

std::vector<std::string> TestFileParser::tokenize(const std::string& line)
{
    std::vector<std::string> tokens;
    std::istringstream stream(line);
    std::string token;
    
    while(stream >> token)
    {
        tokens.push_back(token);
    }

    return tokens;
}