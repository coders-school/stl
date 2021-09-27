#include "advancedCalculator.hpp"


std::vector<std::string> errorCodeVector = {
                                          "OK",
                                          "BadCharacter",
                                          "BadFormat",
                                          "DivideBy0",
                                          "SqrtOfNegativeNumber",
                                          "ModuleOfNonIntegerValue"
                                          };
                                          
int main() {
    double result;
    ErrorCode code = ErrorCode::OK;
    std::string input;

    std::cout << "Enter operands: ";
    std::getline(std::cin, input);
    std::cout << '\n';
    while(input != "Ex") {
        code = process(input, &result);
        std::cout << "Result = ";
        printf("%20.2f", result);
        std::cout << " error code: " << errorCodeVector[(int)code] << '\n';
        std::cout << "Enter operands: ";
        std::getline(std::cin, input);
        std::cout << '\n';    
    }

}