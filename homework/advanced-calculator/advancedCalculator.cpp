
#include "advancedCalculator.hpp"
#include <functional>
#include <map>
#include <string>


// Dodawanie, mnożenie, dzielenie, odejmowanie (+, * , / , -)
// Modulo (%)
// Obliczanie silni (!)
// Podnoszenie liczby do potęgi (^)
// Obliczanie pierwiastka ($)

std::map<char, std::function<double(double first, double second)>>calculator_functions = {
    {'+',[](double first, double second){return first + second;}},
};

// ErrorCode process(std::string input, double* out);