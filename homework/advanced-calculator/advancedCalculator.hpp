#include <algorithm>
#include <functional>
#include <iostream>
#include <array>
#include <vector>
#include <utility>
#include <map>
#include <math.h>

    enum ErrorCode {
      OK,
      BadCharacter,
      BadFormat,
      DivideBy0,
      SqrtOfNegativeNumber,
      ModuleOfNonIntegerValue
    };

ErrorCode isValidInput(std::string input, double& a, double& b, char& op);
ErrorCode process(std::string input, double *out);