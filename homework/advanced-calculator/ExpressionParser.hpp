#pragma once
#include <string>
#include <algorithm>

class ExpressionParser
{
    private:
char Operation_;
std::string Operand1_;
std::string Operand2_;

bool parsingFlag_;

void setParsingFlag(bool state) {parsingFlag_=state;};

public:
bool slice(std::string input);
std::string getOperand1() const {return Operand1_;};
std::string getOperand2() const {return Operand2_;};
char getOperation() const {return Operation_;};
char getParsingFlag() const {return parsingFlag_;};


//c-tor
ExpressionParser(const std::string& input):parsingFlag_{false} {slice(input);};

};