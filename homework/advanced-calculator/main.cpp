#include <iostream>
#include "ExpressionParser.hpp"
#include "advancedCalculator.hpp"

int main() {
    double d;
    std::string line;
    while (1) {
        std::cout<< "Write expression to count: " << "\n";
        std::getline(std::cin, line);
        if (line == "exit") {
            break;
        };

        switch (process(line, &d)) {
        case ErrorCode::OK: {
            std::cout << "Score of calculation: " << d << "\n";
            break;
        }
        case ErrorCode::BadCharacter: {
            std::cout << "ERROR: Bad character in the expression" << "\n";
            break;
        }
        case ErrorCode::BadFormat: {
            std::cout << "ERROR: Bad format in the expression" << "\n";
            break;
        }
        case ErrorCode::DivideBy0: {
            std::cout << "ERROR: Division by 0!" << "\n";
            break;
        }
        case ErrorCode::SqrtOfNegativeNumber: {
            std::cout << "ERROR: Square root of negative number!" << "\n";
            break;
        }
        case ErrorCode::ModuleOfNonIntegerValue: {
            std::cout << "ERROR: Module of non integer value" << "\n";
            break;
        }
        }
        std::cout << std::endl;
    }
};