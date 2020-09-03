#include "advancedCalculator.hpp"
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <regex>

std::map<std::string, std::function<double(double, double)>> operations{
    {"+", std::plus<double>()},
    {"-", std::minus<double>()},
    {"*", std::multiplies<double>()},
    {"/", std::divides<double>()},
    {"%", std::modulus<int>()},
    //{"!", [](double a1, double b1){return 2.5;}},
    {"^", [](double base, double nthPow) { return std::pow(base, nthPow); }},
    {"$", [](double base, double nthRoot) { return std::pow(base, 1.0 / nthRoot); }}};

ErrorCode process(std::string input, double* out) {
    //bad character input handling?

    std::cout << input << '\n';
    std::smatch matches;

    std::regex operationPattern(R"(([-]?\d+.\d+|[-]?\d+)\s?([+*/\-%!^$])\s?([-]?\d+.\d+|[-]?\d+))");
    std::regex factorialPattern(R"((\d+)\s?(\!))");

    if (std::regex_search(input, matches, operationPattern)) {
        double val1 = std::stod(matches[1]);
        std::string operation = matches[2];
        double val2 = std::stod(matches[3]);
        std::cout << matches[0] << '\t' << matches[1] << '\t' << matches[2] << '\t' << matches[3] << '\n';
        *out =  operations.at(operation)(val1, val2);
        std::cout<<*out<<'\n';

    } else if (std::regex_search(input, matches, factorialPattern)) {
        std::cout << matches[0] << '\t' << matches[1] << '\t' << matches[2] << '\n';

    } else {
        std::cout << "not found\n";
    }

    if (matches.size() == 3) {
        //factorial
        std::cout << "Factorial dealing[!] \n";
        return ErrorCode::Ok;
    }

    if (matches.size() == 4) {
        std::cout << "Operations handling[" << matches[2] << "]\n";
        return ErrorCode::Ok;
        //Operations handling
    }

    return ErrorCode::BadCharacter;
}
