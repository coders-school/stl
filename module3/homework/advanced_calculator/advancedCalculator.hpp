#pragma once

#include <functional>
#include <map>
#include <regex>
#include <string>

constexpr size_t MAX_TERMS = 2;
constexpr size_t OPERATOR = 1;
const std::regex arithmeticOp("[\\-+*/^$%]");
const std::regex factorialOp("[!]");

enum class ErrorCode { OK, BadCharacter, BadFormat, DivideBy0, SqrtOfNegativeNumber, ModuleOfNonIntegerValue };

ErrorCode process(std::string input, double* out);
