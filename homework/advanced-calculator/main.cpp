#include <iomanip>
#include <iostream>
#include <type_traits>
#include "advancedCalculator.hpp"

std::ostream& operator<<(std::ostream& os, const ErrorCode& obj) {
    os << static_cast<std::underlying_type<ErrorCode>::type>(obj);
    return os;
};
int main() {
    // std::cout << std::any_cast<decltype(add)>(operations['+'])(3.14, 5) << "\n";
    // std::cout << std::any_cast<decltype(substract)>(operations['-'])(3.14, 5) << "\n";
    // std::cout << std::setprecision(2) << std::any_cast<decltype(factorial)>(operations['!'])(-13) << "\n";
    // std::cout << std::any_cast<decltype(root)>(operations['$'])(13.71, -4) << "\n";

    double* result = new double;

    std::cout << std::fixed << process("3.435!", result);
    // std::cout << 255%1000 << std::endl;
    return 0;
}
