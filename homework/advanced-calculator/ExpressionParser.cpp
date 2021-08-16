#include "ExpressionParser.hpp"
#include <iostream>

bool ExpressionParser::slice(std::string input)
{
    if (input.empty()) {return false;};
input.erase(std::remove(input.begin(),input.end(),' '),input.end());

auto opchar = std::find_if(std::next(input.begin()),input.end(),[](auto& c) {
if (c=='+' || c=='-' || c=='*' || c=='/' || c=='%' || c=='!' || c=='^' || c=='$' ) {return true;};
return false;
});

if (opchar == input.end()) {return false;};

Operand1_=input.substr(0,std::distance(input.begin(),opchar));
Operation_=*opchar;
Operand2_=input.substr(std::distance(input.begin(),opchar)+1,input.size());

std::cout << Operand1_ << Operation_ << Operand2_ << std::endl;
return true;
}


