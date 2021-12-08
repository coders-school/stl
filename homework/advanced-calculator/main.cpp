#include "advancedCalculator.hpp"
void printError(ErrorCode EC)
{
    if(ErrorCode::OK == EC) std::cout << "OK\n";
    if(ErrorCode::BadCharacter == EC) std::cout << "BadCharacter\n";
    if(ErrorCode::BadFormat == EC) std::cout << "BadFormat\n";
    if(ErrorCode::DivideBy0 == EC) std::cout << "DivideBy0\n";
    if(ErrorCode::SqrtOfNegativeNumber == EC) std::cout << "SqrtOfNegativeNumber\n";
    if(ErrorCode::ModuleOfNonIntegerValue == EC) std::cout << "ModuleOfNonIntegerValue\n";
}

int main()
{
    double valDouble;
    auto error = process("3 +4", &valDouble);
    std::cout<<"\n process(3 +4): ";
    std::cout<<"\nError: ";
    printError(error);
    std::cout <<"Result: "<< valDouble<<"\n";
    
    error = process("-7!", &valDouble);
    std::cout<<"\n process(-7!): "; 
    std::cout<<"\nError: ";
    printError(error);
    std::cout <<"Result: "<< valDouble<<"\n";

    error = process("125  $3", &valDouble);
    std::cout<<"\n process(225  $3): ";
    std::cout<<"\nError: ";
    printError(error);
    std::cout <<"Result: "<< valDouble;
    
}
