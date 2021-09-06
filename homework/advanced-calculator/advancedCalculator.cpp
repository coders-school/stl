#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>

#include "advancedCalculator.hpp"

std::string allOperations{"+-/*!$%^"};
std::string allAllowedCharacters{"+-/*!$%^.,0123456789"};

void prepareInput(std::string& input){
        input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
}

bool isAllowedChar(char sign){
    return operations.find(sign) != operations.end();
}

bool isBadCharakter(const std::string& input) {
    for (auto el : input) {
        if(!isAllowedChar(el)) {
                return true;
        }
    }
    return false;
}

bool isOperation(char sign){
    return allOperations.find(sign) != std::string::npos;
}

bool isBadFront(std::string str) {
	auto front = str.front();
	if (!isdigit(front)){
	       if(!(front == '-' && str.size() > 1)) {
			return true;
		}
	}
	return false;
}

bool isToManyDots(std::string str) {
    return std::count_if(str.begin()+1, str.end(),
                         [](unsigned char c){ return c == '.'; }
                        ) >=2;
}

bool isPresentComma(std::string str) {
	return str.find(',') != std::string::npos;
}

bool inPresentOperationSign(std::string str) {
       	return std::any_of(str.begin()+1, str.end(), isOperation);
}

bool isBadValue(const std::string& value){
	std::vector<bool(*)(std::string)> functions{isBadFront, isToManyDots, isPresentComma, inPresentOperationSign};	
	return std::any_of(functions.begin(), functions.end(), [&](auto function){
								return function(value);
								});
}

double convertStringToDouble(const std::string& str) {
        if (str.empty()) {
                return 0.0;
        }
        return std::stod(str);
}
void rewriteValues(const std::string& firstValue, const char sign, const std::string& secondValue, Data& data) {
	data.first = convertStringToDouble(firstValue);
	data.second = convertStringToDouble(secondValue);
	data.sign = sign;
}

bool isBadFormat(const std::string& input, Data& data){
	std::string allOperations{"+-/*!$%^"};

	if (input.empty()) {
                return true;
        }

        auto itSign = std::find_first_of(input.begin() + 1,
                                 input.end(),
                                 allOperations.begin(),
                                 allOperations.end());
        if (itSign == input.end() || *(itSign-1) == '-') {
                return true;
        }

        char sign = *itSign;
        std::string firstValue(input.begin(), itSign);
        std::string secondValue(itSign+1, input.end());

        if (sign == '!') {
		if (isBadValue(firstValue) || !secondValue.empty()) {
			return true; 
		} else { 
		 	rewriteValues(firstValue, sign, secondValue, data);	
			return false;
	       	} 
	}

        if (isBadValue(firstValue) || isBadValue(secondValue)) {
	       	return true;
        }

	rewriteValues(firstValue, sign, secondValue, data);

        return false;
}

ErrorCode process(std::string input, double* out)  {

        Data data;

        prepareInput(input);

        if (isBadCharakter(input)) {
                return ErrorCode::BadCharacter;
        }

        if (isBadFormat(input, data)) {
                return ErrorCode::BadFormat;
        }

	std::cout << "first:"<< data.first <<" second:"<<data.sign <<" second:" << data.second <<'\n';  

        return operations.at(data.sign)(data.first, data.second, out);
}

