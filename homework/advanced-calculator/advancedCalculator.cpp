#include "advancedCalculator.hpp"

std::map<char, std::function<double(double, double)>> mapOfOperations = {
                                                            { '+', [](double a, double b){return a + b;} },
                                                            { '-', [](double a, double b){return a - b;} },
                                                            { '*', [](double a, double b){return a * b;} },   // multiplication
                                                            { '/', [](double a, double b){return a / b;} },   // division
                                                            { '%', [](int a, int b){return a % b;} },       // modulo
                                                            { '!', [](double a, double b){return std::tgamma((double) a + 1.0L);} },       // factorial
                                                            { '^', [](double a, double b){return pow(a, b);} }, // power
                                                            { '$', [](double a, double b){return pow(a, 1.0 / b);} }, // root
                                                        };

std::function<int(int)> foo = [](int a){ return a; };

bool isNumber(std::string s) {
    // checks if first character is a digit or minus sign '-'
    if(!(std::isdigit(s[0]) || s[0] == '-')) {
        return false;    
    }
    auto start_it = begin(s);

    if(s[0] == '-') {
        start_it = begin(s) + 1;
    }
    if(std::count(begin(s), end(s),'.') > 1) {
        return false;
    }
    // return iterator to first character which is not a digit or '.'
    auto it = std::find_if(start_it, end(s), [](char c){  if(c == '\0') return true;  
                                    bool condition = !std::isdigit(c) && c !='.'; 
                                    return condition; 
                                                        });    
    if(it != end(s)) {
        return false;
    }

    return true;
}

bool isValidCharacter(char c, const std::set<char>& set) {
    if(set.count(c) > 0) {
        return true;
    }      
    return false;
}

bool isInteger(double val) {
    return std::floor(val) == val;
}

ErrorCode process(std::string input, double* out) {
    std::set<char> validChar = {'+', '-', '*', '/', '%', '!', '^', '$', '.', ','};
    std::set<char> operators = {'+', '-', '*', '/', '%', '!', '^', '$'};
    char typeOfOperation;
    std::string firstOperand, secondOperand;
    double firstNumber, secondNumber;
    std::vector<std::string> arguments;
    std::string inputNoSpace;
    std::string temp;

    // deleting spaces in input string
    std::copy_if(begin(input), end(input), std::back_inserter(inputNoSpace), [](char c){ 
                                                    if(c == ' ') {
                                                        return false; 
                                                    }
                                                    else {
                                                        return true;    
                                                    }
                                                });


    // checks if string contains invalid character, if true returns iterator to this character
    auto it = std::find_if_not(begin(inputNoSpace), end(inputNoSpace), [validChar](char c){
                                                if(std::isdigit(c) || isValidCharacter(c, validChar)) {
                                                    return true;    
                                                }
                                                return false;
                                                            });
    if(it != end(inputNoSpace)) {
        std::cout << "Invalid character: " << *it << '\n';
        return ErrorCode::BadCharacter;
    }   
    // if first character of string is not digit or '-' return  BadFormat
    if(!(isdigit(inputNoSpace[0]) || inputNoSpace[0]== '-')) {
        return ErrorCode::BadFormat;
    }                                

    // find iterator pointing to type of operation character
    it = std::find_first_of(begin(inputNoSpace) + 1, end(inputNoSpace), 
                                 begin(operators), end(operators));
    typeOfOperation = *it;
    
    std::copy_n(begin(inputNoSpace), it - begin(inputNoSpace), std::back_inserter(firstOperand));
    // checks if a second operand exists
    if(it + 1 != end(inputNoSpace)) {
        std::copy_n(it + 1, end(inputNoSpace) - it - 1, std::back_inserter(secondOperand));
    }

    // For debugging
    // std::cout << "type of operation is: " << typeOfOperation << '\n';
    // std::cout << firstOperand << ' ' << typeOfOperation << ' ' << secondOperand << '\n';
    // std::cout << firstOperand << " is a number: " << std::boolalpha << isNumber(firstOperand) << '\n';
    // std::cout << secondOperand << " is a number: " << std::boolalpha << isNumber(secondOperand) << '\n';

    // if firstOperand or secondOperand is not a number then return BadCharacter
    if(!isNumber(firstOperand)) {
        return ErrorCode::BadFormat;
    }

    if(typeOfOperation == '!') {
        if(secondOperand != "") {
            return ErrorCode::BadFormat;
        }
        firstNumber = std::stod(firstOperand);
        secondNumber = 0.0;
        
        if(firstNumber < 0) {
            *out = -mapOfOperations[typeOfOperation](-firstNumber, secondNumber);
            return ErrorCode::OK; 
        }
        *out = mapOfOperations[typeOfOperation](firstNumber, secondNumber);
        return ErrorCode::OK;   
    }
    
    // if firstOperand is not a number then return BadCharacter
    if(!isNumber(secondOperand)) {
        return ErrorCode::BadFormat;
    }

    firstNumber = std::stod(firstOperand);
    secondNumber = std::stod(secondOperand);

    if(typeOfOperation == '/' && secondNumber == 0.0) {
        return ErrorCode::DivideBy0;   
    }
    // checks if first or second number are not integers
    if(typeOfOperation == '%') {
        if(!isInteger(firstNumber) || !isInteger(secondNumber))
        return ErrorCode::ModuleOfNonIntegerValue;   
    }
    
    // checks if first or second number are not integers
    if(typeOfOperation == '$') {
        if(firstNumber < 0) {
            return ErrorCode::SqrtOfNegativeNumber;  
        } 
    }
    // // assigning the result of calculation to out pointer
    *out = mapOfOperations[typeOfOperation](firstNumber, secondNumber);
    return ErrorCode::OK;
}