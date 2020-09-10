#pragma once

#include <functional>
#include <ostream>
#include <string>
#include <unordered_map>
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
    using OperationVariant = std::
        variant<std::function<double(double, double)>, std::function<int(int, int)>, std::function<double(double)>>;
    double lhs{0};
    double rhs{0};
    char operation{'0'};
    std::string input{};
    std::unordered_map<char, OperationVariant> mathOperations{};

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
    AdvancedCalculator() = default;
    explicit AdvancedCalculator(const std::string& input);
    double getResult();
    ErrorCode getErrorCode();
};
struct EquationData {
    double lhs;
    double rhs;
    char operation;
};

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
