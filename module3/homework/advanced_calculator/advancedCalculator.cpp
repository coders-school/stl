#include "advancedCalculator.hpp"
#include <regex>
#include <iostream>

ErrorCode process(std::string input, double* out) {
    std::cout << input << '\n';
    std::smatch matches;

    std::regex operationPattern(R"((\w+|[-]?\d+.\d+|[-]?\d+)\s?([+*/\-%!^$])\s?(\w+|[-]?\d+.\d+|[-]?\d+))");
    std::regex factorialPattern(R"((\d+)\s?(\!))");

    if(std::regex_search(input, matches, operationPattern)){
        std::cout<<matches[0] << '\t' << matches[1] << '\t' << matches[2] << '\t' <<matches[3] <<'\n';
    }else if(std::regex_search(input, matches, factorialPattern)){
        std::cout<<matches[0] << '\t' << matches[1] << '\t' << matches[2] <<'\n';
    }else{
        std::cout<< "not found\n";
    }
    return ErrorCode::Ok;
}
