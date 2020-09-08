#include "mathOperation.hpp"
#include "errorCodeEnum.hpp"
#include <cmath>
#include <cctype>
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
        if(actualError_ == ErrorCode::OK) calculateResult();

      };

double mathOperation::getResult() const { return result_; }
ErrorCode mathOperation::getErrorCode() const { return actualError_; }


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
  return static_cast<double>(static_cast<int>(firstValue)%
                             static_cast<int>(secondValue));
}
double mathOperation::factorial(double &firstValue, double &secondValue) {
  if(firstValue < 0){
    return 1;
  }else return static_cast<double>(std::tgamma(firstValue+1));
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
      "^(-?[0-9]+\\.?([0-9]+)?)(?:(?=!)(!)|(?!!)([\\+\\-\\*\\/\\^\\$%!#@&?;\\[\\]]?(\\\\)?)(-?[0-9]+\\.?([0-9]+)?))$");
  if (std::regex_match(dataString_, regexMatchGroups_, regexPattern_) == true) {
    return actualError_;
  } else
    return ErrorCode::BadFormat;
}

ErrorCode mathOperation::checkIfBadCharacter() {

  std::string badCharacters{"abcdefghijklmnopqrstuvwxyz=#;\\"};

   if(std::find_first_of(dataString_.begin(), dataString_.end(),
                  badCharacters.begin(), badCharacters.end()) != dataString_.end()){ return ErrorCode::BadCharacter; }

  if(actualError_ == ErrorCode::OK){

    std::vector<std::string> validSymbols{"+", "-", "*", "/",
                                          "!", "%", "$", "^"};
    if (regexMatchGroups_[3].str().length() == 1 &&
        std::find_if(validSymbols.begin(), validSymbols.end(),
                     [this](auto &el) {
                       if (el == regexMatchGroups_[3].str()) {
                         return true;
                       } else
                         return false;
                     }) != validSymbols.end()) {
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
  if (actualError_ == ErrorCode::OK && operationCharacter_ == "$") {
    if (operationCharacter_ == "$" && firstValue_ < 0) {
      return ErrorCode::SqrtOfNegativeNumber;
    }
    return actualError_;
  } else
    return actualError_;
}

ErrorCode mathOperation::checkIfmoduleOfNonIntegerValue() {
  if(operationCharacter_ == "%"){

  int firstValueInt = static_cast<int>(firstValue_);
  int secondValueInt = static_cast<int>(secondValue_);

  if (static_cast<double>(firstValueInt) == firstValue_ &&
      static_cast<double>(secondValueInt) == secondValue_) {
    return actualError_;
  } else
    return ErrorCode::ModuleOfNonIntegerValue;
  }return actualError_;
}

void mathOperation::calculateResult() {

  if (actualError_ == ErrorCode::OK && operationCharacter_.size() == 1) {

    auto it = FunctionalMap_.find(operationCharacter_[0]);
    result_ = it->second(firstValue_, secondValue_);
  }
}
