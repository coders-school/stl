#include "advancedCalculator.hpp"

std::map<const char, std::function<double(const double, const double)>> calculator;


ErrorCode process(std::string input, double* out) {

    return ErrorCode::OK;
}

void calculatorStructureInit() {
    auto plus = std::plus<double>();
    calculator.insert(std::make_pair('+', std::plus<double>());

    // Dodawanie, mnożenie, dzielenie, odejmowanie (+, * , / , -)
    // Modulo (%)
    // Obliczanie silni (!)
    // Podnoszenie liczby do potęgi (^)
    // Obliczanie pierwiastka ($)

}