#include "advancedCalculator.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <functional>
#include <map>
#include <vector>

void getUserInput () {
    std::string str;
    std::cin >> str;
    std::cout << str;
}

ErrorCode process(std::string input, double* out) {
    
}


// bool checkUserInput (std::string &input) {
//     std::vector<char> allowedChars = { '+', '-', '/', '*', '%', '!', '^', '$' };
//     return std::any_of(input.begin(), input.end(), [](char c){ return !isalnum(c); });
// }

// bool isPlayerChoiceValid(std::string &playerAnswer)
// {
//     if(std::cin.fail() || !checkUserInput(playerAnswer))
//     {
//         std::cin.clear();
//         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//         return false;
//     }
//     return true;
// }

