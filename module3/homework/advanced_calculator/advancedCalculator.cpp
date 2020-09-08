#include "advancedCalculator.hpp"
#include "mathOperation.hpp"
#include <algorithm>
#include <iostream>

ErrorCode process(std::string input, double &out) {

  mathOperation dataObject(input);
  //dataObject.printString();
  //dataObject.printRegexGroups();
  //std::cout << "FirstValue: " << dataObject.getFirstValue() << std::endl;
  //std::cout << "SecondValue: " << dataObject.getSecondValue() << std::endl;
  dataObject.printErrorCode();
  //std::cout << "Result: " << dataObject.getResult() << std::endl;
  out = dataObject.getResult();
  return dataObject.getErrorCode();
}