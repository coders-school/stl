#include <algorithm>
#include <functional>
#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <math.h>

//#define M_PI 3.14159265358979323846 /* pi */
//#define E 2.71828182845904523536 /* e */
const double E = 2.71828182845904523536;
const double PI = 3.14159265358979323846;

    enum ErrorCode {
      OK,
      BadCharacter,
      BadFormat,
      DivideBy0,
      SqrtOfNegativeNumber,
      ModuleOfNonIntegerValue
    };

struct Input
{
  double a;
  double b;
  char operation;
  ErrorCode code;
  Input(ErrorCode code)
  {
    this->code = code;
  }
  Input(double a, double b, char op, ErrorCode err)
  {
    this->a = a;
    this->b = b;
    this->operation = op;
    this->code = err;
  }
};

ErrorCode isValidInput(std::string input, double& a, double& b, char& op);
ErrorCode process(std::string input, double *out);