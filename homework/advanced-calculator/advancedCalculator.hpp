#pragma once
#include <string>

enum class ErrorCode 
            { OK,BadCharacter,BadFormat,DivideBy0,SqrtOfNegativeNumber,ModuleOfNonIntegerValue};

ErrorCode process(std::string input, double* out);

void removeWhiteSpaces(std::string &input);
bool checkIfCharIsInCommands(const char com);
std::pair<double,double> splitStringIntoTwoNumbers(std::string& input);