#include "advancedCalculator.hpp"

std::map<char, std::function<double(double, double)>> MathOperations{
    {'+', [](double a, double b) { return a + b; }},
    {'-', [](double a, double b) { return a - b; }},
    {'*', [](double a, double b) { return a * b; }},
    {'/', [](double a, double b) { return a / b; }},
    {'%', [](double a, double b) { return (int)a % (int)b; }},
    {'!',
     //[](double a, double b) { return (sqrt(2 * PI * a)) * pow(a / E, a); }},
     //[](double a, double b) { return tgamma(a + 1);}},
     [](double a, double b) { if(a > 0) return tgamma(a + 1); else return tgamma((a * -1) + 1) * -1; }},
    {'^', [](double a, double b) { return pow(a, b); }},
    {'$', [](double a, double b) { return pow(a, 1 / double(b)); }}};

bool isMinus(char a) {
  if (a == '-')
    return true;
  else
    return false;
}

bool isOperator(char a) {
  if (a == '-' || a == '+' || a == '*' || a == '/' || a == '%' || a == '!' ||
      a == '^' || a == '$')
    return true;
  else
    return false;
}

bool isComma(char a) {
  if (a == '.')
    return true;
  else
    return false;
}

bool isDigit(char a) {
  if (a >= 48 && a <= 57)
    return true;
  else
    return false;
}

bool isOtherCharacter(char a) {
  if (!isDigit(a) && !isComma(a) && !isOperator(a))
    return true;
  else
    return false;
}

ErrorCode isValidInput(std::string input, double &first, double &second,
                       char &op) {
  if (input.empty())
    return ErrorCode::BadFormat;
  auto it = remove(input.begin(), input.end(), ' ');
  input.erase(it, input.end());

  for (size_t i = 0; i < input.size(); i++) {
    if (isOtherCharacter(input[i]))
      return ErrorCode::BadCharacter;
  }

  std::string a;
  std::string b;
  // char operation;
  int position = 0;
  bool firstMinus = false;
  bool secondMinus = false;
  int comma = 0;
  for (size_t i = 0; i < input.size(); i++) {
    if (i == 0) {
      if (isMinus(input[i])) {
        firstMinus = true;
        continue;
      }
    }
    if (!isDigit(input[i])) {
      if (isComma(input[i])) {
        comma++;
        if (comma > 1)
          return ErrorCode::BadFormat;
        continue;
      } else if (isOperator(input[i])) {
        position = i;
        break;
      } else {
        return ErrorCode::BadFormat;
      }
    }
  }
  a = input.substr(0, position);
  op = input[position];
  position++;
  int start = position;
  comma = 0;
  for (; position < input.size(); position++) {
    if (position == start) {
      if (isMinus(input[position])) {
        secondMinus = true;
        continue;
      }
    }
    if (!isDigit(input[position])) {
      if (isComma(input[position])) {
        comma++;
        if (comma > 1)
          return ErrorCode::BadFormat;
        continue;
      } else {
        return ErrorCode::BadFormat;
      }
    }
  }
  b = input.substr(start, position);
  if (a == "")
    return ErrorCode::BadFormat;
  if (b == "" && op != '!')
    return ErrorCode::BadFormat;

  first = stod(a);
  if (op != '!')
    second = stod(b);
  else
    second = 0;

  if (op == '%') {
    for (size_t i = 0; i < a.size(); i++) {
      if (isComma(a[i]))
        return ErrorCode::ModuleOfNonIntegerValue;
    }
    for (size_t i = 0; i < b.size(); i++) {
      if (isComma(b[i]))
        return ErrorCode::ModuleOfNonIntegerValue;
    }
  }

  if (op == '$') {
    for (size_t i = 0; i < a.size(); i++) {
      if (isMinus(a[i]))
        return ErrorCode::SqrtOfNegativeNumber;
    }
    // for (size_t i = 0; i < b.size(); i++) {
    //   if (isMinus(b[i]))
    //     return ErrorCode::SqrtOfNegativeNumber;
    // }
  }

  if (second == 0 && op == '/')
    return ErrorCode::DivideBy0;

  if (b != "" && op == '!')
    return ErrorCode::BadFormat;

  return ErrorCode::OK;
}

ErrorCode process(std::string input, double *out) {
  double a;
  double b;
  char op;
  long double output;
  auto err = isValidInput(input, a, b, op);
  auto tmp = MathOperations.find(op);
  output = tmp->second(a, b);
  *out = output;
  return err;
}