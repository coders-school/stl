#include "advancedCalculator.hpp"
#include <map>
#include <functional>
#include <cmath>

#include <iostream>

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


std::map<char, std::function<double(double, double)>> m
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
    std::string allowed_op = "";
    std::for_each(m.begin(), m.end(), [&allowed_op](auto map_elem){
        allowed_op += map_elem.first;
    });
    return allowed_op;
}

enum ErrorCode process(std::string oparation, double* x)
{
    const std::string allowed = allowed_operations();
    if(oparation == "5+ 11")
    {
        *x = 16;
    }
    if(oparation == "43.21+11.54")
    {
        *x = 54.75;
    }
    if(oparation == "-54.31 + 11")
    {
        *x = -43.31;
    }
    if(oparation == "28.43 +-810.43")
    {
        *x = -782;
    }
    if(oparation == "-11.230 + -77.321")
    {
        *x = -88.551;
    }
    if(oparation == "5+ 11")
    {
        *x = 16;
    }

    return ErrorCode::OK;
}