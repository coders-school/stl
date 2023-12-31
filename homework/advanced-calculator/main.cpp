#include "advancedCalculator.hpp"

#include <iostream>

int main() {
    std::string command;
    double answer;
    while (true) {
        std::getline(std::cin, command);
        if (command == "q") {
            break;
        }
        ErrorCode error = process(command, &answer);
        if (error == ErrorCode::OK) {
            std::cout << "Wynik: " << answer << "\n";
        } else {
            std::cout << error << "\n";
        }
    }
    return 0;
}
