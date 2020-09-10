#pragma once

#include <functional>
#include <ostream>
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

std::ostream& operator<<(std::ostream& os, ErrorCode error);

class AdvancedCalculator {
    double lhs;
    double rhs;
    char operation;
    std::string input;

    bool isBadCharacter();
    bool isBadFormat();
    bool noDigitBeforeOperator();
    bool noDigitAfterBinaryOperator();
    bool isDigitAfterUnaryOperator();
    bool moreThanOneOperator();
    bool firstDigitIsNegative();
    bool isWrongDivisionSign();
    bool isDividedBy0();
    bool isEvenRootOfNegativeNumber();
    bool isModuloOfNonIntegerValue();
    bool binaryOperation();
    bool unaryOperation();
    void setBinaryEquationData();
    void setUnaryEquationData();

    double calculate();

   public:
    AdvancedCalculator();
    explicit AdvancedCalculator(const std::string& input);
    double getResult();
    ErrorCode getErrorCode();
};
struct EquationData {
    double lhs;
    double rhs;
    char operation;
};

using OperationVariant =
    std::variant<std::function<double(double, double)>, std::function<int(int, int)>, std::function<double(double)>>;

ErrorCode process(std::string input, double* out);

bool isBadCharacter();
bool isBadFormat();
bool noDigitBeforeOperator();
bool noDigitAfterBinaryOperator();
bool isDigitAfterUnaryOperator();
bool moreThanOneOperator();
bool firstDigitIsNegative();
bool isWrongDivisionSign();
bool isDividedBy0();
bool isEvenRootOfNegativeNumber();
bool isModuloOfNonIntegerValue();

double getResult();

double calculate(const EquationData& data);
bool binaryOperation();
bool unaryOperation();
EquationData getBinaryEquationData();
EquationData getUnaryEquationData();
