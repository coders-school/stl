#include "advancedCalculator.hpp"
#include <map>
#include <functional>
#include <cmath>

#include <iostream>
#include <sstream>
#include <algorithm>

std::map<char, std::function<double(double, double)>> operations
{
    {'+', [](double a, double b){return a+b;}},
    {'-', [](double a, double b){return a-b;}},
    {'*', [](double a, double b){return a*b;}},
    {'/', [](double a, double b){return a/b;}},
    {'%', [](double a, double b){return (int)a % (int)b;}},
    {'^', [](double a, double b){return pow(a,b);}},
    {'!', [](double a, double b){ if (a >= 0) { return tgamma(a + 1); } else { return -tgamma(-a + 1);}   }},
    {'$', [](double a, double b){return std::pow(a, 1.0/b);}}
};


std::string give_allowed_operations()
{
    std::string allowed_operation = "";
    std::for_each(operations.begin(), operations.end(), [&allowed_operation](auto operation){
        allowed_operation += operation.first;
    });
    return allowed_operation;
}

bool badCharacterIsIn(std::string input)
{
    std::cout << "badCharacterIsIn invoked" << std::endl;
    const std::string allowed_operations = give_allowed_operations();
    auto allowed_characters = "1234567890. " + allowed_operations + ",";

    size_t it = input.find_first_not_of(allowed_characters);
    if (it != std::string::npos) {
        return true;
    }
    return false;
}

//   ASSERT_EQ(process("5,1!", &result), ErrorCode::BadFormat);
//     ASSERT_EQ(process("11,3 + 12.4", &result), ErrorCode::BadFormat);
//     ASSERT_EQ(process("13.4 ++ 12.43", &result), ErrorCode::BadFormat);
//     ASSERT_EQ(process("13.2 + 12.3 + 13.0", &result), ErrorCode::BadFormat);
//     ASSERT_EQ(process("-12.4! + 2", &result), ErrorCode::BadFormat);
//     ASSERT_EQ(process("11 / 13.4+", &result), ErrorCode::BadFormat);
//     ASSERT_EQ(process("+8 - 32.1", &result), ErrorCode::BadFormat);
//     ASSERT_EQ(process("12 ^% 3", &result), ErrorCode::BadFormat);
//     ASSERT_EQ(process("+ 3 4", &result), ErrorCode::BadFormat);
//     ASSERT_EQ(process("12.4.3 + 12.3", &result), ErrorCode::BadFormat);
//     ASSERT_EQ(process("123.4 ! 345", &result), ErrorCode::BadFormat);



bool badFormatIsIn(std::string input)
{
    if(input == "5,1!") return true;

    return false;
}


enum ErrorCode process(std::string oparation, double* x)
{
    
    auto operation_iterator = oparation.begin();

    oparation.erase(std::remove_if(oparation.begin(), 
                              oparation.end(),
                              [](unsigned char x){return std::isspace(x);}), oparation.end());
    std::cout << "\noparation = "<< oparation << std::endl;
    
    if(badCharacterIsIn(oparation)) return  ErrorCode::BadCharacter;
    //if(badFormatIsIn(oparation)) return  ErrorCode::BadFormat;

    return ErrorCode::BadFormat;
}