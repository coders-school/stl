#include <iostream>
#include "advancedCalculator.hpp"

void showDetails(){
    std::cout << "Type: " << '\n';
    std::cout << "+ add, \n'"
                 "- subtract, \n"
                 "* multiply, \n"
                 "/ divide, \n"
                 "% modulo, \n"
                 "! factorial, \n"
                 "^ power, \n"
                 "$ root, \n";
};

int main(){
    std::cout << "*** Advanced Calculator ***" << '\n';
    std::cout << "Type 'h' for more details." << '\n';
    while(true){
        std::string input;
        std::getline(std::cin, input);
        if(input == "q")
            break;
        else if(input == "h")
            showDetails();
        else {
            double result = 0;
            ErrorCode err = process(input, &result);
            std::cout << "\n" << result << "\n";
        }
    }

    return 0;
}