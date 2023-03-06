#include "advancedCalculator.hpp"

ErrorCode process(std::string input, double* out) {
    char type;
    double a;
    double b;

    auto find_string_it = input.find_first_of("+-/*%$!^");
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
        { el.second(a, b);
        return ErrorCode::OK;
     } });
}