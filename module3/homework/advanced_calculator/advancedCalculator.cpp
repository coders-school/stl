#include <algorithm>
#include <cmath>
#include <functional>
#include <map>
#include <string>

#include "advancedCalculator.hpp"

const std::map<std::string, std::function<double(double, double)>> command = {{"+", std::plus<double>()},
                                                                              {"-", std::minus<double>()},
                                                                              {"*", std::multiplies<double>()},
                                                                              {"/", std::divides<double>()},
                                                                              {"%", std::modulus<double>()},
                                                                              {"^", [](double base, double exp) { return pow(base, exp); }},
                                                                              {"$", [](double base, double root) { return pow(base, 1.0 / root); }}};

bool checkCharacters(std::string input) {
    std::string allowedChars{"0123456789+-/*!$^% "};
    return std::all_of(input.begin(), input.end(),
                       [&](const auto& character) { return std::any_of(allowedChars.begin(), allowedChars.end(),
                                                                       [character](const auto& goodChar) { return character == goodChar; }); });
}