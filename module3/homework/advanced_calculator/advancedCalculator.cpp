#include "advancedCalculator.hpp"

#include <cmath>
#include <functional>
#include <map>
#include <string>

const std::map<std::string, std::function<double(double, double)>> command = {{"+", std::plus<double>()},
                                                                              {"-", std::minus<double>()},
                                                                              {"*", std::multiplies<double>()},
                                                                              {"/", std::divides<double>()},
                                                                              {"%", std::modulus<double>()},
                                                                              {"^", [](double base, double exp) { return pow(base, exp); }},
                                                                              {"$", [](double base, double root) { return pow(base, 1.0 / root); }}};
