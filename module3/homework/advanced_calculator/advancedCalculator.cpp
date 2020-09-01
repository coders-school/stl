#include "advancedCalculator.hpp"

#include <cmath>
#include <functional>
#include <map>

const std::map<char, std::function<double(double, double)>> equation {
    {'+', std::plus<double>()},
    {'-', std::minus<double>()},
    {'*', std::multiplies<double>()},
    {'/', std::divides<double>()},
    //{'!', },
    {'^', [](double base, double exp) { return std::pow(base, exp); } },
    {'$', [](double base, double exp) { return std::pow(base, 1/exp); } }
};

ErrorCode process(std::string operation, double* result) {
    return ErrorCode::OK;
}