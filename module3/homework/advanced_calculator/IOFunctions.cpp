#include "IOFunctions.hpp"
#include <iostream>


std::string readInput() {

  std::string inputString;

  std::getline(std::cin, inputString);
  return inputString;
}
void printResult(double result ) { std::cout << "" }
void printError(ErrorCode error);
