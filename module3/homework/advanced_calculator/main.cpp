#include "IOFunctions.hpp"
#include "advancedCalculator.hpp"
#include "mathOperation.hpp"
#include <memory>
int main() {

   bool returnFlag = true;
   while (returnFlag) {
    
    double result;
    ErrorCode errorCodeValue = process(readInput(), result);
    returnFlag = askIfWantToExit();
  }
  return 0;
}