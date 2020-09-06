#include "advancedCalculator.hpp"

#include <cmath>
#include <functional>
#include <map>
#include <variant>

ErrorCode process(std::string input, double* out) {
    std::variant<std::function<double(double, double)>, std::function<int(int, int)>, std::function<double(double)>>
        functions;
    std::map<char, decltype(functions)> basicMathOperations{
        {'+', std::function<double(double, double)>([](double lhs, double rhs) { return lhs + rhs; })},
        {'-', std::function<double(double, double)>([](double lhs, double rhs) { return lhs - rhs; })},
        {'*', std::function<double(double, double)>([](double lhs, double rhs) { return lhs * rhs; })},
        {'/', std::function<double(double, double)>([](double lhs, double rhs) { return lhs / rhs; })},
        {'%', std::function<int(int, int)>([](int lhs, int rhs){ return lhs % rhs; })}, 
        {'!', std::function<double(double)>([](double lhs){ return std::tgamma(lhs + 1); })}, 
        {'^', std::function<double(double,double)>([](double lhs, double rhs){ return std::pow(lhs, rhs); })}, 
        {'$', std::function<double(double,double)>([](double lhs, double rhs){ return std::pow(lhs, 1/rhs); })}};
}
