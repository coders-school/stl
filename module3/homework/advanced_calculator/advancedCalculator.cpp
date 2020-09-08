#include "advancedCalculator.hpp"
#include "inputStringCheck.hpp"
#include "mathematicalOperation.hpp"

#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <vector>

std::map<char, std::function<double(double, double)>> functionMap{
    {'+', mathematicalOperation::add},
    {'-', mathematicalOperation::subtract},
    {'*', mathematicalOperation::multiply},
    {'/', mathematicalOperation::divide},
    {'%', mathematicalOperation::modulo},
    {'!', mathematicalOperation::factorial},
    {'^', mathematicalOperation::power},
    {'$', mathematicalOperation::sqrt}};

ErrorCode process(std::string input, double* out) {
    removeSpaces(input);
    if (checkBadCharacker(input)) {
        return ErrorCode::BadCharacter;
    }

    if (functionMap.find(input.front()) != functionMap.end() && input.front() != '-') {
        return ErrorCode::BadFormat;
    }

    auto inputIt = std::next(input.begin(), 1);
    while (functionMap.find(*inputIt) == functionMap.end() && inputIt != input.end()) {
        inputIt++;
    }
    char operation = *inputIt;
    std::string firstStr = input.substr(0, std::distance(input.begin(), inputIt));
    std::string secondStr = input.substr(std::distance(input.begin(), inputIt) + 1);

    if (operation == '!') {
        if (!isDouble(firstStr) || !isEmpty(secondStr)) {
            return ErrorCode::BadFormat;
        }
    } else {
        if ((!isDouble(firstStr)) | !isDouble(secondStr)) {
            return ErrorCode::BadFormat;
        }
    }

    if (operation == '$' && isNegative(firstStr)) {
        return ErrorCode::SqrtOfNegativeNumber;
    }

    if (operation == '%' && (!isIntiger(firstStr) || !isIntiger(secondStr))) {
        return ErrorCode::ModuleOfNonIntegerValue;
    }

    if (operation == '/' && isZero(secondStr)) {
        return ErrorCode::DivideBy0;
    }

    if (isEmpty(secondStr)) {
        secondStr = "1";
    }

    *out = functionMap[operation](std::stod(firstStr), std::stod(secondStr));

    return ErrorCode::OK;
}

bool checkBadCharacker(const std::string& input) {
    return (std::any_of(input.begin(),
                        input.end(),
                        [&](auto inputElement) { return !(std::isdigit(inputElement) ||
                                                          functionMap.find(inputElement) != functionMap.end() ||
                                                          inputElement == '.' ||
                                                          inputElement == ','); }));
}
