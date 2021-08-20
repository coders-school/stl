#include "advancedCalculator.hpp"
#include <algorithm>
#include <functional>
#include <iostream>  // tests
#include <map>
#include <string>
#include <array>

const MapContainer operations{
    {'$', [](const ArgsArray& arr) { return arr[0] + arr[1]; }},
    {'^', [](const ArgsArray& arr) { return arr[0] + arr[1]; }},
    {'!', [](const ArgsArray& arr) { return arr[0] + arr[1]; }},
    {'%', [](const ArgsArray& arr) { return arr[0] + arr[1]; }},
    {'/', [](const ArgsArray& arr) { return arr[0] + arr[1]; }},
    {'*', [](const ArgsArray& arr) { return arr[0] + arr[1]; }},
    {'+', [](const ArgsArray& arr) { return arr[0] + arr[1]; }},
};

ErrorCode parseStr(std::string& input, ArgsArray& arr, std::string::iterator& opr) {
    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
    std::cout << "Operation: " << input << '\n';
    for (const auto& func : operations) {
        opr = std::find(input.begin(), input.end(), func.first);
        if (opr != input.end()) {
            break;
        }
    }
    if (opr == input.end()) {
        opr = std::find(input.begin(), input.end(), '-');
        if(opr == input.end()) {
            return ErrorCode::BadCharacter;
        }
        input.insert(opr, '+'); // zle
    }
    return ErrorCode::OK;
}

ErrorCode process(std::string input, double* out) {
    ArgsArray arr {0.0, 0.0};
    std::string::iterator it;
    parseStr(input, arr, it);
    if(it != input.end()) {
        std::cout << "Operator: " << *it << '\n';
        std::cout << "Arg 1: " << arr[0] << ", arg 2: " << arr[1] << '\n';
    }
    return ErrorCode::OK;
}
