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
    return a*b;
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
    return std::pow(a, 1.0/b);
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

    std::cout << "\noparation = "<< oparation << std::endl;
    std::stringstream ss;
    ss.str(oparation);
    double lhs;
    char oper;
    double rhs;
    std::string anything_more;
    ss >> lhs >> oper >> rhs >> anything_more;
    std::cout << "----------------\n";
    std::cout << "lhs = " << lhs << std::endl;
    std::cout << "oper = " << oper << std::endl;
    std::cout << "rhs = " << rhs << std::endl;
    std::cout << "anything_more = " << anything_more << std::endl;
    auto disallowed_operator = std::none_of(allowed.begin(), allowed.end(), [&oper](auto allowed_operator){ return oper == allowed_operator;});
    if(disallowed_operator)
    {
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

    // std::cout << "\noparation = "<< oparation << std::endl;
    // std::stringstream ss;
    // ss.str(oparation);
    // if(double lhs; ss >> lhs)
    // {
    //     std::cout << "lhs = " << lhs << std::endl;
    //     //++operation_iterator;
    //     if(char operation_character; ss >> operation_character)
    //     {
    //         std::cout << "operation_character = " << operation_character << std::endl;
    //         //++operation_iterator;

                      

    //         try
    //         {
    //             //++operation_iterator;
    //             if(double rhs; ss >> rhs)
    //             {
    //                 std::cout << "\tBinary operations processing" << std::endl;
    //                 std::cout << "rhs = " << rhs << std::endl;
    //                 std::cout << "operation_iterator = " << *operation_iterator << std::endl;

    //                 *x = calculate_values(lhs, rhs);
    //                 return ErrorCode::OK;
    //             }
    //             else
    //             {
    //                 std::cout << "\tUnary operations processing" << std::endl;
    //                 std::cout << "rhs = " << rhs << std::endl;
    //                 if(rhs != 0.0)
    //                 {
    //                     rhs = lhs;
    //                     if(operation_character == '!')
    //                     {
    //                         *x = calculate_values(lhs, rhs);
    //                         return ErrorCode::OK;
    //                     }
    //                 }
    //                 else
    //                 {
    //                     return ErrorCode::BadFormat;
    //                 }
                    

    //                 return ErrorCode::BadCharacter;
    //             }
    //         }
    //         catch(const std::bad_function_call& e){
    //             std::cerr << e.what() << '\n';
    //             return ErrorCode::BadFormat;
    //         }
    //         catch(const std::exception& e)
    //         {
    //             std::cerr << e.what() << '\n';
    //         }
            
            
    //     }
    //      else 
    //     {
    //         return ErrorCode::BadFormat;
    //     }
    // }
   


    return ErrorCode::BadFormat;
}