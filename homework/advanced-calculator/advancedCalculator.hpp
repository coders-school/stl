#pragma once

#include <functional>
#include <map>
#include <string>

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,                                
    SqrtOfNegativeNumber,                     
    ModuleOfNonIntegerValue                   
};

ErrorCode process(std::string input, double* out);
ErrorCode validationAllData(const std::string & userData);
ErrorCode generateErrorCode(const std::string::const_iterator & first, const std::string::const_iterator & betwen, const std::string::const_iterator & second, const std::string & userData);
ErrorCode factorialValidation(const std::string & userData);
bool isDivideBy0(const std::string& userData);
bool isSqrtOfNegativeNumber(const std::string& userData);
bool isModuleOfNonIntegerValue(const std::string& userData);
ErrorCode validFirstValue(const std::string::const_iterator& first, const std::string & userData);
ErrorCode validSign(const std::string::const_iterator& itBegin, const std::string::const_iterator& itEnd);
ErrorCode validSecondValue(const std::string::const_iterator& beginIt, const std::string::const_iterator& endIt, const std::string & userData);
void createCountingData(const std::string::const_iterator & first, const std::string::const_iterator & betwen, const std::string::const_iterator & second, const std::string & userData);
double countingResults(double first, char oper, double second);
