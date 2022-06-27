#include "advancedCalculator.hpp"

std::map<char, std::function<double(double, double)>> operations{
    {'+', [](double a, double b) { return a + b; }},
    {'-', [](double a, double b) { return a - b; }},
    {'*', [](double a, double b) { return a * b; }},
    {'/', [](double a, double b) { return a / b; }},
    {'%', [](double a, double b) { return (int)a % (int)b; }},
    {'!', [](double a, double b) { return (sqrt(2 * M_PI * a)) * pow(a / E, a); }},
    {'^', [](double a, double b) { return pow(a, b); }},
    {'$', [](double a, double b) { return pow(a, 1 / double(b)); }}};

bool isMinus(char a) {
  if (a == '-')
    return true;
  else
    return false;
}

bool isComma(char a) {
  if (a == 44)
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

ErrorCode isValidInput(std::string input) {
  if (input.empty())
    return ErrorCode::BadCharacter;
  remove(input.begin(), input.end(), ' ');
  int count = 0;
  bool firstMinus = false;
  bool secondMinus = false;
  for (size_t i = 0; i < input.size(); i++) {
    if (i == 0) {
      if (isMinus(input[i]))
        firstMinus = true;
      continue;
    }
    if (!isDigit(input[i])) {
    }
  }
}

ErrorCode process(std::string input, double *out) {}