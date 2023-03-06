#include "advancedCalculator.hpp"

int main() {
    std::string input;
    double result;
    while (true) {
        std::cout << "Podaj wyrazenie do obliczenia " << std::endl;
        std::cin >> input;
        process(input, &result);
        std::cout << "Wynik:" << result << std::endl;
    }
}