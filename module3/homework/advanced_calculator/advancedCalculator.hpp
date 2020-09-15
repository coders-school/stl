#pragma once
#include <string>

enum class ErrorCode { OK, DivideBy0, ModuleOfNonIntegerValue, BadCharacter, SqrtOfNagativeNumber, BadFormat };

ErrorCode process(const std::string& input, double* result);
