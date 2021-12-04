#include <iostream>
#include <string>

#include "advancedCalculator.hpp"

void showResult(std::string line)
{
    double result { 0 };
    auto operationResult = process(line, &result);

    switch (operationResult) {
    case ErrorCode::OK:
        std::cout << line << "==" << result << '\n';
        break;
    case ErrorCode::BadCharacter:
        std::cout << "Entered Bad Character\n";
        break;
    case ErrorCode::BadFormat:
        std::cout << "Operation have Bad Format\n";
        break;
    case ErrorCode::DivideBy0:
        std::cout << "Cannot perform divide by 0\n";
        break;
    case ErrorCode::ModuleOfNonIntegerValue:
        std::cout << "Cannot perform module on non integers\n";
        break;
    case ErrorCode::SqrtOfNegativeNumber:
        std::cout << "Cannot perform root of negative number\n";
        break;
    }
}

int main()
{
    std::cout << "Enter operation or [quit] to exit:";
    for (std::string line; std::getline(std::cin, line);) {
        if (line == "quit") {
            break;
        }
        showResult(line);
    }

    return 0;
}
