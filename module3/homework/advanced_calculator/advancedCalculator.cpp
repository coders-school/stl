#include "advancedCalculator.hpp"
#include "mathOperation.hpp"
#include <algorithm>
#include <iostream>

ErrorCode process(std::string input, double &out) {

  mathOperation dataObject(input);
  dataObject.printString();
  dataObject.printRegexGroups();
  std::cout << "FirstValue: " << dataObject.getFirstValue() << std::endl;
  std::cout << "SecondValue: " << dataObject.getSecondValue() << std::endl;
  //cout << "SecondValue: " << dataObject.getSecondValue() << std::endl;
  dataObject.printErrorCode();
  std::cout << "Result: " << dataObject.getResult() << std::endl;

return dataObject.getErrorCode();

/*   ErrorCode error = dataObject.ValidateInputString();

  dataObject.printString();
  std::cout << dataObject.getFirstValue() << std::endl;
  std::cout << dataObject.getSecondValue() << std::endl;
  dataObject.printErrorCode();
  dataObject.CalculateResult();
  out = dataObject.getResult();
  std::cout << "Oto WYNIK: " << out;
  //return 
  return ErrorCode::OK; */
}