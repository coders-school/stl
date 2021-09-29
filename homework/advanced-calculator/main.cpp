#include <iostream>
#include <string>
#include "advancedCalculator.hpp"

int main() {
    ErrorCode error{ErrorCode::BadFormat};
    std::string input{};
    double* pointer = nullptr;
    while (input != "exit" && input != "quit" && input != "q") {
        std::cout << "Enter query: ";
        std::cin >> input;
        error = process(input, pointer);
        switch (error) {
            case ErrorCode::OK:
                std::cout << *pointer << '\n';
                break;
            default:
                std::cout << "Something went wrong. Try again.\n";
        }
    }
}
