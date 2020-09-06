#include "advancedCalculator.hpp"

#include <algorithm>
#include <cmath>
#include <functional>
#include <map>
#include <sstream>

std::map<char, std::function<double(double, double)>> operation = {
    {'+', std::plus<double>()},
    {'-', std::minus<double>()},
    {'*', std::multiplies<double>()},
    {'/', std::divides<double>()},
    {'^', [](auto first, auto second) { return pow(first, second); }},
    {'$', [](auto first, auto second) { return pow(first, 1.0 / second); }},
    {'%', std::modulus<int>()},
    {'!', [](auto first, auto second) {
         if (first < 0) {
             return 1.0;
         }
         return first * tgamma(first);
     }}};

ErrorCode process(std::string input, double* out) {
    double first = 0;
    double second = 0;
    char action;

    removeSpaces(input);
    if (!checkCharacter(input)) {
        return ErrorCode::BadCharacter;
    }
    if (!checkComas(input)) {
        return ErrorCode::BadFormat;
    }

    ErrorCode error = takeNumbers(input, first, action, second);
    if (error != ErrorCode::OK) {
        return error;
    }

    if (action == '/' && second == 0) {
        return ErrorCode::DivideBy0;
    }
    if (action == '$' && first < 0) {
        return ErrorCode::SqrtOfNagativeNumber;
    }
    if (action == '%' && (ceil(first) != floor(first) || ceil(second) != floor(second))) {
        return ErrorCode::ModuleOfNonIntegerValue;
    }

    *out = operation[action](first, second);
    return ErrorCode::OK;
}

bool checkCharacter(const std::string& input) {
    std::string proper_chars{"0123456789.,+-*/^$%!"};
    return std::all_of(input.begin(), input.end(), [&proper_chars](auto sign) {
        return std::any_of(proper_chars.begin(), proper_chars.end(),
                           [sign](auto prop_char) { return prop_char == sign; });
    });
}

bool checkComas(const std::string& input) {
    return std::none_of(input.begin(), input.end(),
                        [](auto sign) { return sign == ','; });
}

void removeSpaces(std::string& input) {
    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
}

ErrorCode takeNumbers(const std::string& input,
                      double& num1,
                      char& operation,
                      double& num2) {
    if (!isdigit(input[0]) && input[0] != '-') {
        ErrorCode::BadFormat;
    }

    std::string to_check{"+-*/^$%!"};
    std::string number;
    if (isdigit(input[0]) || input[0] == '-') {
        number += input[0];
    } else {
        return ErrorCode::BadFormat;
    }

    int i = 1;
    for (; i < input.size(); ++i) {
        if (!isdigit(input[i]) && input[i] != '.' &&
            std::none_of(to_check.begin(), to_check.end(),
                         [&](auto sign) { return input[i] == sign; })) {
            return ErrorCode::BadFormat;
        }
        if (std::any_of(to_check.begin(), to_check.end(),
                        [&](auto sign) { return input[i] == sign; })) {
            operation = input[i++];
            break;
        }
        number += input[i];
    }

    int dots = 0;
    for (auto c : number) {
        if (c == '.') {
            ++dots;
        }
    }
    if (dots > 1) {
        return ErrorCode::BadFormat;
    }

    num1 = std::stof(number);
    number = "";

    if (i >= input.size()) {
        if (operation == '!') {
            return ErrorCode::OK;
        } else {
            return ErrorCode::BadFormat;
        }
    }
    if (operation == '!' && i < input.size()) {
        return ErrorCode::BadFormat;
    }

    if (isdigit(input[i]) || input[i] == '-') {
        number += input[i++];
    } else {
        return ErrorCode::BadFormat;
    }

    for (; i < input.size(); ++i) {
        if (!isdigit(input[i]) && input[i] != '.') {
            return ErrorCode::BadFormat;
        }
        number += input[i];
    }
    num2 = std::stof(number);
    return ErrorCode::OK;
}
