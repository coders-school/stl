#include "advancedCalculator.hpp"
#include "mathOperation.hpp"
#include <algorithm>
#include <iostream>

ErrorCode process(std::string input, double &out) {

  mathOperation dataObject;
  dataObject.setInputString(input);
  ErrorCode error = dataObject.ValidateInputString();
  dataObject.setErrorCode(error);
  std::cout << dataObject.getFirstValue() << std::endl;
  std::cout << dataObject.getSecondValue() << std::endl;
  dataObject.printErrorCode();
  //calculate result
  out = dataObject.getResult();
  //return 
  return ErrorCode::OK;
}