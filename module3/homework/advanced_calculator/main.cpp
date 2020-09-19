#include "advancedCalculator.hpp"

#include <iostream>
#include <string>
#include <vector>

int main(){

    /*enum class ErrorCode {
   0 OK,
   1 BadFormat,
   2 BadCharacter,
   3 DivideBy0,
   4 ModuleOfNonIntegerValue,
   5 SqrtOfNagativeNumber
    };*/

    ErrorCode ec{};
    std::string input {"13.4 ++ 12.43"};
    double result{};

    ec = process(input, &result);
    std::cout << result << "\n";

    std::cout << (int)ec << "\n";

return 0;
}
