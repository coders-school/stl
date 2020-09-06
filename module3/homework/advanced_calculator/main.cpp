#include "advancedCalculator.hpp"

#include <iostream>

int main() {
    double result;
    ErrorCode error;
    error = process("-98 + 12.3 =", &result);
    if(error == ErrorCode::BadCharacter) {
        std::cout << result << "\n";
    }

}