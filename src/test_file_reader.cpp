#include <fstream>
#include <stdexcept>

#include "test_file_reader.hpp"

std::vector<std::string> TestFileReader::readLines(const std::string& filePath)
{
    std::ifstream file(filePath);

    if(!file.is_open())
    {
        throw std::runtime_error("Failed to open file: " + filePath);
    }
    std::vector<std::string> lines;
    std::string line;

    while(std::getline(file, line))
    {
        lines.push_back(line);
    }

    return lines;
}