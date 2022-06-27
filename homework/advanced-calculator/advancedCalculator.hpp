#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <math.h>

#define M_PI 3.14159265358979323846 /* pi */
#define E 2.71828182845904523536 /* e */

    enum ErrorCode {
      Ok,
      BadCharacter,
      BadFormat,
      DivideBy0,
      SqrtOfNegativeNumber,
      ModuleOfNonIntegerValue
    };

ErrorCode process(std::string input, double *out);