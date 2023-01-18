#include "advancedCalculator.hpp"

#include <iostream>

std::unordered_map<ErrorCode, std::string, HashForErrorCode> errorMsg = {
    {ErrorCode::OK, "OK"},
    {ErrorCode::BadCharacter, "BadCharacter"},
    {ErrorCode::BadFormat, "BadFormat"},
    {ErrorCode::DivideBy0, "DivideBy0"},
    {ErrorCode::SqrtOfNegativeNumber, "SqrtOfNegativeNumber"},
    {ErrorCode::ModuleOfNonIntegerValue, "ModuleOfNonIntegerValue"}};

int main() {
    std::string command = "";
    double result = 0;
    ErrorCode status = ErrorCode::BadFormat;

    while (command != "q") {
        std::cout << "Read command" << std::endl;

        // get line without leading whitespaces
        std::getline(std::cin >> std::ws, command);

        status = process(command, &result);

        if (status == ErrorCode::OK) {
            std::cout << "Result: " << std::scientific << result << std::endl;
        } else {
            std::cout << errorMsg[status] << std::endl;
        }
    }

    return 0;
}
