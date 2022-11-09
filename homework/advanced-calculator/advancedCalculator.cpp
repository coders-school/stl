#include "advancedCalculator.hpp"
#include <map>
#include <functional>
#include <cmath>

#include <iostream>
#include <sstream>
#include <algorithm>
#include <charconv>
#include <iomanip>

#include <tuple>

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


bool is_factorial(const std::string& operation, double& number)
{
    std::cout << "is_factorial = \""<< operation << "\"" << std::endl;
    auto calculate_factorial = [](auto number){ return operations['!'](number, number);};
    auto give_number_from_substr = [](auto operation){ return std::stod(operation.substr(0, *operation.rbegin()));};
    
    if(*operation.rbegin() == '!')
    {
        std::cout << "is_factorial = \""<< operation << "\"" << std::endl;
        auto converted_number  = give_number_from_substr(operation);
        number = calculate_factorial(converted_number);
        std::cout << "number = \""<< number << "\"" << std::endl;
        return true;
    }
    return false;
}


using lhs_t = double;
using operation_t = char;
using rhs_t = double;


//  std::tuple<lhs_t, operation_t, rhs_t>
std::tuple<lhs_t, operation_t, rhs_t>  give_elements_for_binary_operations(std::string& input)
{
    std::cout << "give_elements_for_binary_operations" << std::endl;
    std::cout << "\ninput: " << input << std::endl;
    //for each operation character find  any of except + and -
    for(auto input_character : input)
    {
        auto allowed = give_allowed_operations();
        if(std::any_of(allowed.begin(), allowed.end(), [&](auto allowed_oper){
            return (allowed_oper == input_character)
            and input_character != '+' and input_character != '-';}))
        {
            std::cout << "if: " << input_character << std::endl;
            auto root_character_position = input.find(input_character);
            std::cout << "root_character_position: " << root_character_position << std::endl;
            auto give_lhs_and_rhs = [&input, &root_character_position](){
                std::string lhs_str = input.substr(0, root_character_position);
                std::string rhs_str = input.substr(root_character_position+1, *input.rbegin());
                
                
                auto give_number_from_substr = [](auto input){ return std::stod(input.substr(0, *input.rbegin()));};
                double lhs = give_number_from_substr(lhs_str);
                double rhs = give_number_from_substr(rhs_str);
                std::cout << "lhs: " << lhs << std::endl;
                std::cout << "rhs: " << rhs << std::endl;
                return std::make_tuple(lhs, rhs);
            };
            auto [lhs, rhs] = give_lhs_and_rhs();

            std::cout << "lhs: " << lhs << std::endl;
            std::cout << "input.at(root_character_position): " << input.at(root_character_position) << std::endl;
            std::cout << "rhs: " << rhs << std::endl;
            return std::make_tuple(lhs, input.at(root_character_position), rhs);
        }
        else
        {
            std::cout << "else: " << input_character << std::endl;
        }
    }
    // auto root_character_position =  input.find('%');

  
    

    return std::make_tuple(0, '+', 0);
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
    else
    {
        auto [lhs, operation_character, rhs] = give_elements_for_binary_operations(operation);
        std::cout << "\nmain\n" << std::endl;
        std::cout << "lhs: " << lhs << std::endl;
        std::cout << "operation_character: " << operation_character << std::endl;
        std::cout << "rhs: " << rhs << std::endl;
        *x = operations[operation_character](lhs, rhs);
    }


    return ErrorCode::OK;
}
