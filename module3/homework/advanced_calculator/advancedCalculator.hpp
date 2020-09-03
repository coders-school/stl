#pragma once

#include <cmath>
#include <functional>
#include <map>
#include <string>
#include <vector>

enum class ErrorCode { OK, BadCharacter, BadFormat, DivideBy0, SqrtOfNegativeNumber, ModuleOfNonIntegerValue };

class AdvancedCalculator {
public:
    AdvancedCalculator(std::string input);
    std::string getInputString();
    double getFirst();
    double getSecond();
    std::string getOperation();
    std::string getFullEquation();

    void setFirst(double first);
    void setSecond(double second);
    void setOperation(std::string operation);
    void setFullEquation(std::string operation);

    void readVariables();

private:
    std::string inputString_{};
    std::string fullEquation_{};
    double first_{};
    double second_{};
    std::string operation_{};
    double result_{};

    std::map<std::string, std::function<double(double, double)>> operationsMap{};
};

ErrorCode process(std::string input, double* out);
