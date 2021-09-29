#include "advancedCalculator.hpp"
#include <algorithm>
#include <cctype>
#include <functional>
#include <iostream>
#include <map>
#include <string>

ErrorCode process(std::string input, double* out) {
    Operation operation = parse(input);
    out = nullptr;
    return ErrorCode::BadFormat;
}

auto sum = [](double a, double b) -> double {
    return a + b;
};

std::map<char, std::function<double(double, double)>> operations = { {'+', sum} };

Operation parse(const std::string & string) {
    Operation operation{};
    std::string stringClean{};
    std::copy_if(cbegin(string),
                 cend(string),
                 std::back_inserter(stringClean),
                 [](auto sign) {
                     return (!isspace(sign));
                 });
    int index = stringClean.find_first_of("+*/-%!^$");
    operation.a = std::stoi(stringClean.substr(0, index));
    operation.sign = stringClean[index];
    operation.b = std::stoi(stringClean.substr(index + 1));

    std::cout << string << '\n';
    std::cout << stringClean << '\n';
    std::cout << "Number A: " << operation.a << '\n';
    std::cout << "Sign: " << operation.sign << '\n';
    std::cout << "Number B: " << operation.b << '\n';

    return operation;
}
