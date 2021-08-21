#pragma once
#include <functional>
#include <iostream>
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

ErrorCode process(std::string input, double* out);

std::function<ErrorCode(std::string, double*)> add;
std::function<ErrorCode(std::string, double*)> subtract;
std::function<ErrorCode(std::string, double*)> multiply;
std::function<ErrorCode(std::string, double*)> divide;
std::function<ErrorCode(std::string, double*)> modulo;
std::function<ErrorCode(std::string, double*)> power;
std::function<ErrorCode(std::string, double*)> root;
std::function<ErrorCode(std::string, double*)> factorial;

std::map<char, std::function<ErrorCode(std::string, double*)>> operations {{'+', add},
                                            {'-', subtract},
                                            {'*', multiply},
                                            {'/', divide},
                                            {'%', modulo},
                                            {'^', power},
                                            {'$', root},
                                            {'!', factorial}
};

