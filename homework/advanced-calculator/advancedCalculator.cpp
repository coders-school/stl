#include "advancedCalculator.hpp"
#include <map>
#include <functional>
#include <cmath>

#include <iostream>
#include <sstream>
#include <algorithm>
#include <charconv>
#include <iomanip>

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

bool badFormatIsIn(std::string input)
{
    std::cout << "badFormatIsIn invoked" << std::endl;
    bool bad_format = false;

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
            return std::search(cont.begin(), cont.end(), s.begin(), s.end()) != cont.end();
        };
        return contains(input, "^%");
    };

    if(has_at_least_one_coma)                                    {bad_format = true; std::cout << "has_at_least_one_coma" << std::endl;} 
    else if(has_doubled_plus_characters())                       {bad_format = true; std::cout << "has_doubled_plus_characters" << std::endl;} 
    else if(starts_with_plus)                                    {bad_format = true; std::cout << "starts_with_plus" << std::endl;} 
    else if(has_more_than_two_dots)                              {bad_format = true; std::cout << "has_more_than_two_dots" << std::endl;}
    else if(has_factorial_character_not_last())                  {bad_format = true; std::cout << "has_factorial_character_not_last" << std::endl;} 
    else if(has_last_character_plus)                             {bad_format = true; std::cout << "has_last_character_plus" << std::endl;}
    else if(has_adjacent_power_and_modulo_characters())          {bad_format = true; std::cout << "has_adjacent_power_and_modulo_characters" << std::endl;} 

    std::cout << "badFormatIsIn result: " << std::boolalpha << bad_format <<  std::endl;
    return bad_format;
}

bool DivideBy0IsIn(std::string input)
{
    auto has_divide_character = (std::count_if(input.begin(), input.end(), [](char character){ return character == '/';})) > 0 ? true : false;
    if(has_divide_character)
    {
        auto has_zero_as_last_character = input.back() == '0';
        if(has_zero_as_last_character)
        {
            std::cout << "has_zero_as_last_character" << std::endl;
            return true;
        }
    }
    return false;
}

bool ModuleOfNonIntegerValueIsIn(std::string input)
{
    auto module_character_position =  input.find('%');

    auto has_module_character =   module_character_position != std::string::npos;
    if(has_module_character)
    {
        std::cout << "has_module_character" << std::endl;
        std::cout << "module_character_position: " << module_character_position << std::endl;
        auto give_lhs_and_rhs = [&input, &module_character_position](){
            std::string lhs = input.substr(0, module_character_position);
            std::string rhs = input.substr(module_character_position+1, *input.rbegin());
            
            std::cout << "lhs: " << lhs << std::endl;
            std::cout << "rhs: " << rhs << std::endl;
            return std::make_tuple(lhs, rhs);
        };
        auto [lhs, rhs] = give_lhs_and_rhs();
        
        auto has_dot_character = [](const auto str){ return std::count(str.begin(), str.end(), '.') > 0;};
        std::cout << "lhs: " << lhs << std::endl;
        std::cout << "rhs: " << rhs << std::endl;
        return (has_dot_character(lhs) or has_dot_character(rhs));
    }

    return false;
}

bool hasRootOfNegativeNumber(std::string input)
{
    auto root_character_position =  input.find('$');

    auto has_root_character =   root_character_position != std::string::npos;
    if(has_root_character)
    {
        std::cout << "has_root_character" << std::endl;
        std::cout << "root_character_position: " << root_character_position << std::endl;
        auto give_lhs_and_rhs = [&input, &root_character_position](){
            std::string lhs = input.substr(0, root_character_position);
            std::string rhs = input.substr(root_character_position+1, *input.rbegin());
            
            std::cout << "lhs: " << lhs << std::endl;
            std::cout << "rhs: " << rhs << std::endl;
            return std::make_tuple(lhs, rhs);
        };
        auto [lhs, rhs] = give_lhs_and_rhs();
        
        auto has_minus_character = [](const auto str){ return std::count(str.begin(), str.end(), '-') > 0;};
        std::cout << "lhs: " << lhs << std::endl;
        std::cout << "rhs: " << rhs << std::endl;
        return (has_minus_character(lhs) or has_minus_character(rhs));
    }

    return false;
}

// TEST(advancedCalculatorTest, ShouldFactorial) {
//     double result = 0;

//     ASSERT_EQ(process("5!", &result), ErrorCode::OK);
//     EXPECT_TRUE(cmp(result, 120));
//     ASSERT_EQ(process("6.7!", &result), ErrorCode::OK);
//     EXPECT_TRUE(cmp(result, 2769.83));
//     ASSERT_EQ(process("3.435!", &result), ErrorCode::OK);
//     EXPECT_TRUE(cmp(result, 10.63327));
//     ASSERT_EQ(process("-13!", &result), ErrorCode::OK);
//     EXPECT_TRUE(cmp(result, -6227020800));
//     ASSERT_EQ(process("-12.4!", &result), ErrorCode::OK);
//     EXPECT_TRUE(cmp(result, -1324024774.02));

bool is_factorial(const std::string& operation, double& number)
{
    std::cout << "is_factorial = \""<< operation << "\"" << std::endl;
    if(*operation.rbegin() == '!')
    {
        std::cout << "is_factorial = \""<< operation << "\"" << std::endl;
        number  = std::stod(operation.substr(0, *operation.rbegin()));
        number = operations['!'](number, number);
        std::cout << "number = \""<< number << "\"" << std::endl;
        return true;
    }
    return false;
}


enum ErrorCode process(std::string operation, double* x)
{
    
    auto remove_whitespaces_from_input = [&operation](){operation.erase(std::remove_if(operation.begin(), 
                              operation.end(),
                              [](unsigned char x){return std::isspace(x);}), operation.end());
                              };

    remove_whitespaces_from_input();
    std::cout << "\noperation = \""<< operation << "\"" << std::endl;
    
    if(badCharacterIsIn(operation))                 return  ErrorCode::BadCharacter;
    if(badFormatIsIn(operation))                    return  ErrorCode::BadFormat;
    if(DivideBy0IsIn(operation))                    return  ErrorCode::DivideBy0;
    if(ModuleOfNonIntegerValueIsIn(operation))      return  ErrorCode::ModuleOfNonIntegerValue;
    if(hasRootOfNegativeNumber(operation))          return  ErrorCode::SqrtOfNegativeNumber;

    double lhs = 0;
    if(is_factorial(operation, lhs))
    {
        *x = lhs;
    }


    return ErrorCode::OK;
}