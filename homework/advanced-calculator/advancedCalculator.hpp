#pragma once
#include <string>

enum class ErrorCode 
            { OK,BadCharacter,BadFormat,DivideBy0,SqrtOfNegativeNumber,ModuleOfNonIntegerValue};

ErrorCode process(std::string input, double* out);

void removeWhiteSpaces(std::string &input);
bool checkIfCharIsInCommands(const char com);
bool checkIfSqrtOfNegativeNumber(std::string input,std::tuple<double,double,char> splitted);
bool checkIfDouble(const double a);
bool checkIfModuleOfNonIntegerValue(std::string input,std::tuple<double,double,char> splitted);
bool checkIfDivideBy0(std::string input,std::tuple<double,double,char> splitted);
bool checkIfBadCharacter(std::string input);
std::tuple<double,double,char> splitStringIntoTwoNumbers(std::string& input);