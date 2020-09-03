#include <iostream>
#include <string>

#include "advancedCalculator.hpp"

void printErrorCode(std::string s) {
    double result;
    switch (process(s, &result))
    {
    case ErrorCode::OK:
        std::cout << "OK, result = " << result << '\n';
        break;
    case ErrorCode::BadCharacter:
        std::cout << "Bad character" << '\n';
    case ErrorCode::BadFormat:
        std::cout << "Bad format" << '\n';
    case ErrorCode::DivideBy0:
        std::cout << "Divide by 0" << '\n';
    case ErrorCode::ModuleOfNonIntegerValue:
        std::cout << "Module of non integer value" << '\n';
    case ErrorCode::SqrtOfNegativeNumber:
        std::cout << "Sqrt on negative value" << '\n';
    default:
        break;
    }
}

int main() {
    std::string input {};
    while (input != "q")
    {
        std::cout << "\033[2J\033[1;1H";
        std::cout << "Enter equation: ";
        std::getline(std::cin, input);
        printErrorCode(input);
    }
    
    return 1;
}
