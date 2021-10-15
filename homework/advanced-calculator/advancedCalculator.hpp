#pragma once
#include <iostream>
#include <map>
#include <functional>
#include <numeric>
#include <algorithm>
#include <cmath>

enum ErrorCode
{
	OK=0,
	BadCharacter,           //- znak inny niż liczba
	BadFormat,              //- zły format komendy np. + 5 4, powinno być 4 + 5
	DivideBy0,              //- dzielenie przez 0
	SqrtOfNegativeNumber,   //- pierwiastek z liczby ujemnej
	ModuleOfNonIntegerValue //- próba obliczenia % na liczbie niecałkowitej
};

ErrorCode process(const std::string& input, double* out);

std::string RemoveNotNeccessertyCharacters(const std::string& str);
std::vector<std::string> getNumbers(std::string_view str);
double Factorial(double n);

ErrorCode CheckBadFormat(std::string_view str);
ErrorCode CheckBadCharacter(std::string_view str);
ErrorCode CheckModuleNonIntegerValue(std::string_view v);
ErrorCode CheckDivideBy0(std::vector<std::string> v);
ErrorCode CheckFactorial(std::vector<std::string> v);
ErrorCode CheckNegativeNumber(std::string_view str);



