#include "advancedCalculator.hpp"

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>

std::vector<std::string> splitInputParserString(std::string& input) {
    const std::vector<char> signOperators = {'+', '-', '*', '/', '%', '!', '^', '$'};

    input.erase(remove_if(input.begin(), input.end(), isspace), input.end());
    auto first_char = 0;
    input[0] == '-' ? first_char = 1 : first_char = 0;
    auto signOperator = std::find_if(input.begin() + first_char, input.end(), [&](auto char_input) {
        return std::any_of(signOperators.begin(), signOperators.end(),
                           [&](auto signOp) { return char_input == signOp; });
    });

    auto distSign = std::distance(input.begin(), signOperator);

    std::string lhs = input.substr(0, distSign);
    std::string rhs = input.substr(distSign + 1, input.size() - 1);
    if (*signOperator == '!')
        rhs += "0";
    std::string signOp = std::string(1, *signOperator);

    return {signOp, lhs, rhs};
}

std::pair<char, std::pair<double, double>> splitInputParser(std::string& input) {
    auto result = splitInputParserString(input);
    return {result[0].front(), {std::stod(result[1]), std::stod(result[2])}};
}

double factorial(double value) {
    return value <= 0.0 ? 1.0 : tgamma(value + 1.0);
}

bool checkCharacters(std::string input) {
    const std::string allowedSigns{" ,.!+/%$-+*^"};
    return std::any_of(input.begin(), input.end(), [&allowedSigns](char letter) {
        return std::find(allowedSigns.begin(), allowedSigns.end(), letter) == allowedSigns.end() && !isdigit(letter);
    });
};

bool checkFormat(std::string& input) {
    if (input.empty())
        return false;
    if (std::find(input.begin(), input.end(), ',') != input.end()) {
        return false;
    }

    auto result = splitInputParserString(input);
    auto lhs = result[1];
    auto rhs = result[2];
    auto signOperator = result[0];

    if (lhs[0] == '+' || rhs[0] == '+')
        return false;

    if (signOperator == " ")
        return false;

    int countDotsLhs = std::count(lhs.begin(), lhs.end(), '.');
    int countDotsRhs = std::count(rhs.begin(), rhs.end(), '.');

    if (countDotsLhs > 1 || countDotsRhs > 1)
        return false;

    if (!lhs[0] || !rhs[0])
        return false;

    if ((lhs[0] == '-') && (lhs[1] == '.' || !isdigit(lhs[1])))
        return false;
    if ((rhs[0] == '-') && (rhs[1] == '.' || !isdigit(rhs[1])))
        return false;

    if ((lhs[0] != '-') && (!isdigit(lhs[0])))
        return false;
    if ((rhs[0] != '-') && (!isdigit(rhs[0])))
        return false;
    auto results = splitInputParser(input);
    if (signOperator == "!" && results.second.second) {
        return false;
    }
    if (!isdigit(lhs.back()) || !isdigit(rhs.back())) {
        return false;
    }

    return true;
}

const std::map<std::string, std::function<double(double, double)>> CalculatorCommands{
    {"+", std::plus<double>()},
    {"-", std::minus<double>()},
    {"*", std::multiplies<double>()},
    {"/", std::divides<double>()},
    {"^", [](auto lhs, auto rhs) { return std::pow(lhs, rhs); }},
    {"$", [](auto lhs, auto rhs) { return pow(lhs, 1.0 / rhs); }},
    {"%", std::modulus<int>()},
    {"!", [](double lhs, double rhs) { return factorial(lhs); }}};

ErrorCode process(std::string input, double* out) {
    if (checkCharacters(input)) {
        return ErrorCode::BadCharacter;
    }

    if (!checkFormat(input)) {
        return ErrorCode::BadFormat;
    }

    auto results = splitInputParser(input);
    double lhs = results.second.first;
    double rhs = results.second.second;
    std::string signOperator = std::string(1, results.first);

    if (signOperator == "/" && rhs == 0) {
        return ErrorCode::DivideBy0;
    }

    if (signOperator == "$" && lhs < 0) {
        return ErrorCode::SqrtOfNegativeNumber;
    }

    if (signOperator == "%" && (ceil(lhs) != floor(lhs) || ceil(rhs) != floor(rhs))) {
        return ErrorCode::ModuleOfNonIntegerValue;
    }

    *out = CalculatorCommands.at(signOperator)(lhs, rhs);

    return ErrorCode::OK;
}