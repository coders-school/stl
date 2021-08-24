#pragma once

#include <functional>
#include <map>
#include <string>

enum class ErrorCode {
    OK,
    BadCharacter,                             // Jeżeli użytkownik poda znak inny niż liczbę.
    BadFormat,                                // Jeżeli użytkownik poda zły format komendy np. + 5 4, powinno być 4 + 5.
    DivideBy0,                                // dzielenie przez 0.
    SqrtOfNegativeNumber,                     // pierwiastek z liczby ujemnej.
    ModuleOfNonIntegerValue                   // Póba obliczenia % na liczbie niecałkowitej.
};

ErrorCode validationUserData(const std::string& userData);
bool isBadCharacter(const std::string& UserData);
bool isBadFormat(const std::string& UserData);
bool isDivideBy0(const std::string& UserData);
bool isSqrtOfNegativeNumber(const std::string& UserData);
bool isModuleOfNonIntegerValue(const std::string& UserData);
double getFirsValue(const std::string& UserData);
char getSign(const std::string& UserData);
double getSecondValue(const std::string& UserData);
double coutingResults(double firstValue, char operation, double secondValue);
ErrorCode process(std::string input, double* out);
extern std::map<const char, std::function<double(const double, const double)>> operations;
void operationsInit();