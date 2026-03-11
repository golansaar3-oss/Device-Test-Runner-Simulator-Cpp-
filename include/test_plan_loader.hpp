#pragma once

#include <string>

#include "load_result.hpp"
class TestPlanLoader
{
public:
static LoadResult loadFromFile(const std::string& filePath);

};