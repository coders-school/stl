#include <iostream>

#include "advancedCalculator.hpp"

void printAction() {
    std::cout << "\nNext is your action: \n";
    std::cout << "1) Calculate \n2) Help \n3) Exit\n\n";
}
void printIntro() {
    std::cout << std::string(30, '*') << '\n';
    std::cout << "***   Advanced Calcualor   *** \n";
    std::cout << std::string(30, '*') << '\n';
    printAction();
}

void printHelp() {
    std::cout << "Available math oprations:\n \n"
              << "Add [+]\n"
              << "Substract [-]\n"
              << "Multiply [*]\n"
              << "Divide [/]\n"
              << "Modulo [%]\n"
              << "Factorial [!]\n"
              << "Power [^]\n"
              << "Root [$]\n"
              << "Exit: [x]\n";

    std::cout << "\nFor example: Insert expression in that style: \"2 + 2\" \n";
}

const std::map<ErrorCode, std::string> errorHandler{
    {ErrorCode::OK, "OK! \n"},
    {ErrorCode::BadCharacter, "You insert a bad character !\n"},
    {ErrorCode::BadFormat, "You insert your expression in bad format !\n"},
    {ErrorCode::DivideBy0, "You can not divide by 0 ! \n"},
    {ErrorCode::SqrtOfNegativeNumber, "You can not get sqrt from negative number ! \n"},
    {ErrorCode::ModuleOfNonIntegerValue, "You can not get modulo of non integer value ! \n"}};

void calculate(std::string input) {
    ErrorCode mathOperation;
    double result = 0;
    mathOperation = process(input, &result);
    if (mathOperation == ErrorCode::OK) {
        std::cout << "result = " << result << std::endl;
    } else {
        std::cout << errorHandler.at(mathOperation);
    }
}

int main() {
    printIntro();

    std::string input;
    std::string action;

    while (true) {
        std::getline(std::cin, action);
        if (action == "1") {
            std::cout << "Insert expression to calculate your math operation: ";
            std::getline(std::cin, input);
            calculate(input);
        } else if (action == "2") {
            std::cout << "--- Print help: ---\n \n";
            printHelp();

        } else {
            break;
        }

        if (input == "q") {
            break;
        }

        std::cout << "--------------\n";
        printAction();
    }

    return 0;
}