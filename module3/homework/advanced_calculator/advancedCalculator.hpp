#pragma once

#include <string>

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue,
};

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
int getResult(const std::string& input);
