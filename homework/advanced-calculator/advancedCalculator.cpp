#include "advancedCalculator.hpp"

std::map<char, std::function<double(const double&, const double&)>>
    mapOfType = {
        {'+', [](const auto& a, const auto& b) -> double { return a + b; }},
        {'*', [](const auto& a, const auto& b) -> double { return a * b; }},
        {'/', [](const auto& a, const auto& b) -> double { return a / b; }},
        {'-', [](const auto& a, const auto& b) -> double { return a - b; }},
        {'%', [](const auto& a, const auto& b) -> double { return std::fmod(a, b); }},
        {'!', [](const auto& a, const auto& b) -> double { return std::tgamma(a + 1); }},
        {'^', [](const auto& a, const auto& b) -> double { return std::pow(a, b); }},
        {'$', [](const auto& a, const auto& b) -> double { return std::pow(a, 1.0 / b); }},
};

ErrorCode process(std::string input, double* out) {
    char type;
    double a;
    double b;

    auto find_string_it = input.find_first_of("+-/*%$!^", 1);

    if (find_string_it != std::string::npos) {
        type = input[find_string_it];
        std::string a_string = input.substr(0, find_string_it);
        std::string b_string = input.substr(find_string_it, input.size());
        try {
            a = std::stod(a_string);
            b = std::stod(b_string);
        } catch (std::invalid_argument) {
            return ErrorCode::BadCharacter;
        }
    } else {
        return ErrorCode::BadFormat;
    }

    switch (type) {
    case '/':
        if (b == 0) {
            return ErrorCode::DivideBy0;
        }
    case '%':
        if (a == 0 || b == 0) {
            return ErrorCode::ModuleOfNonIntegerValue;
        }
    case '$':
        if (a < 0) {
            return ErrorCode::SqrtOfNegativeNumber;
        }
    }

    std::for_each(mapOfType.begin(), mapOfType.end(), [&](const auto& el) {
        if (el.first == type) 
        { *out = el.second(a, b);
     } });
    return ErrorCode::OK;
}