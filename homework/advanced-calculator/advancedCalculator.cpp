#include "advancedCalculator.hpp"


ErrorCode process(std::string input, double* result)
{
    if(BadCharacter(input)){
        return ErrorCode::BadCharacter;
    }
    if(BadFormat(input)){
        return ErrorCode::BadFormat;
    } 

    try{
        double a = parseFirst(input);
        int position = operatorPosition(input);
        double b = 0;
        if(input[position] != '!'){
            b = parseSecond(input, position);
        }
        return operations(input[position], a, b, result);
    }
    catch(const std::exception&){
        return ErrorCode::BadFormat;
    }
}


ErrorCode operations(char ch, double a, double b, double* result)
{
    std::map<char, std::function<ErrorCode(double, double, double*)>>actions{
        {'+',[](double a, double b, double* result){*result = a + b; return ErrorCode::OK; }},
        {'-',[](double a, double b, double* result){*result = a - b; return ErrorCode::OK; }},
        {'*',[](double a, double b, double* result){*result = a * b; return ErrorCode::OK; }},
        {'/', divide},
        {'^',[](double a, double b, double* result){*result = std::pow(a,b); return ErrorCode::OK; }},
        {'!', factorial},
        {'$', nth_root},
        {'%',modulo}, 
    };
    auto iter = actions.find(ch);
    if(iter != actions.end()){
        return iter->second(a, b, result);
    }
    return ErrorCode::BadCharacter;
}


ErrorCode divide(double a, double b, double* result)
{
    if(b == 0) {
        return ErrorCode::DivideBy0;
    }
    *result = a/b;
    return ErrorCode::OK;
}


ErrorCode factorial(double a, double b, double* result)
{
    if(a < 0){
        a *= -1;
        *result = std::tgamma(a+1) *-1;
    }
    else{
        *result = std::tgamma(a + 1);
    }
    return ErrorCode::OK;
}


ErrorCode nth_root(double a, double b, double* result)
{
    if(a < 0 || b == 0){
        return ErrorCode::SqrtOfNegativeNumber;
    }    
    *result = std::pow(a, (1 / b));
    return ErrorCode::OK;    
}


ErrorCode modulo(double a, double b, double* result)
{
    if(std::floor(b) != b || std::floor(a) != a) {
        return ErrorCode::ModuleOfNonIntegerValue;
    }
    *result = static_cast<int>(a) % static_cast<int>(b);
    return ErrorCode::OK;
}


bool BadCharacter(const std::string& input)
{
    std::string operations = "0123456789+-*/!^$%,. ";
    auto iter = input.find_first_not_of(operations);
    if(iter != std::string::npos){
        return true;
    }
    return false;
}


bool BadFormat(const std::string& input)
{
    if(comma(input)){
        return true;
    }
    if(factorialBadFormat(input)){
        return true;
    }
    if(dots(input)) {
        return true;
    }
    if(tooLong(input)){
        return true;
    }
    if(!isdigit(input[0]) && input[0] != '-') {
        return true;
    }
    return false;
}


double parseFirst(const std::string& input)
{
    return std::stold(input);
}


int operatorPosition(const std::string& input)
{
    std::string operators = "+-*/!^%$";
    int position = std::string(input.begin() +1, input.end()).find_first_of(operators);
    return position + 1;
}


double parseSecond(const std::string& input, int position)
{
    return std::stold(std::string(input.begin() + position+1, input.end()));
}


bool comma(const std::string& input)
{
    auto it = std::find(input.begin(), input.end(), ',');
    if(it == input.end()){
        return false;
    }
    return true;
}


bool dots(const std::string& input)
{
    int dots = 0;
    for(const auto& it : input){
        if(it == '.'){
            dots++;
        }
        if(!isdigit(it) && it != '.'){
            dots = 0;
        }
        if(dots >= 2){
            return true;
        }
    }
    return false;
}



bool factorialBadFormat(const std::string& input)
{
    auto it = std::find(input.begin(), input.end(), '!');
    if(it == input.end()){
        return false;
    }
    auto iter = std::find_if(it +1, input.end(),
            [](char z) {return z != ' ';});
    if(iter == input.end()){
        return false;
    }
    return true;
}


bool tooLong(const std::string& input)
{
    auto i = operatorPosition(input);
    auto it = std::find_if(input.begin()+i+1, input.end(),
                [](char z) {return std::isdigit(z); }); 

    auto iter = std::find_if_not(it+1, input.end(),
                [](char z) {return std::isdigit(z) || z == '.'; });

    
    while (iter != input.end())
    {
        if(*iter != ' ')
            return true;
        iter++;
    }
    
    
    return false;
}
