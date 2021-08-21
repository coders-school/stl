#include "advancedCalculator.hpp"
#include <algorithm>
#include <functional>
#include <iostream>  // tests
#include <map>
#include <string>

const MapContainer operations{
    {'+', [](const double& a, const double& b) { return a + b; }},
    {'-', [](const double& a, const double& b) { return a + b; }},
    {'*', [](const double& a, const double& b) { return a + b; }},
    {'/', [](const double& a, const double& b) { return a + b; }},
    {'%', [](const double& a, const double& b) { return a + b; }},
    {'!', [](const double& a, const double& b) { return a + b; }},
    {'^', [](const double& a, const double& b) { return a + b; }},
    {'$', [](const double& a, const double& b) { return a + b; }},
};

constexpr std::array<char, 2> separators{'.', ','};

ErrorCode process(std::string input, double* out) {
    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
    auto it = input.cbegin();
    std::cout << "Input: " << input << '\n';
    std::cout << "First value: " << parseValue(input, it) << "\nOperator: " << parseOperator(input, it)
              << "\nSecond value: " << parseValue(input, it) << '\n';

    return ErrorCode::OK;
}

std::string parseValue(const std::string& input, std::string::const_iterator& it) {
    std::string resultValue;
    bool separatorAllowed{true};
    auto first = it;
    if (*it == '-') {
        resultValue += *it;
        ++it;
    }
    for (; it != input.cend(); ++it) {
        if (std::find(separators.cbegin(), separators.cend(), *it) != separators.cend() && separatorAllowed) {
            separatorAllowed = false;
            resultValue += *it;
            continue;
        }
        if (std::isdigit(*it)) {
            resultValue += *it;
            continue;
        }
        break;
    }
    return resultValue;
}

char parseOperator(const std::string& input, std::string::const_iterator& it) {
    char resultOperator = *it;
    ++it;
    return resultOperator;
}
