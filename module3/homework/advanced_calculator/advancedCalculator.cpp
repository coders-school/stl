#include "advancedCalculator.hpp"

#include <cmath>
#include <iostream>
#include <map>
#include <regex>

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

bool isBadCharacter(const std::string& input) {
    std::string badCharacters{R"([^0-9\+\-\*\/\^\%\!\$\s\.,])"};
    std::regex pattern(badCharacters);
    return std::regex_search(input, pattern);
}

bool isBadFormat(const std::string& input) {
    if (std::all_of(begin(input), end(input), [](unsigned char elem) { return isblank(elem); })) {
        return true;
    }
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
    std::regex operators(R"((\+|\-|\/|\*|\%|\^|\$|\!)(?=\D))");
    auto operators_begin = std::sregex_iterator(begin(input), end(input), operators);
    auto operators_end = std::sregex_iterator();
    if (std::distance(operators_begin, operators_end) > 1) {
        return true;
    }
    return false;
}

bool isWrongDivisionSign(const std::string& input) {
    std::regex pattern(R"(\d+\.\d+\.|(,))");
    return std::regex_search(input, pattern);
}

bool firstDigitIsNegative(const std::string& input) {
    std::regex pattern(R"(^(\s+)?(\-)(\s+)?(\d+))");
    return std::regex_search(input, pattern);
}

bool isDividedBy0(const std::string& input) {
    std::regex pattern(R"((\/(\s*)\-?0))");
    return std::regex_search(input, pattern);
}

bool isEvenRootOfNegativeNumber(const std::string& input) {
    if (!firstDigitIsNegative(input)) {
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

bool isModuloOfNonIntegerValue(const std::string& input) {
    std::regex pattern(R"((\d+\.\d+\s*\%)|(\%\s*\d+\.\d+))");
    return std::regex_search(input, pattern);
}

double getResult(const std::string& input) {
    EquationData data;
    if (binaryOperation(input)) {
        data = getBinaryEquationData(input);
    }
    if (unaryOperation(input)) {
        data = getUnaryEquationData(input);
    }
    return calculate(data);
}

bool binaryOperation(const std::string& input) {
    std::regex pattern(R"((\-?\d+(\.\d+)?)(\s*)((\+|\-|\/|\*|\%|\^|\$)|(\-\s*\-))(\s*)(\-?\d+(\.\d+)?))");
    return std::regex_search(input, pattern);
}

EquationData getBinaryEquationData(const std::string& input) {
    std::regex pattern(R"((\-?\d+(\.\d+)?)(\s*)((\+|\-|\/|\*|\%|\^|\$)|(\-\s*\-))(\s*)(\-?\d+(\.\d+)?))");
    std::smatch match;
    std::regex_search(input, match, pattern);
    EquationData data;
    data.lhs = std::stod(match[1].str());
    data.rhs = std::stod(match[8].str());
    auto operators = match[4].str();
    if (std::count_if(begin(operators), end(operators), [](auto sign) { return sign == '-'; }) == 2) {
        data.operation = '+';
    } else {
        data.operation = operators[0];
    }
    return data;
}

bool unaryOperation(const std::string& input) {
    std::regex pattern(R"((\-?\d+(\.\d+)?)(\s*)(\!))");
    return std::regex_search(input, pattern);
}

EquationData getUnaryEquationData(const std::string& input) {
    std::regex pattern(R"((\-?\d+(\.\d+)?)(\s*)(\!))");
    std::smatch match;
    std::regex_search(input, match, pattern);
    EquationData data;
    data.lhs = std::stod(match[1].str());
    data.rhs = 0;
    data.operation = match[4].str()[0];
    return data;
}

double calculate(const EquationData& data) {
    static std::map<char, OperationVariant> mathOperations{
        {'+', std::function<double(double, double)>([](double lhs, double rhs) { return lhs + rhs; })},
        {'-', std::function<double(double, double)>([](double lhs, double rhs) { return lhs - rhs; })},
        {'*', std::function<double(double, double)>([](double lhs, double rhs) { return lhs * rhs; })},
        {'/', std::function<double(double, double)>([](double lhs, double rhs) { return lhs / rhs; })},
        {'%', std::function<int(int, int)>([](int lhs, int rhs) { return lhs % rhs; })},
        {'!', std::function<double(double)>([](double lhs) { return (lhs + 1 > 0) ? std::tgamma(lhs + 1) : 1; })},
        {'^', std::function<double(double, double)>([](double lhs, double rhs) { return std::pow(lhs, rhs); })},
        {'$', std::function<double(double, double)>([](double lhs, double rhs) { return std::pow(lhs, 1 / rhs); })}};

    if (std::holds_alternative<std::function<double(double, double)>>(mathOperations[data.operation])) {
        auto function = std::get<0>(mathOperations[data.operation]);
        return function(data.lhs, data.rhs);

    } else if (std::holds_alternative<std::function<int(int, int)>>(mathOperations[data.operation])) {
        auto modulo = std::get<1>(mathOperations[data.operation]);
        return modulo(data.lhs, data.rhs);
    } else {
        auto factorial = std::get<2>(mathOperations[data.operation]);
        return factorial(data.lhs);
    }
}

ErrorCode process(std::string input, double* out) {
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
