#include "advancedCalculator.hpp"

#include <algorithm>

std::string eraseSpaces(std::string input)
{
    input.erase(std::remove_if(input.begin(), 
                              input.end(),
                              [](unsigned char x){return std::isspace(x);}),
               input.end());

    return input;
}

ErrorCode process(std::string input, double* out)
{
    return ErrorCode::OK;
}

using specMap = std::map<char, std::function<void()>>;
specMap actionsHolder;
