#include "advancedCalculator.hpp"

#include <cmath>
#include <functional>
#include <map>
#include <regex>

const std::map<char, std::function<double(double, double)>> operations{
    {'+', std::plus<>()},
    {'-', std::minus<>()},
    {'*', std::multiplies<>()},
    {'/', std::divides<>()},
    {'%', std::modulus<int>()},
    {'^', [](auto base, auto exponent) { return pow(base, exponent); }},
    {'$', [](auto value, auto root) { return pow(value, 1.0 / root); }},
    {'!', [](auto value, auto notUsed) { return value <= 0 ? 1.0 : std::tgamma(value + 1.0); }}
};

const std::regex regex2arguments{R"((^[\-]?\d+\.*\d*)\s*(\D)\s*([\-]?\d+\.*\d*)$)"};
const std::regex regex1argument{R"((^[\-]?\d+\.*\d*)\s*(\D)$)"};

static bool parseString(const std::string& string, char* operation, double* lhs, double* rhs)
{
    if (std::smatch match;
        std::regex_search(string, match, regex2arguments) or std::regex_search(string, match, regex1argument)) {
        if (match[0] != string) {
            return false;
        } else {
            *lhs = stod(match[1]);
            *operation = ((std::string)match[2])[0];
            if (match.size() == 4) {
                *rhs = stod(match[3]);
            }
            if ((match.size() == 4) and (*operation == '!')) {
                return false;
            }
            return true;
        }
    }
    return false;
}

bool checkBadCharacter(const std::string& string)
{
    std::string allowedCharacters;

    for (const auto& operation : operations) {
        allowedCharacters.append(std::string(1, operation.first));
    }
    return false;
}

bool checkDivideBy0(char operation, double number)
{
    if ((operation == '/') and (number == 0.0)) {
        return true;
    }
    return false;
}

bool checkSqrtOfNegativeNumber(char operation, double number)
{
    if ((operation == '$') and (number < 0)) {
        return true;
    }
    return false;
}

bool checkModuleOfNonIntegerValue(char operation, double value)
{
    if ((operation == '%') and (value != floor(value))) {
        return true;
    }
    return false;
}

ErrorCode process(const std::string& input, double* result)
{
    char operation;
    double lhs;
    double rhs;

    if (checkBadCharacter(input)) {
        return ErrorCode::BadCharacter;
    }
    else if (!parseString(input, &operation, &lhs, &rhs)) {
        return ErrorCode::BadFormat;
    } else if (checkDivideBy0(operation, rhs)) {
        return ErrorCode::DivideBy0;
    } else if (checkSqrtOfNegativeNumber(operation, lhs)) {
        return ErrorCode::SqrtOfNegativeNumber;
    } else if (checkModuleOfNonIntegerValue(operation, rhs)) {
        return ErrorCode::ModuleOfNonIntegerValue;
    }
    
    auto it = operations.find(operation); it != operations.end();
    *result = it->second(lhs, rhs);
    return ErrorCode::OK;
}
