#pragma once

#include <cmath>
#include <functional>
#include <map>
#include <string>
#include <vector>

enum class ErrorCode { OK, BadCharacter, BadFormat, DivideBy0, SqrtOfNegativeNumber, ModuleOfNonIntegerValue };

bool checkCharacters(std::string input);
bool isInteger(double number);
ErrorCode process(std::string input, double* out);
