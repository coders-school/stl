#include "advancedCalculator.hpp"

#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <map>
#include <regex>
#include <string_view>

constexpr std::string_view ERROR_CODE_MESSAGE[] = {"Result: ",
                                                   "Bad Format!",
                                                   "You cant divide by zero!",
                                                   "Bad Character!",
                                                   "You cant get sqrt from negative number!",
                                                   "You cant get module from non integer value!"};

constexpr size_t ALLOWED_CHARACKTERS_SIZE = 11;
constexpr std::array<char, ALLOWED_CHARACKTERS_SIZE> ALLOWED_CHARACTERS = {'+', '-', '*', '/', '%', '^', '$', '!', '.', ' ', ','};

const std::map<std::string, std::function<double(double, double)>> calculateFunctions{
    {"+", std::plus<double>()},
    {"-", std::minus<double>()},
    {"*", std::multiplies<double>()},
    {"/", std::divides<double>()},
    {"%", std::modulus<int>()},
    {"^", [](const double base, const double exponent) { return pow(base, exponent); }},
    {"$", [](const double number, const double root) { return pow(number, 1 / root); }},
    {"!", [](const double value, const double defaultValue) { return (value < 0) ? defaultValue : tgamma(value + defaultValue); }}};

bool checkCharacter(const std::string& inputData) {
    return std::any_of(inputData.cbegin(), inputData.cend(), [](char charackter) {
        return (std::find(ALLOWED_CHARACTERS.cbegin(), ALLOWED_CHARACTERS.cend(), charackter) == ALLOWED_CHARACTERS.cend()) && !isdigit(charackter);
    });
}

bool checkIfNumberIsInteger(const double value) {
    return value - static_cast<int>(value) == 0;
}

ErrorCode process(std::string inputData, double* out) {
    if (checkCharacter(inputData)) {
        return ErrorCode::BadCharacter;
    }

    std::regex allowedInputFormatForOperations(R"(([-]?\d+[.]?\d*)[ ]*([+\-*\/$^%])[ ]*([-]?\d+[.]?\d*))");
    std::regex allowedInputFormatForFactorialOperation(R"(([-]?\d+[.]?\d*[ ]*)([!]))");
    std::smatch matchResult;

    if (std::regex_search(inputData, matchResult, allowedInputFormatForOperations)) {
        if (matchResult[0] != inputData) {
            return ErrorCode::BadFormat;
        }

        double firstValue = std::stod(matchResult[1]);
        double secondValue = std::stod(matchResult[3]);
        std::string calculateOperation = matchResult[2];

        if (calculateOperation == "/" && secondValue == 0) {
            return ErrorCode::DivideBy0;
        }
        if (calculateOperation == "$" && firstValue < 0) {
            return ErrorCode::SqrtOfNegativeNumber;
        }
        if (calculateOperation == "%" && (!checkIfNumberIsInteger(firstValue) || !checkIfNumberIsInteger(secondValue))) {
            return ErrorCode::ModuleOfNonIntegerValue;
        }

        *out = calculateFunctions.at(calculateOperation)(firstValue, secondValue);

        return ErrorCode::OK;
    }

    if (std::regex_search(inputData, matchResult, allowedInputFormatForFactorialOperation)) {
        if (matchResult[0] != inputData) {
            return ErrorCode::BadFormat;
        }

        double value = std::stod(matchResult[1]);
        const double defaultValue = 1;
        std::string calculateFactorialOperation = matchResult[2];

        *out = calculateFunctions.at(calculateFactorialOperation)(value, defaultValue);

        return ErrorCode::OK;
    }

    return ErrorCode::BadFormat;
}

void calculate(std::string& inputData) {
    double out{};

    switch (process(inputData, &out)) {
    case ::ErrorCode::OK:
        std::cout << ERROR_CODE_MESSAGE[0] << out << '\n';
        break;
    case ErrorCode::BadFormat:
        std::cout << ERROR_CODE_MESSAGE[1] << '\n';
        break;
    case ErrorCode::DivideBy0:
        std::cout << ERROR_CODE_MESSAGE[2] << '\n';
        break;
    case ::ErrorCode::BadCharacter:
        std::cout << ERROR_CODE_MESSAGE[3] << '\n';
        break;
    case ::ErrorCode::SqrtOfNegativeNumber:
        std::cout << ERROR_CODE_MESSAGE[4] << '\n';
        break;
    case ::ErrorCode::ModuleOfNonIntegerValue:
        std::cout << ERROR_CODE_MESSAGE[5] << '\n';
        break;
    }
}