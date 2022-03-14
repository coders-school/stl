#pragma once

#include <algorithm>
#include <cctype>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using Operations = std::map<char,std::function<double(double,double)>>;

struct mathExpresion{
  double firstArg;
  double secondArg;
  char oper;
};

enum class ErrorCode{
  OK,
  BadCharacter, // - znak inny niż liczba
  BadFormat, // - zły format komendy np. + 5 4, powinno być 4 + 5
  DivideBy0, // - dzielenie przez 0
  SqrtOfNegativeNumber, // - pierwiastek z liczby ujemnej
  ModuleOfNonIntegerValue //- próba obliczenia % na liczbie niecałkowitej
};

ErrorCode process(std::string input, double* out);

//bad character test
bool badCharTest(const std::string &);

bool badFormatTest(const std::string &);

//deleting spaces
std::string parsingInput(std::string &);

mathExpresion extracting(const std::string &);
                
bool requestForQuit(std::string &);