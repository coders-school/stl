#pragma once

#include <string>

enum class ErrorCode { OK,
                       BadCharacter,
                       BadFormat,
                       DivideBy0,
                       SqrtOfNagativeNumber,
                       ModuleOfNonIntegerValue };

ErrorCode process(std::string input, double* out);
