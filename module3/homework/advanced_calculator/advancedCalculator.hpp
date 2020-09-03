#pragma once

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

    void setFirst(double first);
    void setSecond(double second);
    void setOperation(std::string operation);

    void readVariables();

    // double add(double& first, double& second);
    // double subtract(double& first, double& second);
    // double multiplicate(double& first, double& second);
    // double divide(double& first, double& second);
    // double modulo(double& first, double& second);
    // double factorial(double& first, double& second);
    // double power(double& first, double& second);
    // double sqrt(double& first, double& second);

private:
    std::string inputString_{};
    double first_{};
    double second_{};
    std::string operation_{};
    double result_{};

    // std::map<char, std::function<double(double&, double&)>> FunctionalMap = {
    //     {'+', add},    {'-', subtract},  {'*', multiplicate}, {'/', divide},
    //     {'%', modulo}, {'!', factorial}, {'^', power},        {'$', sqrt}};
};

ErrorCode process(std::string input, double* out);
