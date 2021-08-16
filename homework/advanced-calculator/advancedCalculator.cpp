#include "advancedCalculator.hpp"


std::map<char, std::function<double(double a, double b)>> MapCommands_
{
    {'+', [](auto a, auto b) {return a + b; } },
    {'-', [](auto a, auto b) {return a - b; } },
    {'*', [](auto a, auto b) {return a * b; } },
    {'/', [](auto a, auto b) {return a / b; } },
    {'%', [](auto a, auto b) {return (static_cast<int>(a) % static_cast<int>(b)); }},
    {'^', [](auto a, auto b) {return std::pow(a,b);}},
    {'!', [](auto a, auto b) {return std::tgamma(a+1);}},
    {'$', [](auto a, auto b) {return pow(a,1.0/b); }}

};

ErrorCode process(std::string input, double* out) {
    ExpressionParser Expression(input);
    double d;

    if (MapCommands_.find(Expression.getOperation()) != MapCommands_.end()) {

switch(Expression.getOperation())
{

    case '!':
    if (std::stod(Expression.getOperand1())<0) {d = -1*(std::invoke(MapCommands_.find(Expression.getOperation())->second,-(std::stod(Expression.getOperand1())),0));} else
d = std::invoke(MapCommands_.find(Expression.getOperation())->second,std::stod(Expression.getOperand1()),0);
break;

    default:
d = std::invoke(MapCommands_.find(Expression.getOperation())->second,std::stod(Expression.getOperand1()),std::stod(Expression.getOperand2()));
break;

};

*out = d;
return ErrorCode::OK;
    } else {
        return ErrorCode::BadCharacter;
    };

    return ErrorCode::OK;
}



// try {
//     Operand1D_=std::stod(Operand1_);
// } catch (const std::invalid_argument&) {
//     return false;
//     throw;
// };