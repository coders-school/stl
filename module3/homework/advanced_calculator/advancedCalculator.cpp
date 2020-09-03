#include "advancedCalculator.hpp"

#include <functional>
#include <iostream>
#include <map>
#include <regex>

AdvancedCalculator::AdvancedCalculator(std::string input) : inputString_(input){};

std::string AdvancedCalculator::getInputString() {
    return this->inputString_;
};

double AdvancedCalculator::getFirst() {
    return this->first_;
};
double AdvancedCalculator::getSecond() {
    return this->second_;
};
std::string AdvancedCalculator::getOperation() {
    return this->operation_;
};
std::string AdvancedCalculator::getFullEquation() {
    return this->fullEquation_;
};

void AdvancedCalculator::setFirst(double first) {
    this->first_ = first;
};
void AdvancedCalculator::setSecond(double second) {
    this->second_ = second;
};
void AdvancedCalculator::setOperation(std::string operation) {
    this->operation_ = operation;
};
void AdvancedCalculator::setFullEquation(std::string operation) {
    this->fullEquation_ = operation;
};

void AdvancedCalculator::readVariables() {
    std::regex expression("(\\S?\\s?\\d+\\.?\\d*)\\s?([-+*\\/^$!%])?\\s?(\\S?\\d+\\.?\\d*)?$");
    std::smatch m;
    std::string input = this->getInputString();

    while (std::regex_search(input, m, expression)) {
        this->setFullEquation(m[0]);
        this->setFirst(std::stod(m[1]));
        if (m[2] != '!') {
            this->setSecond(std::stod(m[3]));
        }
        this->setOperation(m[2]);
        input = m.suffix().str();
    }
};

std::map<std::string, std::function<double(double, double)>> operationsMap{
    {"+", std::plus<double>()},
    {"-", std::minus<double>()},
    {"*", std::multiplies<double>()},
    {"/", std::divides<double>()},
    {"%", std::modulus<int>()},
    {"!", [](double number, double zero) { return number != 1.0 ? tgamma(number) : 1.0; }},
    {"^", [](double base, double exponent) { return pow(base, exponent); }},
    {"$", [](double num, double root) { return pow(num, 1.0 / root); }}};

ErrorCode process(std::string input, double* out) {
    AdvancedCalculator ac(input);
    ac.readVariables();
    double first = ac.getFirst();
    double second = ac.getSecond();
    std::string operation = ac.getOperation();
    std::cout << operationsMap.at(ac.getOperation())(ac.getFirst(), ac.getSecond()) << std::endl;
    if (ac.getFullEquation() != input) {
        return ErrorCode::BadFormat;
    };
    if (operation == "$" && first < 0) {
        return ErrorCode::SqrtOfNegativeNumber;
    } else if (operation == "/" && second == 0) {
        return ErrorCode::DivideBy0;
    } else if (operation == "%") {
        return ErrorCode::ModuleOfNonIntegerValue;
    } else {
        *out = operationsMap.at(ac.getOperation())(ac.getFirst(), ac.getSecond());
        return ErrorCode::OK;
    }
    // std::cout << ac.getFirst() << std::endl;
    // std::cout << ac.getOperation() << std::endl;
    // std::cout << ac.getSecond() << std::endl;
    // return ErrorCode::OK;
}
