#include "advancedCalculator.hpp"
#include <iostream>

int main() {
    double result{};
    auto error = AdvancedCalculator::process("225 %1000", &result);
    
    if(error == AdvancedCalculator::ErrorCode::OK)
       std::cout << result << '\n'; 


    return 0;
}
