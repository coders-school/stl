#include <iostream>
#include <map>
#include <functional>
#include <regex>

#include "advancedCalculator.hpp"

int main()
{
	std::string input = "5,1!";

	double out = 0;
	std::cout << "error : " << process(input, &out);
	std::cout << " out : " << out << '\n';

	return 0;
}