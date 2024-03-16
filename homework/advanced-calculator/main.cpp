#include <algorithm>
#include <cmath>
#include <iostream>
#include <regex>
#include "advancedCalculator.hpp"

int main() {
    std::string input = "123 % 0.0005";

    double x = 0;
    ErrorCode response;
    response = process(input, &x);

    if (response == ErrorCode::ModuleOfNonIntegerValue) {
        std::cout << x << std::endl;
    }

    return 0;
}