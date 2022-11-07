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
    std::cout << "badFormatIsIn invoked" << std::endl;
    bool result = false;

    const std::string allowed_operations = give_allowed_operations();
    auto has_at_least_one_coma = (std::count(input.begin(), input.end(), ',') > 0) ? true : false;
    
    auto has_doubled_plus_characters = [&input](){
        auto first_adjacent = std::adjacent_find(input.begin(), 
                                                    input.end()); 
        auto second_adjacent = first_adjacent + 1;
        if (*first_adjacent == '+' && *second_adjacent == '+') return true;
        return false; 
    };
            

    auto starts_with_plus = input[0] == '+';
    auto has_more_than_two_dots = (std::count_if(input.begin(), input.end(), [](char character){ return character == '.';})) > 2 ? true : false;
    auto has_factorial_character_not_last = [&input](){
            
        std::size_t pos_factorial = input.find('!');
        if(pos_factorial != std::string::npos)
        {
            std::cout << "pos_factorial = " << pos_factorial << " size " << input.size() << "\n";
            std::cout << "input last character = \"" << input.back() << "\"" << std::endl;
            if(input[pos_factorial] != input.back()) return true;

        }
        return false;
    };

    auto has_last_character_plus = (input.back() == '+') ? true : false;
    
    auto has_adjacent_power_and_modulo_characters = [&input](){
        auto contains = [](const auto& cont, std::string_view s)
        {
            // str.find() (or str.contains(), since C++23) can be used as well
            return std::search(cont.begin(), cont.end(), s.begin(), s.end()) != cont.end();
        };
        return contains(input, "^%");
    };

    if(has_at_least_one_coma){result = true; std::cout << "has_at_least_one_coma" << std::endl;} 
    if(has_doubled_plus_characters()){result = true;  std::cout << "has_doubled_plus_characters" << std::endl;} 
    if(starts_with_plus){result = true; std::cout << "starts_with_plus" << std::endl;} 
    if(has_more_than_two_dots){result = true; std::cout << "has_more_than_two_dots" << std::endl;}
    if(has_factorial_character_not_last()){result = true; std::cout << "has_factorial_character_not_last" << std::endl;} 
    if(has_last_character_plus){result = true; std::cout << "has_last_character_plus" << std::endl;}
    if(has_adjacent_power_and_modulo_characters()){result = true; std::cout << "has_adjacent_power_and_modulo_characters" << std::endl;} 

    std::cout << "badFormatIsIn result: " << std::boolalpha << result <<  std::endl;
    return result;
}

bool DivideBy0IsIn(std::string input)
{
    auto has_divide_character = (std::count_if(input.begin(), input.end(), [](char character){ return character == '/';})) > 0 ? true : false;
    if(has_divide_character)
    {
        auto has_zero_after_divide_character = [&input](){
            
                                                        std::size_t pos_divide = input.find('/');
                                                        std::size_t pos_zero = input.find('0');
                                                        std::cout << "pos_divide: " << pos_divide << std::endl;
                                                        std::cout << "pos_zero: " << pos_zero << std::endl;
                                                        if(pos_zero != std::string::npos)
                                                        {
                                                            std::cout << "if(pos_zero != std::string::npos): " << std::endl;
                                                            return ((pos_zero > pos_divide) or (input.back() == '0')) ? true : false;

                                                        }
                                                        std::cout << "result false: " << std::endl;
                                                        return false;
                                                        };

        return has_zero_after_divide_character();
    }
    return false;

}

enum ErrorCode process(std::string oparation, double* x)
{
    
    auto operation_iterator = oparation.begin();

    oparation.erase(std::remove_if(oparation.begin(), 
                              oparation.end(),
                              [](unsigned char x){return std::isspace(x);}), oparation.end());
    std::cout << "\noparation = \""<< oparation << "\"" << std::endl;
    
    if(badCharacterIsIn(oparation)) return  ErrorCode::BadCharacter;
    if(badFormatIsIn(oparation))    return  ErrorCode::BadFormat;
    if(DivideBy0IsIn(oparation))    return  ErrorCode::DivideBy0;

    return ErrorCode::OK;
}