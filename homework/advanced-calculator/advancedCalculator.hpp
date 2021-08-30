#pragma once
#include <iostream>
#include <algorithm>
#include <map>
#include <functional>

enum class errorCode
{
    Ok,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNagativeNumber,
    ModuleOfNonIntegerValue 
};

std::map<char, std::function<errorCode(double, double)>> kalkulator
{
    {'+', [](double numOne, double numTwo){
            std::cout << numOne + numTwo;
            return errorCode::Ok;
        }}
};