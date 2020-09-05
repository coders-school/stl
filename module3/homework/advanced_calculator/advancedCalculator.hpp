#pragma once
#include <functional>
#include <map>
#include <regex>

const std::regex formatRegex("^(-?[0-9]+\\.?([0-9]+)?)(?:(?=!)(!)|(?!!)([\\+\\-\\*\\/\\^\\$%!#@&?\\[\\]]?(\\\\)?)(-?[0-9]+\\.?([0-9]+)?))$");

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    RootOfNegativeNumber,
    ModuleOfNonIntegerValue
};

class Calculator {
private:
    double add(double a, double b);
    double substract(double a, double b);
    double multiplicate(double a, double b);
    double divide(double a, double b);
    double modulo(double a, double b);
    double factorial(double a, double b = 0);
    double power(double a, double b);
    double root(double a, double b);
    ErrorCode validateBadFormat();
    ErrorCode checkAndAssignOperation();
    ErrorCode validateValuesForOperation();
    void cleanInputAndExecuteRegex();
    void getValues();
    char getGroupChar(size_t index);
    double calculate();

    std::map<char, std::function<double(Calculator*, double, double)>> possibleFunctions_ = {
        {'+', &Calculator::add},
        {'-', &Calculator::substract},
        {'*', &Calculator::multiplicate},
        {'/', &Calculator::divide},
        {'%', &Calculator::modulo},
        {'!', &Calculator::factorial},
        {'^', &Calculator::power},
        {'$', &Calculator::root}};

    const std::vector<std::function<ErrorCode(Calculator*)>> validators_{
        &Calculator::validateBadFormat,
        &Calculator::checkAndAssignOperation,
        &Calculator::validateValuesForOperation};
    double firstValue_{};
    double secondValue_{};
    char operation_{};
    std::string input_{};
    std::smatch matchedInput_{};
    ErrorCode errorCode_{};

public:
    ErrorCode process(std::string& input, double* out);
};
