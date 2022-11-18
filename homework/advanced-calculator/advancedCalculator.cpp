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

int modulo(const double a, const double b){
    return static_cast<int>(a) % static_cast<int>(b);
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

//Function shall return true if given char is in commands
bool checkIfCharIsInCommands(const char com){
    return commands.find(com) != commands.end();
}

ErrorCode process(std::string input, double* out){
    std::tuple<double,double,char> splitted = splitStringIntoTwoNumbers(input);

    if (auto search = commands.find(std::get<2>(splitted)); search != commands.end())
        *out = search->second(std::get<0>(splitted),std::get<1>(splitted));
    else
        std::cout << "Not found\n";


   // std::cout<<*out<<"\n";
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
            //std::cout<<"lhs: "<<-lhss<<"     "<<"rhs: "<<rhss<<"\n";

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
            //std::cout<<"lhs: "<<lhss<<"     "<<"rhs: "<<rhss<<"\n";
            return {lhss,rhss,*Command};
        }

}
