#include "advancedCalculator.hpp"

int main() {
  std::string input {};
  
  while(std::getline(std::cin,input) && requestForQuit(input)){
    double result {};
    ErrorCode codeAnswer = process(input,&result);
    if(codeAnswer == ErrorCode::OK){
      std::cout << result;
    }  
  }
  std::cout << "uff";
} 