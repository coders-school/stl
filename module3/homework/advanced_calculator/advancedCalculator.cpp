#include "advancedCalculator.hpp"
#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <map>

const std::map<std::string, std::function<double(double, double)>> commands{
    {"+", std::plus<double>()},
    {"-", std::minus<double>()},
    {"*", std::multiplies<double>()},
    {"/", std::divides<double>()},
    {"%", std::modulus<int>()},
    {"^", [](double base, double Pow) { return std::pow(base, Pow); }},
    {"$", [](double base, double Pow) { return std::pow(base, 1.0 / Pow); }}};

bool isBadCharacter(std::string in) {
    constexpr int numberOfCommands = 10;
    constexpr std::array<char, numberOfCommands> calculatorCommands{
        '+', '-', '*', '/', '%', '!', '^', '$', '.', ','};
    return std::any_of(in.begin(), in.end(),
                       [calculatorCommands](char c) {
                           return (std::ispunct(c) &&
                                   (std::find(calculatorCommands.begin(),
                                    calculatorCommands.end(), c) == calculatorCommands.end())) 
                                    || std::isalpha(c);
                       });
}
