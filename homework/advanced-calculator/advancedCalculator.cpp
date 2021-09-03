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
    return allAllowedCharacters.find(sign) != std::string::npos;
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
	if(!isdigit(front) || (front == '-')) {
		std::cout << "jestem tu\n";
			return true;
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

	std ::cout << firstValue << " "  << sign << " " << secondValue << '\n';
        if (sign == '!') {
		if (isBadValue(firstValue) || !secondValue.empty()) {
			return true; 
		} else {        
			data.first = convertStringToDouble(firstValue);
		        data.second = convertStringToDouble(secondValue);
		        data.sign = sign;
			return false;
	       	} 
	}

        if (isBadValue(firstValue) || isBadValue(secondValue)) {
	       	return true;
        }

        data.first = convertStringToDouble(firstValue);
        data.second = convertStringToDouble(secondValue);
        data.sign = sign;
	

        return false;
}

bool isDividedByZero(const Data& data){
        return (data.sign == '/' &&  data.second == 0);
}

bool isModuleOfNonIntegerValue(const Data& data){
        return data.sign == '%' &&  (static_cast<int>(data.second) != data.second || static_cast<int>(data.first) != data.first);
}

bool isSqrtOfNegativeNumber(const Data& data)  {
        return (data.sign == '$' &&  data.first < 0);
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

//        if (isSqrtOfNegativeNumber(data)) {
  //              return ErrorCode::SqrtOfNegativeNumber;
    //    }

 //       if (isDividedByZero(data)) {
     //           return ErrorCode::DivideBy0;
   //     }

  //      if (isModuleOfNonIntegerValue(data)) {
   //             return ErrorCode::ModuleOfNonIntegerValue;
     //   }

    //    *out = operations.at(data.sign)(data.first, data.second);
    //
	std::cout << "first:"<< data.first <<" second:"<<data.sign <<" second:" << data.second <<'\n';  

        return operations.at(data.sign)(data.first, data.second, out);
}

