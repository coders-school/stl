#include "advancedCalculator.hpp"
#include <string>
#include <iostream>

int main(){
    double out;
    std::string formula;

    while(true){
        std::getline(std::cin >> std::ws, formula);
        auto message = process(formula, &out);

        if(message == ErrorCode::OK)
            std::cout << " = " << out << '\n';
        else
            std::cout << static_cast<int>(message);
    }
    return 0;
}