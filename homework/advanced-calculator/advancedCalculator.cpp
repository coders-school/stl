#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <vector>

#include "advancedCalculator.hpp"

double addition(const double a, const double b){
    return a + b;
}

double substract(const double a, const double b){
    return a - b;
}

double multiply(const double a, const double b){
    return a * b;
}

double divide(const double a, const double b){
    return a / b;
}

int modulo(const int a, const int b){
    return a % b;
}

long double factorial(double a, const double){
    if(a>=0)
        return std::tgamma(a)*a;
    
    a*=-1;
    return -std::tgamma(a)*a;
}

int power(const double a, const double b){
    return std::pow(a,b);
}

double sqrtRoot(const double a, const double b){
    return std::pow(a,1.0 / b);
}

std::vector<char> availableCharacters{'+','-','*','/','%','!','^','$'};
std::map<char,std::function<double(const double, const double)>> commands{
    {'+' , addition},
    {'-' , substract},
    {'*' , multiply},
    {'/' , divide},
    {'%' , modulo},
    {'!' , factorial},
    {'^' , power},
    {'$' , sqrtRoot}
};

//Function shall remove all white spaces in given string 
void removeWhiteSpaces(std::string &input){
    input.erase(std::remove_if(input.begin(),input.end(),
                                [](char zn){ return zn == ' ';}),input.end());
}

bool checkIfSqrtOfNegativeNumber(std::string input,std::tuple<double,double,char> splitted){

    return std::get<2>(splitted) == '$' && std::get<0>(splitted) <=0;
}

bool checkIfModuleOfNonIntegerValue(std::string input,std::tuple<double,double,char> splitted){

    return std::get<2>(splitted) == '%' && (checkIfDouble(std::get<0>(splitted)) || checkIfDouble(std::get<1>(splitted)));
}

bool checkIfDivideBy0(std::string input,std::tuple<double,double,char> splitted){
    
     return std::get<2>(splitted) == '/' && std::get<1>(splitted) == 0;
}

bool checkIfBadCharacter(std::string input){
    std::vector<char> BadCharacters{'\\','@','#','&','(',')','[',']','?',';',':',',','=','<','>'};

    auto Command = std::find_first_of(input.begin(),input.end(),
                                      BadCharacters.begin(),BadCharacters.end());
    
    auto letter = std::find_if(input.begin(),input.end(),[](const char zn){return (zn >='A' && zn<='Z') || (zn>='a' && zn <='z'); });

    return Command!=input.end() || letter!=input.end();
}

bool checkIfBadFormat(std::string input){
    std::vector<char> UniqueCharacters{'+','*','/','%','!','^','$'};
    int counter = 0;
    removeWhiteSpaces(input);

    std::for_each(UniqueCharacters.begin(),UniqueCharacters.end(),[&counter,input](char UniqueCharactersCHAR){
        counter+=std::count(input.begin(),input.end(),UniqueCharactersCHAR);      
    });
    if(counter>=2)
        return true;

    if(std::count(input.begin(),input.end(),'.') >= 3)
        return true;
    
    auto FirstPostion = std::find(UniqueCharacters.begin(),UniqueCharacters.end(),input[0]);
    auto lastPostion = std::find(UniqueCharacters.begin(),UniqueCharacters.end(),input.back());
    if(FirstPostion != UniqueCharacters.end() || (lastPostion != UniqueCharacters.end() && *lastPostion != '!') )
        return true;

    auto findChar = std::find(input.begin(),input.end(),'!');

    if(findChar!= input.end() && input.back()!='!')
        return true;
   
    return false;
}

bool checkIfDouble(const double a){

    if(static_cast<int>(a * 10000) % 10000 == 0)
        return false;
    return true;
}

ErrorCode process(std::string input, double* out){
    

    if(checkIfBadCharacter(input) == true){
        return ErrorCode::BadCharacter;
    }
    if(checkIfBadFormat(input) == true){
        return ErrorCode::BadFormat;
    }

    std::tuple<double,double,char> splitted = splitStringIntoTwoNumbers(input);

    if(checkIfSqrtOfNegativeNumber(input,splitted) == true){
        return ErrorCode::SqrtOfNegativeNumber;
    }
    if(checkIfModuleOfNonIntegerValue(input,splitted) == true){
        return ErrorCode::ModuleOfNonIntegerValue;
    }
    if(checkIfDivideBy0(input,splitted) == true){
        return ErrorCode::DivideBy0;
    }
    
    if (auto search = commands.find(std::get<2>(splitted)); search != commands.end())
        *out = search->second(std::get<0>(splitted),std::get<1>(splitted));
    else
        std::cout << "Not found\n";

    return ErrorCode::OK;
}

std::tuple<double,double,char> splitStringIntoTwoNumbers(std::string& input){

    std::string lhs, rhs;
    double lhss=0 ,rhss=0;
    removeWhiteSpaces(input);
   
        if(input[0]=='-')
        {
            auto Command = std::find_first_of(input.begin()+1,input.end(),
                                      availableCharacters.begin(),availableCharacters.end());
            std::for_each(input.begin()+1,Command,[&](char zn){ lhs.push_back(zn);});
            std::for_each(Command+1,input.end(),[&](char zn){ rhs.push_back(zn);});
           
            lhss = std::stod(lhs);
            if(rhs != ""){ 
                 rhss = std::stod(rhs);
            }

             return {-lhss,rhss,*Command};
        }else{
            auto Command = std::find_first_of(input.begin(),input.end(),
                                      availableCharacters.begin(),availableCharacters.end());
            std::for_each(input.begin(),Command,[&](char zn){ lhs.push_back(zn);});
            std::for_each(Command+1,input.end(),[&](char zn){ rhs.push_back(zn);});


            lhss = std::stod(lhs);
             if(rhs != ""){
                 rhss = std::stod(rhs);
            }
            return {lhss,rhss,*Command};
        }

}
