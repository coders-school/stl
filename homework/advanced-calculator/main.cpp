#include <iostream>

#include "advancedCalculator.hpp"

int main() {
    double result;
    ErrorCode errorCode = process("2 + 2", &result);

    switch (errorCode) {
    case ErrorCode::OK:
        std::cout << result << std::endl;
        break;
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
        std::cout << "Modulus of non-integer value!" << std::endl;
        break;
    case ErrorCode::SqrtOfNegativeNumber:
        std::cout << "Root of negative number!" << std::endl;
        break;
    }

    return 0;
}
