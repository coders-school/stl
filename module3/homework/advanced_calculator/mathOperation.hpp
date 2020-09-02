#pragma once
#include "errorCodeEnum.hpp"
#include <cmath>
#include <functional>
#include <map>
#include <string>
#include <regex>
using funcType = std::function<double(double &, double &)>;

class mathOperation {

public:
  // mathOperation();
  std::string& getString();
  double getFirstValue();
  double getSecondValue();
  double getResult();
  ErrorCode getErrorCode();
  void setInputString(std::string& string);
  void setResult(double& result);
  void setErrorCode(ErrorCode& error);
  void printErrorCode();
  void printString();
  void removeSpaces();
  ErrorCode ValidateInputString();
  ErrorCode ReadRegexGroups(const std::smatch& regexGroups);
  static double add(double &firstValue, double &secondValue);
  static double subtract(double &firstValue, double &secondValue);
  static double multiplicate(double &firstValue, double &secondValue);
  static double divide(double &firstValue, double &secondValue);
  static double modulo(double &firstValue, double &secondValue);
  static double factorial(double &firstValue, double &secondValue);
  static double power(double &firstValue, double &secondValue);
  static double square(double &firstValue, double &secondValue);

private:
  std::string dataString_;
  double firstValue_;
  double secondValue_;
  double result_;
  std::string operationCharacter_;
  ErrorCode ActualError_;
  /*    const std::map<char, funcType> FunctionalMap = {
        {'+', add},    {'-', subtract},  {'*', multiplicate}, {'/', divide},
        {'%', modulo}, {'!', factorial}, {'^', power}};

    funcType add = [](double &a, double &b) { return a + b; };
    funcType subtract = [](double &a, double &b) { };
    funcType multiplicate = [](double &a, double &b) { return a * b; };
    funcType divide = [](double &a, double &b) { return a / b; };

    funcType modulo = [](double &a, double &b) {
      return static_cast<double>(static_cast<int>(a) + static_cast<int>(b));
    };

    funcType factorial = [](double &a, double &b) {
      double result = 0;
      for (double i = 1; i <= a; i++) {
        double result = result * i;
      }
      return result;
    };

    funcType power = [](double &a, double &b) { return pow(a, b); };
    funcType square = [](double &a, double &b) { return sqrt(a); };  */
  std::map<char, std::function<double(double &, double &)>> FunctionalMap = {
      {'+', mathOperation::add},          {'-', mathOperation::subtract},
      {'*', mathOperation::multiplicate}, {'/', mathOperation::divide},
      {'%', mathOperation::modulo},       {'!', mathOperation::factorial},
      {'^', mathOperation::power},        {'$', mathOperation::square}};
};
