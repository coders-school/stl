#pragma once
#include <functional>
#include <map>
#include <string>

enum class ErrorCode {
    OK,
    BadCharacter,               //Jeżeli użytkownik poda znak inny niż liczbę.
    BadFormat,                  //Jeżeli użytkownik poda zły format komendy np. + 5 4, powinno być 4 + 5.
    DivideBy0,                  //dzielenie przez 0.
    SqrtOfNegativeNumber,       //pierwiastek z liczby ujemnej.
    ModuleOfNonIntegerValue     //Póba obliczenia % na liczbie niecałkowitej. 
};

extern const std::map<const char, std::function<double(double, double)>>operations;

ErrorCode process(std::string input, double* out);

bool isAllowedOperation(char operation);
bool isBadCharacter(std::string input);
