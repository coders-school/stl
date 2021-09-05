#include <iostream>
#include <string>
#include "advancedCalculator.hpp"

int main() {

    std::cout << "zrn: ";
    double a;
    std::string str;
    std::getline(std::cin, str);
    // std::cin >> str;
    std::cout << "str =  " << str << '\n';
                // size_t pos;
                // size_t* posPtr = &pos;
                // double value = std::stod(str, posPtr);


    process(str, &a);


    std::cout << "result " << a << '\n';
    // std::cout << " double: "  << value << "  % :" << static_cast<int>(value) % 2<< '\n';
    // std::cout << " double: "  << value << "  pos :" << pos << '\n';


    
    return 0;
}