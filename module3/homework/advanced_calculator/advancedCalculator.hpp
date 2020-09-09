#pragma once

#include <functional>
#include <string>
#include <variant>

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue,
};

struct EquationData {
    double lhs;
    double rhs;
    char operation;
};

using OperationVariant = std::variant<std::function<double(double, double)>, std::function<int(int, int)>, std::function<double(double)>>;

ErrorCode process(std::string input, double* out);

bool isBadCharacter(const std::string& input);
bool isBadFormat(const std::string& input);
bool noDigitBeforeOperator(const std::string& input);
bool noDigitAfterBinaryOperator(const std::string& input);
bool isDigitAfterUnaryOperator(const std::string& input);
bool moreThanOneOperator(const std::string& input);
bool firstDigitIsNegative(const std::string& input);
bool isWrongDivisionSign(const std::string& input);
bool isDividedBy0(const std::string& input);
bool isEvenRootOfNegativeNumber(const std::string& input);
bool isModuloOfNonIntegerValue(const std::string& input);
double getResult(const std::string& input);
double calculate(const EquationData& data);
bool binaryOperation(const std::string& input);
bool unaryOperation(const std::string& input);
EquationData getBinaryEquationData(const std::string& input);
EquationData getUnaryEquationData(const std::string& input);
