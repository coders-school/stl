#include <iostream>
#include <string>

#include "advancedCalculator.hpp"


void printErrorCode(ErrorCode error) {
	if (error == ErrorCode::OK) { std::cout << "OK\n"; }
        if (error == ErrorCode::BadCharacter) { std::cout << "BadCharacter\n"; }
	if (error == ErrorCode::BadFormat) { std::cout << "BadFormat\n"; }
	if (error == ErrorCode::DivideBy0) { std::cout << "DivideBy0\n"; }
	if (error == ErrorCode::SqrtOfNegativeNumber) { std::cout << "SqrtOfNegativeNumber\n"; }
	if (error == ErrorCode::ModuleOfNonIntegerValue) { std::cout << "ModuleOfNonIntegerValue\n"; }
}	      

int main() {

	double out;

	std::string input; 
	std::cout << " Podaj dzialanie :\n";
	std::getline(std::cin, input);	
	std::string calc= "-8.5 +    -9.56.3";

	auto message = process(input, &out);

	printErrorCode(message);
	if (message == ErrorCode::OK) {
		std::cout << out << '\n';
	}
}
