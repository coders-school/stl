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

    std::cout << "\noparation = "<< oparation << std::endl;
    std::stringstream ss;
    ss.str(oparation);
    double lhs;
    std::string oper;
    double rhs;
    std::string anything_more;
    ss >> lhs >> oper >> rhs >> anything_more;
    std::cout << "----------------\n";
    std::cout << "lhs = " << lhs << std::endl;
    std::cout << "oper = " << oper << std::endl;
    std::cout << "rhs = " << rhs << std::endl;
    std::cout << "anything_more = " << anything_more << std::endl;
    auto disallowed_operator = std::none_of(allowed.begin(), allowed.end(), [&oper](auto allowed_operator){ return oper == std::to_string(allowed_operator);});
    if(disallowed_operator)
    {
        std::cout << "disallowed_operator\n";
        auto has_comma = oper.find(",")!=std::string::npos;
        auto has_semicolon = oper.find(";")!=std::string::npos;
        auto has_allowed_operator = std::any_of(allowed.begin(), allowed.end(), [&oper](auto allowed_operator){ return oper.find(allowed_operator)!=std::string::npos; });
        auto has_digit = std::any_of(oper.begin(), oper.end(), [](auto x ){ return std::isdigit(x);});
        auto whole_operation_has_semicolon = oparation.find(";")!=std::string::npos;
        auto anything_more_has_correct_operator = std::any_of(allowed.begin(), allowed.end(), [&anything_more](auto allowed_operator){ return anything_more.find(allowed_operator)!=std::string::npos; });
        if(anything_more_has_correct_operator)
        {
            std::cout << "anything_more_has_correct_operator\n";
            return ErrorCode::BadFormat;
        }
        if(has_semicolon)
        {
            std::cout << "has_semicolon\n";
            std::cout << "ErrorCode::BadCharacter\n";
            return ErrorCode::BadCharacter;
        }
        if(has_comma and has_digit and has_allowed_operator)
        {
            std::cout << "has_comma\n";
            std::cout << "has_digit\n";
            std::cout << "has_allowed_operator\n";
            return ErrorCode::BadFormat;
        }
        if(has_allowed_operator)
        {
            std::cout << "has_allowed_operator\n";
           
            auto has_more_allowed_operators_than_one = [&oper](){ 
                    auto it = std::adjacent_find (oper.begin(), oper.end());
                    return it!=oper.end();
            };

            if(has_more_allowed_operators_than_one())
            {
                std::cout << "has_more_allowed_operators_than_one\n";
                return ErrorCode::BadFormat;
            }
            
        }
        if(has_comma and has_digit and rhs == 0.0)
        {
            std::cout << "has_comma\n";
            std::cout << "has_digit\n";
            std::cout << "has rhs == 0.0\n";
            if(whole_operation_has_semicolon)
            {
                std::cout << "whole_operation_has_semicolon\n";
                return ErrorCode::BadCharacter;
            }
            return ErrorCode::BadFormat;
        }
        if(has_comma)
        {
            std::cout << "has_comma\n";
            std::cout << "has_digit\n";
            return ErrorCode::BadFormat;
        }
        std::cout << "ErrorCode::BadCharacter\n";
        return ErrorCode::BadCharacter;
    }
    if(not anything_more.empty())
    {
        std::cout << "not anything_more.empty\n";
        std::cout << "ErrorCode::BadCharacter\n";
        return ErrorCode::BadCharacter;
    }
    if(rhs == 0.0)
    {
        std::cout << "rhs == 0.0\n";
        std::cout << "ErrorCode::BadCharacter\n";
        return ErrorCode::BadCharacter;
    }



    return ErrorCode::BadFormat;
}