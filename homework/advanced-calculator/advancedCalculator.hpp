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
    std::string firstValue_;
    char operation_;
    std::string secondValue_;
};

Data divideInput(std::string& input);
bool isAllowedOperation(char operation);
bool isBadCharacter(const std::string& input);
bool isBadFormat(std::string& input, Data& data);
bool isBadNumber(std::string& input);
double stringToDouble(std::string input, size_t precision);
std::string doubleToString(double number);
size_t getPrecision(std::string input);
