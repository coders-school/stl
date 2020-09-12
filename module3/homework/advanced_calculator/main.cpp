#include <iostream>

#include "advancedCalculator.hpp"

int main() {
    double result{};

    ErrorCode error = process("5 !", &result);
    
    if (error == ErrorCode::OK) {
        std::cout << "Result : " << result << std::endl;
    } else {
        switch (error) {
        case ErrorCode::BadCharacter:
            std::cout << "Bad character!" << std::endl;
            break;
        case ErrorCode::BadFormat:
            std::cout << "Bad format!" << std::endl;
            break;
        case ErrorCode::DivideBy0:
            std::cout << "Division by zero!" << std::endl;
            break;
        case ErrorCode::ModuleOfNonIntegerValue:
            std::cout << "Modulus of non integers!" << std::endl;
            break;
        case ErrorCode::SqrtOfNegativeNumber:
            std::cout << "Root of negative number!" << std::endl;
            break;
        }
    }

    return 0;
}
