#include "advancedCalculator.hpp"
#include <iostream>

int main() {
    double result{};
    auto error = AdvancedCalculator::process("  30 * -20   ", &result);
    if(error == AdvancedCalculator::ErrorCode::OK) {
        std::cout << result << '\n';
    }
}

