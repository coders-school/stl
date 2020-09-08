#include "advancedCalculator.hpp"
#include "mathOperation.hpp"
#include <algorithm>
#include <iostream>

ErrorCode process(std::string input, double &out) {

  mathOperation dataObject(input);
  out = dataObject.getResult();
  return dataObject.getErrorCode();
}
