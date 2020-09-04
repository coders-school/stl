#include <iostream>
#include <map>

#include "advancedCalculator.hpp"

const std::map<ErrorCode, std::string> errorNames{
    {ErrorCode::OK, "ErrorCode::OK"},
    {ErrorCode::BadCharacter, "ErrorCode::BadCharacter"},
    {ErrorCode::BadFormat, "ErrorCode::BadFormat"},
    {ErrorCode::DivideBy0, "ErrorCode::DivideBy0"},
    {ErrorCode::SqrtOfNegativeNumber, "ErrorCode::SqrtOfNegativeNumber"},
    {ErrorCode::ModuleOfNonIntegerValue, "ErrorCode::ModuleOfNonIntegerValue"}};

void calculate(const std::string& input) {
    double result = 0;
    auto error = process(input, &result);
    if (error != ErrorCode::OK) {
        std::cout << "You did it wrong!!! - " << errorNames.at(error) << '\n';
    } else {
        std::cout << "Result of " << input << " is: " << result << '\n';
    }
}

void informations() {
    std::cout << "Valid oprations:\n"
              << "Add [+]\n"
              << "Multiply [*]\n"
              << "Divide [/]\n"
              << "Substract [-]\n"
              << "Modulo [%] - Only intigers!\n"
              << "Factorial [!]\n"
              << "Power [^]\n"
              << "Root [$]\n";
    std::cout << "Sample valid command: 5 + 5 \n";
    std::cout << "To quit type: quit\n";
}

int main() {
    std::cout << "*** Advanced calculator ****\n";
    std::cout << "For more information type: help\n";
    for (std::string line; std::cout << ">>", std::getline(std::cin, line);) {
        if (line == "quit") {
            break;
        } else if (line == "help") {
            informations();
        } else {
            calculate(line);
        }
    }
    return 0;
}
