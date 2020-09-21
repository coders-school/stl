#include "advancedCalculator.hpp"
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>

const std::map<char, std::function<double(double, double)>> operations {
    {'+', std::plus<double>()},
    {'*', std::multiplies<double>()},
    {'/', std::divides<double>()},
    {'-', std::minus<double>()},
    {'%', std::modulus<int>()},
    {'!', [](double firstNum, double secNum) { return factorial(firstNum, secNum); }},
    {'^', [](auto firstNum, auto secNum) { return std::pow(firstNum, secNum); }},
    {'$', [](auto firstNum, auto secNum) { return std::pow(firstNum, 1.0 / secNum); }}
};

double factorial (double firstNum, double secNum) {
    return firstNum <= 0.0 ? 1.0 : std::tgamma(firstNum + 1.0 + secNum - secNum);
}

void removeSpace(std::string & input) {
    input.erase(std::remove_if(input.begin(), input.end(), [](auto el) { return std::isspace(el); }), input.end());
}

char findOperatorSign(std::string input) {
    auto operationIt = std::find_if(std::next(input.begin()), input.end(), [](auto el) { return operations.find(el) != operations.cend(); });
    return *operationIt;
}

double findFirstValue(std::string input) {
    auto operationIt = std::find_if(std::next(input.begin()), input.end(), [](auto el) { return operations.find(el)!= operations.cend(); });
    if (operationIt == input.end()) {
        return 0.0;
    } 
    return std::stod(std::string {input.begin(), operationIt});
}

double findSecondValue(std::string input) {
    auto operationIt = std::find_if(std::next(input.begin()), input.end(), [](auto el) { return operations.find(el) != operations.cend(); });
    if (operationIt == input.end()) {
        return 0.0;
    } 
    return std::stod(std::string {std::next(operationIt), input.end()});
}

double calculate(std::string input) {
    return operations.at(findOperatorSign(input))(findFirstValue(input), findSecondValue(input));
}

void startCalculate() {
    printWelcomeScreen();
    mainLoop();
    printGoodByeScreen();
}

void printWelcomeScreen() {
    std::cout << "Welcome in calculator for professionals. \n";
}

void makeAction(Action choice) {
    switch (choice) {
        case Action::Calculate: {
            std::string input;
            removeSpace(input);
            double output = calculate(input);
            std::getline(std::cin, input);
            process(input, & output);
            std::cout << "Result: \n" << output;
            break;
        }
        case Action::Help: {
            printHelp();
            break;
        }
        case Action::Exit: {
            break;
        }
        default:
            std::cout << "I can't do this. \n";  
    }
}

void mainLoop() {
    while (true) {
        std::cout << "Choose what you want to do: \n"
                  << "1 - calculate \n 2 - help \n 3 - end \n";
        int pickAction;
        std::cin >> pickAction;
        makeAction(static_cast<Action>(pickAction));
        if (static_cast<Action>(pickAction) == Action::Exit) {
            break;
        }
    }
}

void printHelp() {
    std::cout << "You can use operations: \n"
              << "Add [+] \n"
              << "Multiply [*] \n"
              << "Divide [/] \n"
              << "Substract [-] \n"
              << "Modulo [%] \n"
              << "Factorial [!] \n"
              << "Power [^] \n"
              << "Root [$] \n ";
}

void printGoodByeScreen() {
    std::cout << "Thank you for using our services. \n";
}

bool isComma(const char input) {
    return input == '.' || ',';
}

bool isBadCharacter(std::string input) {
    return false;
    //(std::any_of(input.cbegin(), input.cend(), [](auto el) { 
     //   return !(std::isdigit(el) || std::isspace(el) || operations.find(el) != operations.cend()); }));
}

bool isBadFormat(std::string input) {
    // if (input.back() == '!' ) {
    //     return (std::any_of(input.cbegin(), input.cend(), [](auto el) { 
    //         return !(isComma(el) || operations.find(el) != operations.cend()); }));
    // }
    return false;
    //(operations.find(input.front()) != operations.end() && input.front() != '-');
}

bool isDivideBy0(std::string input) {
    // if (input.back() == '!' ) {
    //     return false;
    // }
    // return findSecondValue(input) == 0.0;
    return false;
}

bool isSqrtOfNegativeNumber(std::string input) {
    // auto operationIt = std::find_if(std::next(input.begin()), input.end(), [](auto el) { return operations.find(el) != operations.cend(); });
    // double firstValue = std::stod(std::string {input.begin(), operationIt});
    return false;
    //firstValue < 0;
}

bool isModuleOfNonIntegerValue(std::string input) {
    // auto operationIt = std::find_if(std::next(input.begin()), input.end(), [](auto el) { return operations.find(el) != operations.cend(); });
    // double firstValue = std::stod(std::string {input.begin(), operationIt});
    // int integerValue = (int)firstValue;
    return false;
    //integerValue != firstValue;
}

ErrorCode process(std::string input, double* out) {
    if (isBadCharacter(input)) {
        return ErrorCode::BadCharacter;
    } else if (isBadFormat(input)) {
        return ErrorCode::BadFormat;
    } else if (isDivideBy0(input)) {
        return ErrorCode::DivideBy0;
    } else if (isSqrtOfNegativeNumber(input)) {
        return ErrorCode::SqrtOfNegativeNumber;
    } else if (isModuleOfNonIntegerValue(input)) {
        return ErrorCode::ModuleOfNonIntegerValue;
    } else {
        *out = calculate(input);
        return ErrorCode::OK;
    }
}
