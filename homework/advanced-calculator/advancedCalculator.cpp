#include "advancedCalculator.hpp"

#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>
#include <sstream>

ErrorCode process(std::string input, double* out)
{
    return ErrorCode::OK;
}

bool quitRequested(std::string line)
{
    std::transform(begin(line), end(line), begin(line), tolower);

    return line == "quit";
}

void printInstructions()
{
    std::cout << "-----Simple calculator-----\n"
              << "type 'quit' or enter a calculation to be performed\n";
}

FormatedInput formatInput(const std::string& line)
{
    //   * Dodawanie, mnożenie, dzielenie, odejmowanie (`+`,  `*` , `/` , `-`)
    // * Modulo (`%`)
    // * Obliczanie silni (`!`)
    // * Podnoszenie liczby do potęgi (`^`)
    // * Obliczanie pierwiastka (`$`)
    static constexpr std::array<char, 8> allowed_operations { '+', '*' };
    std::istringstream(line);
    std::string lhs_operand;
    std::string rhs_operand;
    std::string operation;
    line >> lhs_operand >> operation >> rhs_operand;
}