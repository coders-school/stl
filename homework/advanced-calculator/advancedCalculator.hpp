#pragma once
#include <functional>
#include <map>
#include <string>

enum class ErrorCode {
    OK,
    BadCharacter,            //Jeżeli użytkownik poda znak inny niż liczbę.
    BadFormat,               //Jeżeli użytkownik poda zły format komendy np. + 5 4, powinno być 4 + 5.
    DivideBy0,               //dzielenie przez 0.
    SqrtOfNegativeNumber,    //pierwiastek z liczby ujemnej.
    ModuleOfNonIntegerValue  //Póba obliczenia % na liczbie niecałkowitej.
};

extern const std::map<const char, std::function<double(double, double)>> operations;

ErrorCode process(std::string input, double* out);

struct Data {
    double firstValue_;
    char operation_;
    double secondValue_;
};

bool isAllowedOperation(char operation);
bool isBadCharacter(const std::string& input);
bool isBadFormat(std::string& input);
// void breaksStringToMembers(std::string input);
Data parseString(std::string input);
double stringToDouble(std::string input);
std::string doubleToString(double number);
size_t getPrecision(std::string input);
