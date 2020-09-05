#include <iostream>
#include <string>

#include "advancedCalculator.hpp"

void calculate(const std::string& input) {
    double result;

    switch (process(input, &result)) {
        case ErrorCode::OK:
            std::cout << "Result: " << result << '\n';
            break;
        case ErrorCode::BadCharacter:
            std::cout << "Wrong character\n";
            break;
        case ErrorCode::BadFormat:
            std::cout << "Wrong format\n";
            break;
        case ErrorCode::DivideBy0:
            std::cout << "Don't divide by 0. Match Error\n";
            break;
        case ErrorCode::SqrtOfNegativeNumber:
            std::cout << "Don't use square root of negative number. Match Error\n";
            break;
        case ErrorCode::ModuleOfNonIntegerValue:
            std::cout << "Don't use modulo of non-integer value. Match Error\n";
            break;
    }
}

int main() {
    std::string input;

    for(;;){
        std::cout << "Enter expression to calculate (q to exit): ";
        std::getline(std::cin, input);

        if (input == "q") {
            break;
        }

        calculate(input);
    }
    return 0;
}
