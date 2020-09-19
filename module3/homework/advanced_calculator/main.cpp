#include "advancedCalculator.hpp"

#include <iostream>
#include <string>
#include <vector>

int main(){

    std::string input {"2$1024 "};
    double result{};

    process(input, &result);
    std::cout << result << "\n";

return 0;
}
