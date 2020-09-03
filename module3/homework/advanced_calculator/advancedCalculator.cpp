#include "advancedCalculator.hpp"

#include <iostream>
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

void AdvancedCalculator::setFirst(double first) {
    this->first_ = first;
};
void AdvancedCalculator::setSecond(double second) {
    this->second_ = second;
};
void AdvancedCalculator::setOperation(std::string operation) {
    this->operation_ = operation;
};

void AdvancedCalculator::readVariables() {
    std::regex expression("(\\S?\\s?\\d+\\.?\\d*)\\s?([-+*\\/^$!%])?\\s?(\\S?\\d+\\.?\\d*)?");
    std::smatch m;
    std::string input = this->getInputString();

    while (std::regex_search(input, m, expression)) {
        this->setFirst(std::stod(m[1]));
        if (m[2] != '!') {
            this->setSecond(std::stod(m[3]));
        }
        this->setOperation(m[2]);
        input = m.suffix().str();
    }
};

ErrorCode process(std::string input, double* out) {
    AdvancedCalculator ac(input);
    ac.readVariables();
    std::cout << ac.getFirst() << std::endl;
    std::cout << ac.getOperation() << std::endl;
    std::cout << ac.getSecond() << std::endl;
    return ErrorCode::OK;
}
