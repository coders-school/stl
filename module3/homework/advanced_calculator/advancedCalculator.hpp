#pragma once
#include <functional>
#include <map>
#include <regex>

const std::regex badFormatRegex("^(-?[0-9]+\\.?([0-9]+)?)(?:(?=!)(!)|(?!!)([\\+\\-\\*\\/\\^\\$%!#@&?\\[\\]]?(\\\\)?)(-?[0-9]+\\.?([0-9]+)?))$");

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

typedef ErrorCode func(void);

class Calculator {
private:
    static double add(double a, double b);
    static double substract(double a, double b);
    static double multiplicate(double a, double b);
    static double divide(double a, double b);
    static double modulo(double a, double b);
    static double factorial(double a, double b = 0);
    static double power(double a, double b);
    static double root(double a, double b);
    ErrorCode validateBadFormat();
    ErrorCode checkAndAssignOperation();
    ErrorCode validateValuesForOperation();
    void cleanInputAndExecuteRegex();
    void getValues();

    static std::map<char, std::function<double(double, double)>> possibleFunctions_;

    std::vector<std::function<ErrorCode(Calculator*)>> validators_{
        validateBadFormat,
        checkAndAssignOperation,
        validateValuesForOperation};
    double firstValue_{};
    double secondValue_{};
    char operation_{};
    std::string input_{};
    std::smatch matchedInput_;
    ErrorCode errorCode_{};

public:
    double calculate(char operation, double a, double b = 0);
    ErrorCode process(std::string& input, double* out);
};
