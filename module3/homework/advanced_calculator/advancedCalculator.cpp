#include "advancedCalculator.hpp"

#include <cmath>
#include <iostream>
#include <map>
#include <regex>

AdvancedCalculator::AdvancedCalculator(const std::string& input) :
    input(input),
    mathOperations{
        {'+', std::function<double(double, double)>([](double lhs, double rhs) { return lhs + rhs; })},
        {'-', std::function<double(double, double)>([](double lhs, double rhs) { return lhs - rhs; })},
        {'*', std::function<double(double, double)>([](double lhs, double rhs) { return lhs * rhs; })},
        {'/', std::function<double(double, double)>([](double lhs, double rhs) { return lhs / rhs; })},
        {'%', std::function<int(int, int)>([](int lhs, int rhs) { return lhs % rhs; })},
        {'!', std::function<double(double)>([](double lhs) { return (lhs + 1 > 0) ? std::tgamma(lhs + 1) : 1; })},
        {'^', std::function<double(double, double)>([](double lhs, double rhs) { return std::pow(lhs, rhs); })},
        {'$', std::function<double(double, double)>([](double lhs, double rhs) { return std::pow(lhs, 1 / rhs); })}} {
}

std::ostream& operator<<(std::ostream& os, ErrorCode error) {
    switch (error) {
        case ErrorCode::OK:
            os << "OK";
            break;
        case ErrorCode::BadCharacter:
            os << "BadCharacter";
            break;
        case ErrorCode::BadFormat:
            os << "BadFormat";
            break;
        case ErrorCode::DivideBy0:
            os << "DivideBy0";
            break;
        case ErrorCode::SqrtOfNegativeNumber:
            os << "SqrtOfNegativeNumber";
            break;
        case ErrorCode::ModuleOfNonIntegerValue:
            os << "ModuleOfNonIntegerValue";
            break;
    }
    return os;
}

bool AdvancedCalculator::isBadCharacter() {
    std::string badCharacters{R"([^0-9\+\-\*\/\^\%\!\$\s\.,])"};
    std::regex pattern(badCharacters);
    return std::regex_search(input, pattern);
}

bool AdvancedCalculator::isBadFormat() {
    if (std::all_of(begin(input), end(input), [](unsigned char elem) { return isblank(elem); })) {
        return true;
    }
    if (noDigitBeforeOperator()) {
        return true;
    }
    if (noDigitAfterBinaryOperator()) {
        return true;
    }
    if (isDigitAfterUnaryOperator()) {
        return true;
    }
    if (moreThanOneOperator()) {
        return true;
    }
    if (isWrongDivisionSign()) {
        return true;
    }
    return false;
}

bool AdvancedCalculator::noDigitBeforeOperator() {
    std::regex pattern(R"(^(\D+)?(\s+)?(\+|\/|\*|\^|\$|\!|\%))");
    return std::regex_search(input, pattern);
}

bool AdvancedCalculator::noDigitAfterBinaryOperator() {
    std::regex pattern(R"((\+|\-|\/|\*|\^|\$|\%)$)");
    return std::regex_search(input, pattern);
}

bool AdvancedCalculator::isDigitAfterUnaryOperator() {
    std::regex pattern(R"((\!)(\s+)?(\d+))");
    return std::regex_search(input, pattern);
}

bool AdvancedCalculator::moreThanOneOperator() {
    std::regex operators(R"((\+|\-|\/|\*|\%|\^|\$|\!)(?=\D))");
    auto operators_begin = std::sregex_iterator(begin(input), end(input), operators);
    auto operators_end = std::sregex_iterator();
    if (std::distance(operators_begin, operators_end) > 1) {
        return true;
    }
    return false;
}

bool AdvancedCalculator::isWrongDivisionSign() {
    std::regex pattern(R"(\d+\.\d+\.|(,))");
    return std::regex_search(input, pattern);
}

bool AdvancedCalculator::firstDigitIsNegative() {
    std::regex pattern(R"(^(\s+)?(\-)(\s+)?(\d+))");
    return std::regex_search(input, pattern);
}

bool AdvancedCalculator::isDividedBy0() {
    std::regex pattern(R"((\/(\s*)\-?0))");
    return std::regex_search(input, pattern);
}

bool AdvancedCalculator::isEvenRootOfNegativeNumber() {
    if (!firstDigitIsNegative()) {
        return false;
    }
    std::regex pattern(R"(((\$)(\s*)(\-?\d+))$)");
    std::smatch match;
    std::regex_search(input, match, pattern);
    if (match.empty()) {
        return false;
    }
    auto rootDegree = std::stoi(match[4].str());
    if (rootDegree % 2 == 0) {
        return true;
    }
    if (rootDegree < 2) {
        return true;
    }
    return false;
}

bool AdvancedCalculator::isModuloOfNonIntegerValue() {
    std::regex pattern(R"((\d+\.\d+\s*\%)|(\%\s*\d+\.\d+))");
    return std::regex_search(input, pattern);
}

double AdvancedCalculator::getResult() {
    if (binaryOperation()) {
        setBinaryEquationData();
    }
    if (unaryOperation()) {
        setUnaryEquationData();
    }
    return calculate();
}

bool AdvancedCalculator::binaryOperation() {
    std::regex pattern(R"((\-?\d+(\.\d+)?)(\s*)((\+|\-|\/|\*|\%|\^|\$)|(\-\s*\-))(\s*)(\-?\d+(\.\d+)?))");
    return std::regex_search(input, pattern);
}

void AdvancedCalculator::setBinaryEquationData() {
    std::regex pattern(R"((\-?\d+(\.\d+)?)(\s*)((\+|\-|\/|\*|\%|\^|\$)|(\-\s*\-))(\s*)(\-?\d+(\.\d+)?))");
    std::smatch match;
    std::regex_search(input, match, pattern);
    EquationData data;
    lhs = std::stod(match[1].str());
    rhs = std::stod(match[8].str());
    auto operators = match[4].str();
    if (std::count_if(begin(operators), end(operators), [](auto sign) { return sign == '-'; }) == 2) {
        operation = '+';
    } else {
        operation = operators[0];
    }
}

bool AdvancedCalculator::unaryOperation() {
    std::regex pattern(R"((\-?\d+(\.\d+)?)(\s*)(\!))");
    return std::regex_search(input, pattern);
}

void AdvancedCalculator::setUnaryEquationData() {
    std::regex pattern(R"((\-?\d+(\.\d+)?)(\s*)(\!))");
    std::smatch match;
    std::regex_search(input, match, pattern);
    EquationData data;
    lhs = std::stod(match[1].str());
    rhs = 0;
    operation = match[4].str()[0];
}

double AdvancedCalculator::calculate() {
    if (std::holds_alternative<std::function<double(double, double)>>(mathOperations[operation])) {
        auto function = std::get<0>(mathOperations[operation]);
        return function(lhs, rhs);

    } else if (std::holds_alternative<std::function<int(int, int)>>(mathOperations[operation])) {
        auto modulo = std::get<1>(mathOperations[operation]);
        return modulo(lhs, rhs);
    } else {
        auto factorial = std::get<2>(mathOperations[operation]);
        return factorial(lhs);
    }
}

ErrorCode AdvancedCalculator::getErrorCode() {
    
}

ErrorCode process(std::string input, double* out) {
    AdvancedCalculator calculator(input);
    switch (calculator.getErrorCode()) {
        case ErrorCode::BadCharacter:
            return ErrorCode::BadCharacter;
        case ErrorCode::BadFormat:
            return ErrorCode::BadFormat;
        case ErrorCode::DivideBy0:
            return ErrorCode::DivideBy0;
        case ErrorCode::ModuleOfNonIntegerValue:
            return ErrorCode::ModuleOfNonIntegerValue;
        case ErrorCode::SqrtOfNegativeNumber:
            return ErrorCode::SqrtOfNegativeNumber;
    }
    *out = calculator.getResult();

    return ErrorCode::OK;
}
