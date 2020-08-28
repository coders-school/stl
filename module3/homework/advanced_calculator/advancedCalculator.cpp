#include "advancedCalculator.hpp"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <functional>
#include <map>
#include <regex>

std::map<char, std::function<double(double, double)>> commands{{'+', std::plus<double>()},
                                                               {'-', std::minus<double>()},
                                                               {'*', std::multiplies<double>()},
                                                               {'/', std::divides<double>()},
                                                               {'%', std::modulus<int>()},
                                                               {'^', [](double base, double exponent) { return pow(base, exponent); }},
                                                               {'$', [](double num, double root) { return pow(num, 1.0 / root); }},
                                                               {'!', [](double num, double whatever = 0.0) { return tgamma(num + 1.0); }}};

void exportKeys(std::string& operators) {
    for (const auto& el : commands) {
        operators.push_back(el.first);
    }
}

ErrorCode process(std::string input, double* out) {
    std::string operators{" ,."};
    exportKeys(operators);

    if (std::any_of(input.cbegin(), input.cend(), [&operators](char letter) {
            return std::find(operators.cbegin(), operators.cend(), letter) == operators.cend() && !isdigit(letter);
        })) {
        return ErrorCode::BadCharacter;
    }

    const std::regex commandRegex(R"((([-]?\d+[.]*\d*)[ ]*([+\-*\/$^])[ ]*([-]?\d+[.]*\d*))|(([-]?\d+[.]*\d*)[ ]*!))");
    std::smatch match;

    if (std::regex_search(input, match, commandRegex)) {
        if (match[0] != input) {
            return ErrorCode::BadFormat;
        } else if (match[1] == input && stod(match[4]) == 0.0) {
            return ErrorCode::DivideBy0;
        }
        return ErrorCode::OK;
    }
    return ErrorCode::BadFormat;
}
