#include "advancedCalculator.hpp"
#include <iostream>
ErrorCode errors;

std::map<char, std::any>
    operations{
        {'+', std::function<double(double x, double y)>([](double x, double y) -> double { return x + y; })},
        {'-', std::function<double(double x, double y)>([](double x, double y) -> double { return x - y; })},
        {'*', std::function<double(double x, double y)>([](double x, double y) -> double { return x * y; })},
        {'/', std::function<double(double x, double y)>([](double x, double y) -> double { return x / y; })},
        {'^', std::function<double(double x, double y)>([](double x, double y) -> double { return std::pow(x, y); })},
        {'$', std::function<double(double x, double y)>([](double x, double y) -> double { return std::pow(x, 1.0 / y); })},
        {'%', std::function<int(int x, int y)>([](int x, int y) -> int { return x % y; })},
        {'!', std::function<double(double)>([](double x) -> double {
            std::string b=std::to_string(abs(x));
           double result = std::tgamma(std::stod(b) + 1.0);
           if (x<0.0){
            result*=-1.0;
           }
    return result; })}};

ErrorCode process(std::string input, double* out) {
    input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
    std::regex charsetRegex("[^*+,. %0-9^/!$-]");
    if (std::regex_search(input, charsetRegex)) {
        std::cout << "Bad character\n";
        return ErrorCode::BadCharacter;
    }
    std::regex operatorRegex("^[-]?[[:digit:]]+[.]?[[:digit:]]*[$*+/%^-]{1}[-]?[[:digit:]]+[.]?[[:digit:]]*$");
    std::regex factorialRegex("^[-]?[[:digit:]]+[.]?[[:digit:]]*[!]{1}$");
    if (!((std::regex_match(input, operatorRegex)) || (std::regex_match(input, factorialRegex)))) {
        std::cout << "Bad format" << std::endl;
        return ErrorCode::BadFormat;
    }
    if (size_t found = input.find('$'); found != std::string::npos && input[0] == '-') {
        std::cout << "SqrtOfNegativeNumber" << std::endl;
        return ErrorCode::SqrtOfNegativeNumber;
    }
    bool percentFound = (input.find('%') != std::string::npos);
    bool dotFound = (input.find('.') != std::string::npos);
    if (percentFound && dotFound) {
        std::cout << "ModuleOfNonIntegerValue" << std::endl;
        return ErrorCode::ModuleOfNonIntegerValue;
    }
    std::regex divideByZeroRegex(".*/[-]?0[.]?[0]*$");
    if (std::regex_match(input, divideByZeroRegex)) {
        std::cout << "DivideBy0" << std::endl;
        return ErrorCode::DivideBy0;
    }
    char operation{};
    int pos{};
    std::string charactersToFind{"+/*^!%$-"};
    for (char c : charactersToFind) {
        auto it = input.find(c, 1);
        if (it != std::string::npos) {
            pos = it;
            operation = input[it];
            break;
        }
    }
    double a = std::stof(input.substr(0, pos));
    double b{};
    if (!(operation == '!')) {
        b = std::stof(input.substr(pos + 1));
    }
    switch (operation) {
    case '+': {
        *out = std::any_cast<decltype(add)>(operations['+'])(a, b);
        break;
    }
    case '-': {
        *out = std::any_cast<decltype(substract)>(operations['-'])(a, b);
        break;
    }
    case '*': {
        *out = std::any_cast<decltype(multipl)>(operations['*'])(a, b);
        break;
    }
    case '/': {
        *out = std::any_cast<decltype(divide)>(operations['/'])(a, b);
        break;
    }
    case '%': {
        *out = std::any_cast<decltype(modulo)>(operations['%'])(a, b);
        break;
    }
    case '!': {
        *out = std::any_cast<decltype(factorial)>(operations['!'])(a);
        break;
    }
    case '^': {
        *out = std::any_cast<decltype(power)>(operations['^'])(a, b);
        break;
    }
    case '$': {
        *out = std::any_cast<decltype(root)>(operations['$'])(a, b);
        break;
    }
    }
    return ErrorCode::OK;
}
