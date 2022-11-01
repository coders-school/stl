#include "advancedCalculator.hpp"
#include <map>
#include <functional>
#include <cmath>

#include <iostream>
#include <sstream>

double addValues(double a, double b)
{
    return a+b;
}

double substractValues(double a, double b)
{
    return a-b;
}

double multiplyValues(double a, double b)
{
    return a+b;
}

double divideValues(double a, double b)
{
    return a/b;
}

double moduloValues(double a, double b)
{
    return (int)a % (int)b;
}

double powerValues(double a, double b)
{
    return pow(a,b);
}

double factorialValues(double a, double b)
{
    if (a >= 0) {
        return tgamma(a + 1);
    } else {
        return -tgamma(-a + 1);
    }
}

double sqrtValues(double a, double b)
{
    return sqrt(a);
}


std::map<char, std::function<double(double, double)>> operations
{
    {'+', addValues},
    {'-', substractValues},
    {'*', multiplyValues},
    {'/', divideValues},
    {'%', moduloValues},
    {'^', powerValues},
    {'!', factorialValues},
    {'$', sqrtValues}
};


std::string allowed_operations()
{
    std::string allowed_operation = "";
    std::for_each(operations.begin(), operations.end(), [&allowed_operation](auto operation){
        allowed_operation += operation.first;
    });
    return allowed_operation;
}

enum ErrorCode process(std::string oparation, double* x)
{
    const std::string allowed = allowed_operations();
    auto operation_iterator = oparation.begin();

    std::stringstream ss;
    ss.str(oparation);
    if(double lhs; ss >> lhs)
    {
        ++operation_iterator;
        if(char operation_character; ss >> operation_character)
        {
            ++operation_iterator;
            if(double rhs; ss >> rhs)
            {
                std::cout << "lhs = " << lhs << std::endl;
                std::cout << "operation_character = " << operation_character << std::endl;
                std::cout << "rhs = " << rhs << std::endl;
                
                auto calculate = operations[operation_character];
                *x = calculate(lhs, rhs);
                return ErrorCode::OK;
            }
            else
            {
                return ErrorCode::BadCharacter;
            }

        }
        else
        {
            return ErrorCode::BadCharacter;
        }
    }
    else
    {
        return ErrorCode::BadCharacter;
    }

    return ErrorCode::OK;
}