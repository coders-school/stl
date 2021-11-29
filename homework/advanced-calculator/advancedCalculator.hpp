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

bool checkInputFormat(const std::string & ,const char & ,const std::string &, const std::string &);
bool checkOperation(const std::string & );
auto returnOperation(std::string & );
bool isNumber(const std::string & );
bool isInteger(const std::string & );
double doMath (const char & ,const auto & ,const auto & );
ErrorCode process(std::string , double * );




//1. pierwszy znak operacji 