#include <iostream>
#include <string>

#include "advancedCalculator.hpp"

void calculate(const std::string& input) {
    double result{};

    switch (process(input, &result)) {
    case ErrorCode::OK:
        std::cout << "Result: " << result << '\n';
        break;
    case ErrorCode::BadCharacter:
        std::cout << "Error!!! Bad character\n";
        break;
    case ErrorCode::BadFormat:
        std::cout << "Error!!! Bad format\n";
        break;
    case ErrorCode::DivideBy0:
        std::cout << "Error!!! Divide by 0\n";
        break;
    case ErrorCode::SqrtOfNagativeNumber:
        std::cout << "Error!!! Square root of negative number\n";
        break;
    case ErrorCode::ModuleOfNonIntegerValue:
        std::cout << "Error!!! Modulo of non-integer value\n";
        break;
    }
}

int main() {
    std::string input;

    while (true) {
        std::cout << "Enter expression to calculate (q to exit): ";
        std::getline(std::cin, input);

        if (input == "q") {
            break;
        }

        calculate(input);

        std::cout << "--------------\n";
    }
    return 0;
}
