#include "advancedCalculator.hpp"

#include <cmath>
#include <iostream>
#include <map>
#include <regex>

bool isBadCharacter(const std::string& input) {
    std::string badCharacters{R"([^0-9\+\-\*\/\^\%\!\$\s\.])"};
    std::regex pattern(badCharacters);
    return std::regex_search(input, pattern);
}

bool isBadFormat(const std::string& input) {
    if (noDigitBeforeOperator(input)) {
        return true;
    }
    if (noDigitAfterBinaryOperator(input)) {
        return true;
    }
    if (isDigitAfterUnaryOperator(input)) {
        return true;
    }
    if (moreThanOneOperator(input)) {
        return true;
    }
    if (isWrongDivisionSign(input)) {
        return true;
    }
    return false;
}

bool noDigitBeforeOperator(const std::string& input) {
    std::regex pattern(R"(^(\D+)?(\s+)?(\+|\/|\*|\^|\$|\!|\%))");
    return std::regex_search(input, pattern);
}

bool noDigitAfterBinaryOperator(const std::string& input) {
    std::regex pattern(R"((\+|\-|\/|\*|\^|\$|\%)$)");
    return std::regex_search(input, pattern);
}

bool isDigitAfterUnaryOperator(const std::string& input) {
    std::regex pattern(R"((\!)(\s+)?(\d+))");
    return std::regex_search(input, pattern);
}

bool moreThanOneOperator(const std::string& input) {
    std::regex operators(R"((\+|\-|\/|\*|\^|\$|\%|\!))");
    std::smatch foundOperators;
    auto operators_begin = std::sregex_iterator(input.begin(), input.end(), operators);
    auto operators_end = std::sregex_iterator();
    auto equalToMinus = [](auto elem) { return elem.str() == "-"; };
    if (std::distance(operators_begin, operators_end) > 3) {
        return true;
    }
    if (std::distance(operators_begin, operators_end) == 3) {
        return !std::all_of(operators_begin, operators_end, equalToMinus);
    }
    if (std::distance(operators_begin, operators_end) == 2) {
        if (!firstDigitIsNegative(input)) {
            return true;
        }
    }
    return false;
}

bool isWrongDivisionSign(const std::string& input) {
    std::regex pattern(R"((\.\S+\.)|(,))");
    return std::regex_search(input, pattern);
}

bool firstDigitIsNegative(const std::string& input) {
    std::regex pattern(R"(^(\s+)?(\-)(\s+)?(\d+))");
    return std::regex_search(input, pattern);
}

bool isDividedBy0(const std::string& input) {
    std::regex pattern(R"((\/(\s+)?0))");
    return std::regex_search(input, pattern);
}

bool isEvenRootOfNegativeNumber(const std::string& input) {
    if (!firstDigitIsNegative(input)) {
        return false;
    }
    std::regex pattern(R"(((\$)(\s*)(\d+))$)");
    std::smatch match;
    std::regex_search(input, match, pattern);
    if (match.empty()) {
        return false;
    }
    auto rootDegree = std::stoi(match[4].str());
    if (rootDegree % 2 == 0) {
        return true;
    }
    return false;
}

bool isModuloOfNonIntegerValue(const std::string& input) {
    std::regex pattern(R"((\d+\.\d+\s*\%)|(\%\s*\d+\.\d+))");
    return std::regex_search(input, pattern);
}

int getResult(const std::string& input) {
    std::regex pattern(R"((\-?\d+(\.\d+)?)(\s*)((\+|\-|\/|\*|\%|\^|\!|\$|)|(\-\s*\-))(\s*)(\d+(\.\d+)?))");
    std::smatch match;
    std::regex_search(input, match, pattern);
    int lhs = std::stoi(match[1].str());
    char operation;
    if (match[4].str().size() == 2) {
        operation = '+';
    } else {
        operation= match[4].str()[0];
    }
    int rhs = std::stoi(match[8].str());

}

int calculate(double lhs, double rhs, const Operation& op) {
    
}


ErrorCode process(std::string input, double* out) {
    std::map<char, Operation> basicMathOperations{
        {'+', std::function<double(double, double)>([](double lhs, double rhs) { return lhs + rhs; })},
        {'-', std::function<double(double, double)>([](double lhs, double rhs) { return lhs - rhs; })},
        {'*', std::function<double(double, double)>([](double lhs, double rhs) { return lhs * rhs; })},
        {'/', std::function<double(double, double)>([](double lhs, double rhs) { return lhs / rhs; })},
        {'%', std::function<int(int, int)>([](int lhs, int rhs) { return lhs % rhs; })},
        {'!', std::function<double(double)>([](double lhs) { return std::tgamma(lhs + 1); })},
        {'^', std::function<double(double, double)>([](double lhs, double rhs) { return std::pow(lhs, rhs); })},
        {'$', std::function<double(double, double)>([](double lhs, double rhs) { return std::pow(lhs, 1 / rhs); })}};
    if (isBadCharacter(input)) {
        return ErrorCode::BadCharacter;
    }
    if (isBadFormat(input)) {
        return ErrorCode::BadFormat;
    }
    if (isDividedBy0(input)) {
        return ErrorCode::DivideBy0;
    }
    if (isEvenRootOfNegativeNumber(input)) {
        return ErrorCode::SqrtOfNegativeNumber;
    }
    if (isModuloOfNonIntegerValue(input)) {
        return ErrorCode::ModuleOfNonIntegerValue;
    }
    *out = getResult(input);

    return ErrorCode::OK;
}
