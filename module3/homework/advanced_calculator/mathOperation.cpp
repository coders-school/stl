#include "mathOperation.hpp"
#include "errorCodeEnum.hpp"
#include <cmath>
#include <iostream>
#include <vector>

std::string &mathOperation::getString() { return dataString_; }
double mathOperation::getFirstValue() { return firstValue_; }
double mathOperation::getSecondValue() { return secondValue_; }
ErrorCode mathOperation::getErrorCode() { return ActualError_; }
double mathOperation::getResult() { return result_; }
void mathOperation::printErrorCode() {
  switch (ActualError_) {
  case ErrorCode::OK:
    std::cout << "ErrorCode::OK";
    break;
  case ErrorCode::BadCharacter:
    std::cout << "ErrorCode::BadCharacter";
    break;
  case ErrorCode::BadFormat:
    std::cout << "ErrorCode::BadFormat";
    break;
  case ErrorCode::DivideBy0:
    std::cout << "ErrorCode::DivideBy0";
    break;
  case ErrorCode::SqrtOfNegativeNumber:
    std::cout << "ErrorCode::SqrtOfNegativeNumber";
    break;
  case ErrorCode::ModuleOfNonIntegerValue:
    std::cout << "ErrorCode::ModuleOfNonIntegerValue";
    break;
  }
}
void mathOperation::printString() {
  std::for_each(dataString_.begin(), dataString_.end(),
                [](char i) { std::cout << i; });
}
void mathOperation::setInputString(std::string &string) {
  dataString_ = string;
}
void mathOperation::setResult(double &result) { result_ = result; }

void mathOperation::setErrorCode(ErrorCode& error) { ActualError_ = error; }

double mathOperation::add(double &firstValue, double &secondValue) {
  return firstValue + secondValue;
}
double mathOperation::subtract(double &firstValue, double &secondValue) {
  return firstValue - secondValue;
}
double mathOperation::multiplicate(double &firstValue, double &secondValue) {
  return firstValue * secondValue;
}
double mathOperation::divide(double &firstValue, double &secondValue) {
  return firstValue / secondValue;
}
double mathOperation::modulo(double &firstValue, double &secondValue) {
  return static_cast<double>(static_cast<int>(firstValue) +
                             static_cast<int>(secondValue));
}
double mathOperation::factorial(double &firstValue, double &secondValue) {
  double result = 0;
  for (double i = 1; i <= firstValue; i++) {
    double result = result * i;
  }
  return result;
}
double mathOperation::square(double &firstValue, double &secondValue) {
  return sqrt(firstValue);
}
double mathOperation::power(double &firstValue, double &secondValue) {
  return pow(firstValue, secondValue);
}

void mathOperation::removeSpaces() {
  dataString_.erase(remove_if(dataString_.begin(), dataString_.end(), isspace),
                    dataString_.end());
}

ErrorCode mathOperation::ValidateInputString() {
  const std::regex pattern(
      "^(-?[0-9]+\\.?([0-9]+)?)(?:(?=!)(!)|(?!!)([\\+\\-\\*\\/\\^\\$%!#@&?\\[\\]]?(\\\\)?)(-?[0-9]+\\.?([0-9]+)?))$");
  std::smatch match_groups;
  if (std::regex_match(dataString_, match_groups, pattern)) {
    return ReadRegexGroups(match_groups);
  } else {
    return ErrorCode::BadFormat;
  }
}

ErrorCode mathOperation::ReadRegexGroups(const std::smatch &regexGroups) {

  // #1 group holds complete first value,
  // #2 group holds what is after dot in first value
  // #3 group if exists, can hold only '!'
  // #4 group holds every possible operation sign
  // #5 group is only for one test-case with '//' (Dzieki Mateusz :) :) :) )
  // #6 group holds complete second value,
  // #7 group holds what is after dot in second value

  std::vector<std::string> validSymbols{"+", "-", "*", "/", "!", "%", "$"};

  if (regexGroups[3].str() == "!") {
    firstValue_ = std::stod(regexGroups[1].str());
    operationCharacter_ = "!";
    secondValue_ = 0;
    return ErrorCode::OK;
  } else {

    int sizeOfSignGroup = regexGroups[4].str().size();
    std::cout << sizeOfSignGroup << std::endl;
    if (sizeOfSignGroup == 1 &&
        std::find_if(validSymbols.begin(), validSymbols.end(),
                     [&regexGroups](auto &el) {
                       if (el == regexGroups[4].str()) {
                         return true;
                       } else
                         return false;
                     }) != validSymbols.end()) {
      operationCharacter_ = regexGroups[4].str();
      firstValue_ = std::stod(regexGroups[1].str());
      secondValue_ = std::stod(regexGroups[6].str());
      return ErrorCode::OK;
    } else
      return ErrorCode::BadCharacter;
  }
}