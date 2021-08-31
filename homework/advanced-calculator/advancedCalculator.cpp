#include "advancedCalculator.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <functional>
#include <map>
#include <vector>

double result = 0;
std::string allowedChars = { "+-/*%!^$" };

ErrorCode process(std::string input, double* out) {
    if (!validateCharacters(input)) {
        return ErrorCode::BadCharacter;
    }

}

bool validateCharacters (std::string &input) {
    input.erase(std::remove_if(input.begin(), input.end(), [](char c){ return isspace(c); }), input.end());
    return std::any_of(input.begin(), input.end(), [&](char c){ return isdigit(c) && !std::any_of(allowedChars.begin(),
                                                                                                   allowedChars.end(),
                                                                                                   [&](char command){ return c != command;  }) ; });
}


bool validateFormat (std::string &input) {

}

char findCommand (std::string &input) {
    char command;
    

    return command;
}

