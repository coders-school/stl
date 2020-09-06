#include "advancedCalculator.hpp"

#include <iostream>

int main() {
    double result{};
    std::string input{};
    printInfo();
    while(true) {
        std::cout << ">>> ";
        getline(std::cin, input);
        if (input == "exit") {
            break;
        }
        auto ec = process(input, &result);
        if (ec == ErrorCode::OK) {
            std::cout << result << '\n';
        } else {
            std::cout << getErrorMsg(ec) << '\n';
        }
    }
}
