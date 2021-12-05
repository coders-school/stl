#pragma once
#include <string>

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

bool checkOperation(const char & );
auto returnOperation(std::string & );
bool checkCharacter(const std::string &);
bool isNumber(const std::string & );
bool checkFormat(const char & , const std::string & , const std::string & );
bool isInteger(const std::string & );
double doMath (const char & ,const double & ,const double & );
ErrorCode process(std::string , double * );