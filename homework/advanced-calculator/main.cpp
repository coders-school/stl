#include<iostream>
#include "advancedCalculator.hpp"

int main(int argc, char const *argv[])
{
    std::map<char, std::function<double(double, double)>> MathOperations{
    {'+', [](double a, double b) { return a + b; }},
    {'-', [](double a, double b) { return a - b; }},
    {'*', [](double a, double b) { return a * b; }},
    {'/', [](double a, double b) { return a / b; }},
    {'%', [](double a, double b) { return (int)a % (int)b; }},
    {'!', [](double a, double b) { return (sqrt(2 * PI * a)) * pow(a / E, a); }},
    {'^', [](double a, double b) { return pow(a, b); }},
    {'$', [](double a, double b) { return pow(a, 1 / double(b)); }}};

    std::for_each(MathOperations.begin(), MathOperations.end(), [](auto a){ std::cout << a.first << " | " << a.second(6.7, 6.7) << std::endl;});
    double a;
    double b;
    char operation;
    ErrorCode result = isValidInput("12 ^% 3",a ,b , operation);
    ErrorCode result2 = isValidInput("+ 3 4",a ,b , operation);
    ErrorCode result3 = isValidInput("12.4.3 + 12.3",a ,b , operation);
    ErrorCode result4 = isValidInput("123.4 ! 345",a ,b , operation);
    
    ErrorCode result11 = isValidInput("123 #- 123",a ,b , operation);
    ErrorCode result12 = isValidInput("123 @- 123",a ,b , operation);
    ErrorCode result13 = isValidInput("123 &- 123",a ,b , operation);
    ErrorCode result14 = isValidInput("123 ? 123",a ,b , operation);
    ErrorCode result15 = isValidInput("123 \\ 123",a ,b , operation);
    ErrorCode result16 = isValidInput("-123 [ -123",a ,b , operation);
    ErrorCode result17 = isValidInput("-123 ] 123",a ,b , operation);
    ErrorCode result18 = isValidInput("-98 + 12.3 =",a ,b , operation);
    ErrorCode result19 = isValidInput("123 -#- 4",a ,b , operation);
    ErrorCode result20 = isValidInput("qwert + 123",a ,b , operation);
    ErrorCode result21 = isValidInput("123,4 ; 345",a ,b , operation);


    return 0;
}
