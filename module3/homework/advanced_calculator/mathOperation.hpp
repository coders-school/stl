#pragma once
#include "errorCodeEnum.hpp"
#include <cmath>
#include <functional>
#include <map>
#include <regex>
#include <string>
using funcType = std::function<double(double &, double &)>;
class mathOperation {

public:
  mathOperation(std::string& inputString);
  std::string& getString() const;
  double getFirstValue() const;
  double getSecondValue()const;  
  double getResult() const;
  ErrorCode getErrorCode() const;
  void printErrorCode() const;
  void printString() const;
  void printRegexGroups() const;
  void calculateResult();



private:
  std::string& dataString_;
  double firstValue_;
  double secondValue_;
  double result_;
  std::string operationCharacter_;
  ErrorCode actualError_;
  std::smatch regexMatchGroups_;

  //ErrorCode pushRegexSearchResultToMembers();
  void removeSpaces();
  ErrorCode checkIfBadFormat();
  ErrorCode checkIfBadCharacter();
  ErrorCode checkIfDivideByZero();
  ErrorCode checkIfSqrtOfNegativeNumber();
  ErrorCode checkIfmoduleOfNonIntegerValue();

  static double add(double &firstValue, double &secondValue);
  static double subtract(double &firstValue, double &secondValue);
  static double multiplicate(double &firstValue, double &secondValue);
  static double divide(double &firstValue, double &secondValue);
  static double modulo(double &firstValue, double &secondValue);
  static double factorial(double &firstValue, double &secondValue);
  static double power(double &firstValue, double &secondValue);
  static double squareRoot(double &firstValue, double &secondValue);

    std::map<char, std::function<double(double& firstValue, double&
  secondValue)>> FunctionalMap_ = {
        {'+', mathOperation::add},          {'-', mathOperation::subtract},
        {'*', mathOperation::multiplicate}, {'/', mathOperation::divide},
        {'%', mathOperation::modulo},       {'!', mathOperation::factorial},
        {'^', mathOperation::power},        {'$', mathOperation::squareRoot}};
  };



   /*   funcType add = [&](double &a, double &b) { return a + b; };
    funcType subtract = [&](double &a, double &b) { return a - b; };
    funcType multiplicate = [&](double &a, double &b) { return a * b; };
    funcType divide = [&](double &a, double &b) { return a / b; };
    funcType modulo = [&](double &a, double &b) {
      return static_cast<double>(static_cast<int>(a) + static_cast<int>(b));
    };
    funcType factorial = [&](double &a, double &b) {
      double result = 0;
      for (double i = 1; i <= a; i++) {
        double result = result * i;
      }
      return result;
    };
    funcType power = [](double &a, double &b) { return pow(a, b); };
    funcType square = [](double &a, double &b) { return sqrt(a); }; */

/*   const std::map<char, funcType> FunctionalMap = {
      {'+', mathOperation::add},          {'-', mathOperation::subtract},
      {'*', mathOperation::multiplicate}, {'/', mathOperation::divide},
      {'%', mathOperation::modulo},       {'!', mathOperation::factorial},
      {'^', mathOperation::power}};

  funcType add = [](double &a, double &b) { return a + b; };
  funcType subtract = [](double &a, double &b) { return a - b; };
  funcType multiplicate = [](double &a, double &b) { return a * b; };
  funcType divide = [](double &a, double &b) { return a / b; };
  funcType modulo = [](double &a, double &b) {
    return static_cast<double>(static_cast<int>(a) + static_cast<int>(b));
  };
  funcType factorial = [](double &a, double &b) {
    double result = 1;
    for (double i = 1; i <= a; i++) {
      double result = result * i;
    }
    return result;
  };
  funcType power = [](double &a, double &b) { return pow(a, b); };
  funcType square = [](double &a, double &b) { return sqrt(a); }; */