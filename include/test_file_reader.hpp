#pragma once
#include <string>
#include <vector>

class TestFileReader
{
    // this is static class which responsible for: open file>read lines> return vector<string>
public:
    static std::vector<std::string> readLines(const std::string& filePath);

};