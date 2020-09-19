#include <cmath>
#include <functional>
#include <map>

const std::map<std::string, std::function<double(double, double)>> commands{
    {"+", std::plus<double>()},
    {"-", std::minus<double>()},
    {"*", std::multiplies<double>()},
    {"/", std::divides<double>()},
    {"%", std::modulus<int>()},
    {"^", [](double base, double Pow) { return std::pow(base, Pow); }},
    {"$", [](double base, double Pow) { return std::pow(base, 1.0 / Pow); }}};
