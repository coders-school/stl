#include "advancedCalculator.hpp"

#include <algorithm>
#include <array>
#include <cctype>
#include <cmath>
#include <functional>
#include <map>
#include <regex>
#include <sstream>

const std::map<char, std::function<double(double, double)>> operations {
    { '+', std::plus<double>() },
    { '-', std::minus<double>() },
    { '*', std::multiplies<double>() },
    { '/', std::divides<double>() },
    { '%', std::modulus<int>() },
    { '^', [](const auto& base, const auto& exp) { return std::pow(base, exp); } },
    { '$', [](const auto& radicant, const auto& index) { return std::pow(radicant, (1 / index)); } },
};

ErrorCode process(std::string input, double* out)
{
    const std::array<char, 10> correctCharacters { '+', '*', '/', '-', '%', '!', '^', '$', '.', ',' };

    auto isBadCharacterInInput = [&correctCharacters](const auto& character) {
        auto isInvalidCharacter = std::ispunct(character)
            && std::find(correctCharacters.cbegin(), correctCharacters.cend(), character) == correctCharacters.cend();
        return std::isalpha(character) || isInvalidCharacter;
    };

    if (std::any_of(input.cbegin(), input.cend(), isBadCharacterInInput)) {
        return ErrorCode::BadCharacter;
    } else if (std::find(input.cbegin(), input.cend(), ',') != input.cend()) {
        return ErrorCode::BadFormat;
    }

    const std::regex operationPattern(R"(([\-]?\d+([\.]\d*)?)\s*([+*\/\-%^$])\s*([\-]?\d+([\.]\d*)?))");
    const std::regex factorialPattern(R"(([\-]?\d+([\.]\d*)?)\s*[!])");
    std::smatch matches;

    if (std::regex_match(input, matches, operationPattern)) {
        auto lhs = std::stod(matches[1]);
        auto rhs = std::stod(matches[4]);
        char operation = std::string(matches[3])[0];

        auto isInteger = [](const auto& number) { return std::fmod(number, 1.0) == 0.0; };

        if (operation == '%' && (!isInteger(lhs) || !isInteger(rhs))) {
            return ErrorCode::ModuleOfNonIntegerValue;
        } else if (operation == '/' && rhs == 0) {
            return ErrorCode::DivideBy0;
        } else if (operation == '$' && lhs < 0) {
            return ErrorCode::SqrtOfNegativeNumber;
        }

        *out = operations.at(operation)(lhs, rhs);
        return ErrorCode::OK;
    } else if (std::regex_match(input, matches, factorialPattern)) {
        auto value = std::stod(matches[1]);
        auto calculateFactorial = [](const auto& value) {
            if (value > 0) {
                return std::tgamma(value + 1);
            }
            return -std::tgamma(std::fabs(value) + 1);
        };

        *out = calculateFactorial(value);
        return ErrorCode::OK;
    }

    return ErrorCode::BadFormat;
}
