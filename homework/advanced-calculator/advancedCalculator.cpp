#include <algorithm>
#include <cmath>
#include <functional>
#include <map>

#include "advancedCalculator.hpp"

ErrorCode process(std::string input, double* out){
    
    return ErrorCode::OK;
}

double addition(const double a, const double b){
    return a + b;
}

double substract(const double a, const double b){
    return a - b;
}

double multiply(const double a, const double b){
    return a * b;
}

double divide(const double a, const double b){
    return a / b;
}

int modulo(const double a, const double b){
    return static_cast<int>(a) % static_cast<int>(b);
}

int factorial(double a, const double){
    return std::tgamma(static_cast<int>(a))*a;
}

int power(const double a, const double b){
    return std::pow(a,b);
}

double sqrtRoot(const double a, const double b){
    return std::pow(a,1.0 / b);
}


std::map<char,std::function<double(const double, const double)>> commands{
    {'+' , addition},
    {'-' , substract},
    {'*' , multiply},
    {'/' , divide},
    {'%' , modulo},
    {'!' , factorial},
    {'^' , power},
    {'$' , sqrtRoot}
};

//Function shall remove all white spaces in given string 
void removeWhiteSpaces(std::string &input){
    input.erase(std::remove_if(input.begin(),input.end(),
                                [](char zn){ return zn == ' ';}),input.end());
}

//Function shall return true if given char is in commands
bool checkIfCharIsInCommands(const char com){
    return commands.find(com) != commands.end();
}