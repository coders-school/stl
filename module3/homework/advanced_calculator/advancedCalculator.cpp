#include "advancedCalculator.hpp"
#include <cmath>
#include <regex>

bool isInteger(double number) {
    return number == std::floor(number);
}

bool isAcceptableOperation(char operation) {
    const std::string acceptableOperations{"+-*/%!^$"};
    auto it = std::find_if(acceptableOperations.begin(), acceptableOperations.end(), [operation](auto el) { return el == operation; });

    return it != acceptableOperations.end();
}

double Calculator::add(double a, double b) {
    return a + b;
}
double Calculator::substract(double a, double b) {
    return a - b;
}
double Calculator::multiplicate(double a, double b) {
    return a * b;
}
double Calculator::divide(double a, double b) {
    return a / b;
}
double Calculator::modulo(double a, double b) {
    return static_cast<int>(a) % static_cast<int>(b);
}
double Calculator::factorial(double a, double b) {
    if (0 == a || 1 == a) {
        return 1;
    } else if (0 > a) {
        a *= (-1);
        return -(a * std::tgamma(a));
    }
    return a * std::tgamma(a);
}
double Calculator::power(double a, double b) {
    return std::pow(a, b);
}
double Calculator::root(double a, double b) {
    return pow(a, 1 / b);
}

char Calculator::getGroupChar(size_t index) {
    return *matchedInput_[index].str().c_str();
}

double Calculator::calculate(char operation, double a, double b) {
    return possibleFunctions_[operation](a, b);
}

ErrorCode Calculator::validateBadFormat() {
    return matchedInput_.size() ? ErrorCode::OK : ErrorCode::BadFormat;
}
void Calculator::cleanInputAndExecuteRegex() {
    input_.erase(std::remove_if(input_.begin(), input_.end(), isspace), input_.end());
    std::regex_search(input_, matchedInput_, formatRegex);
}

ErrorCode Calculator::checkAndAssignOperation() {
    operation_ = std::max({getGroupChar(4), getGroupChar(5), getGroupChar(3)});
    return isAcceptableOperation(operation_) ? ErrorCode::OK : ErrorCode::BadCharacter;
}

void Calculator::getValues() {
    firstValue_ = getGroupChar(1) ? std::stod(matchedInput_[1].str()) : 0;
    secondValue_ = getGroupChar(6) ? std::stod(matchedInput_[6].str()) : 0;
}

ErrorCode Calculator::validateValuesForOperation() {
    if ('/' == operation_ && 0 == secondValue_) {
        return ErrorCode::DivideBy0;
    } else if ('%' == operation_ && (!isInteger(secondValue_) || 0 == secondValue_)) {
        return ErrorCode::ModuleOfNonIntegerValue;
    } else if ('$' == operation_ && 0 > firstValue_) {
        return ErrorCode::RootOfNegativeNumber;
    }
    return ErrorCode::OK;
}

ErrorCode Calculator::process(std::string& input, double* out) {
    input_ = input;
    cleanInputAndExecuteRegex();
    getValues();

    for (auto validator : validators_) {
        errorCode_ = validator(this);
        if (ErrorCode::OK != errorCode_) {
            return errorCode_;
        }
    }

    *out = calculate(operation_, firstValue_, secondValue_);

    return errorCode_;
}

std::map<char, std::function<double(double, double)>> Calculator::possibleFunctions_ = {
    {'+', Calculator::add},
    {'-', Calculator::substract},
    {'*', Calculator::multiplicate},
    {'/', Calculator::divide},
    {'%', Calculator::modulo},
    {'!', Calculator::factorial},
    {'^', Calculator::power},
    {'$', Calculator::root}};