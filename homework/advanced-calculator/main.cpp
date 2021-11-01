#include <iostream>
#include <string>
#include "advancedCalculator.hpp"

int main() {
    ErrorCode error{ErrorCode::Undefined};
    std::string input{};
    double result{0};
    while (input != "exit" && input != "quit" && input != "q") {
        std::cout << "Enter query: ";
        std::getline(std::cin, input);
        error = process(input, &result);
        switch (error) {
            case ErrorCode::OK:
                std::cout << "= " << result << '\n';
                break;
            case ErrorCode::BadCharacter:
                std::cout << "Error: contains alphabetic characters\n";
                break;
            case ErrorCode::BadFormat:
                std::cout << "Error: Bad command formatting\n";
                break;
            case ErrorCode::Undefined:
                std::cout << "Error: Something went wrong\n";
                break;
        }
    }
}
