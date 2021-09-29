#include <iostream>
#include <string>
#include "advancedCalculator.hpp"

int main() {
    ErrorCode error{ErrorCode::OK};
    std::string input{};
    double* pointer = nullptr;
    while (input != "exit" && input != "quit" && input != "q") {
        std::cout << "Provide command: ";
        std::cin >> input;
        error = process(input, pointer);
        if (pointer) {
            std::cout << *pointer << '\n';
        }
        std::cout << static_cast<std::underlying_type<ErrorCode>::type>(error) << '\n';
    }
}
