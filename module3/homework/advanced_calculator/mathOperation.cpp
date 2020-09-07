#include "mathOperation.hpp"
#include "errorCodeEnum.hpp"
#include <cmath>
#include <iostream>
#include <vector>

mathOperation::mathOperation(std::string& inputString)
    : dataString_(inputString), result_(0), firstValue_(0), secondValue_(0),
      operationCharacter_(""), actualError_(ErrorCode::OK) {
        removeSpaces();
        actualError_ =  checkIfBadFormat();
        actualError_ =  checkIfBadCharacter();
        actualError_ =  checkIfDivideByZero();
        actualError_ = checkIfSqrtOfNegativeNumber();
        actualError_ = checkIfmoduleOfNonIntegerValue();
        calculateResult();

      };

std::string& mathOperation::getString() const { return dataString_; }
double mathOperation::getFirstValue() const { return firstValue_; }
double mathOperation::getSecondValue() const { return secondValue_; }
double mathOperation::getResult() const { return result_; }
ErrorCode mathOperation::getErrorCode() const { return actualError_; }
void mathOperation::printErrorCode() const {
  switch (actualError_) {
  case ErrorCode::OK:
    std::cout << "ErrorCode::OK" << std::endl;
    break;
  case ErrorCode::BadCharacter:
    std::cout << "ErrorCode::BadCharacter"<< std::endl;
    break;
  case ErrorCode::BadFormat:
    std::cout << "ErrorCode::BadFormat"<< std::endl;
    break;
  case ErrorCode::DivideBy0:
    std::cout << "ErrorCode::DivideBy0"<< std::endl;
    break;
  case ErrorCode::SqrtOfNegativeNumber:
    std::cout << "ErrorCode::SqrtOfNegativeNumber"<< std::endl;
    break;
  case ErrorCode::ModuleOfNonIntegerValue:
    std::cout << "ErrorCode::ModuleOfNonIntegerValue"<< std::endl;
    break;
  }
}
void mathOperation::printString() const {
  std::for_each(dataString_.begin(), dataString_.end(),
                [](char i) { std::cout << i; });
                std::cout << std::endl;
}
/* void mathOperation::setInputString(std::string &string) {
  dataString_ = string;
}
void mathOperation::setResult(double &result) { result_ = result; }

void mathOperation::setErrorCode(ErrorCode &error) { actualError_ = error; } */

double mathOperation::add(double &firstValue, double &secondValue) {
  std::cout << "dodajemy";
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
  return static_cast<double>(static_cast<int>(firstValue)%
                             static_cast<int>(secondValue));
}
double mathOperation::factorial(double &firstValue, double &secondValue) {
  return std::tgamma(firstValue+1);
}
double mathOperation::squareRoot(double &firstValue, double &secondValue) {
  return pow(firstValue, 1/secondValue);
}
double mathOperation::power(double &firstValue, double &secondValue) {
  return pow(firstValue, secondValue);
}

void mathOperation::removeSpaces() {
  dataString_.erase(remove_if(dataString_.begin(), dataString_.end(), isspace),
                    dataString_.end());
}

  // #1 group holds complete first value,
  // #2 group holds what is after dot in first value
  // #3 group if exists, can hold only '!'
  // #4 group holds every possible operation sign (with // too)
  // #5 group is only for one test-case with '//' (Dzieki Mateusz :) :) :) )
  // #6 group holds complete second value,
  // #7 group holds what is after dot in second value
 
ErrorCode mathOperation::checkIfBadFormat() {

  const std::regex regexPattern_(
      "^(-?[0-9]+\\.?([0-9]+)?)(?:(?=!)(!)|(?!!)([\\+\\-\\*\\/\\^\\$%!#@&?\\[\\]]?(\\\\)?)(-?[0-9]+\\.?([0-9]+)?))$");
  if (std::regex_match(dataString_, regexMatchGroups_, regexPattern_) == true) {
    return actualError_;
  } else
    return ErrorCode::BadFormat;
}

ErrorCode mathOperation::checkIfBadCharacter() {
  if(actualError_ == ErrorCode::OK){
  std::vector<std::string> validSymbols{"+", "-", "*", "/", "!", "%", "$"};
  if (regexMatchGroups_[3].str().length() == 1 &&
      std::find_if(validSymbols.begin(), validSymbols.end(), [this](auto &el) {
        if (el == regexMatchGroups_[3].str()) {
          std::cout << el << std::endl;
          return true;
        } else
          return false;
      }) != validSymbols.end()) {
            std::cout << "modulo!" << std::endl;
    operationCharacter_ = regexMatchGroups_[3].str();
    return actualError_;
  } else if (regexMatchGroups_[4].str().length() == 1 &&
             std::find_if(validSymbols.begin(), validSymbols.end(),
                          [this](auto &el) {
                            if (el == regexMatchGroups_[4].str()) {
                              return true;
                            } else
                              return false;
                          }) != validSymbols.end()) {
    operationCharacter_ = regexMatchGroups_[4].str();
    return actualError_;
  } else
    return ErrorCode::BadCharacter;
  }else return actualError_;
}

ErrorCode mathOperation::checkIfDivideByZero() {
  if (operationCharacter_ == "!" && actualError_ == ErrorCode::OK) {
    firstValue_ = std::stod(regexMatchGroups_[1].str());
    return ErrorCode::OK;
  } else if (actualError_ == ErrorCode::OK) {
    firstValue_ = std::stod(regexMatchGroups_[1].str());
    secondValue_ = std::stod(regexMatchGroups_[6].str());
  } else
    return actualError_;
  if (secondValue_ == 0)
    return ErrorCode::DivideBy0;
  else
    return actualError_;
}

ErrorCode mathOperation::checkIfSqrtOfNegativeNumber() {
  if (actualError_ == ErrorCode::OK) {
    if (operationCharacter_ == "$" && firstValue_ < 0) {
      return ErrorCode::SqrtOfNegativeNumber;
    }
    return actualError_;
  } else
    return actualError_;
}

ErrorCode mathOperation::checkIfmoduleOfNonIntegerValue() {
  int firstValueInt = static_cast<int>(firstValue_);
  int secondValueInt = static_cast<int>(secondValue_);

  if (static_cast<double>(firstValueInt) == firstValue_ &&
      static_cast<double>(secondValueInt) == secondValue_) {
    return actualError_;
  } else
    return ErrorCode::ModuleOfNonIntegerValue;
}

void mathOperation::calculateResult() {

  if (actualError_ == ErrorCode::OK && operationCharacter_.size() == 1) {

    auto it = FunctionalMap_.find(operationCharacter_[0]);
    result_ = it->second(firstValue_, secondValue_);
  }
}

void mathOperation::printRegexGroups() const {

  for(int i = 1; i <= 7; i++){
  std::cout << "RegexGroupNumber"<< i  << ": "<< regexMatchGroups_[i].str() << std::endl;
  std::cout << "RegexGroupNumberLength"<< i  << ": "<< regexMatchGroups_[i].str().length() << std::endl;
  }
  std::cout << "OperationCharacter:" << operationCharacter_ << std::endl;
}