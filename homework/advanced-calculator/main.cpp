#include <iostream>
#include<string>
#include "advancedCalculator.hpp"

int main() {
    double output = 0;
    std::string value;
   
   while(getline(std::cin,value)){

   process(value,&output);

   }


    return 0;
}