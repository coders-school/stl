#include <iostream>
#include "ExpressionParser.hpp"
#include "advancedCalculator.hpp"

int main()
{
double d;
//ExpressionParser Expression("11,3 + 12.4");
process("5,1!",&d);

std::cout << d << "\n";

};