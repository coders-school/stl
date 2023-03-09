#include "advancedCalculator.hpp"

int main() {
    std::string input;
    double result;
    while (true) {
        result = 0;
        std::cout << "Podaj wyrazenie do obliczenia " << std::endl;
        std::cin >> input;
        process(input, &result);
        std::cout << std::setprecision(10) << "Wynik: " << result << std::endl;
    }
}