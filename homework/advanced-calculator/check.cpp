#include <algorithm>
#include <cctype>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <string>


std::map<const char, std::function<double(const double& a, const double& b)>> operations{
    {'+', std::plus<double>{}},
    {'-', std::minus<double>{}},
    {'*', std::multiplies<double>{}},
    {'/', std::divides<double>{}},
    {'%', [](const double& a, const double b) { return static_cast<int>(a) % static_cast<int>(b); }},
    {'!', [](const double& a, [[maybe_unused]] const double b) { if (a < 0) { return -std::tgamma(-a + 1); }
                                                                 return std::tgamma(a + 1); }},
    {'^', [](const double& a, const double b) { return std::pow(a, b); }},
    {'$', [](const double& a, const double b) { if (b == 0) { return 1.0; }
                                                return std::pow(a, 1 / b); }}};




std::string allOperations{"+-/*!$%^"};

struct Data {
	double first;
	char sign;
	double second;
};

void prepareInput(std::string& input){
        input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
}


int count_dots(const std::string& s){
    return std::count_if(s.begin()+1, s.end(),
                         [](unsigned char c){ return c == '.'; }
                        );
}

bool isOperation(char sign){
    return allOperations.find(sign) != std::string::npos;
}


bool isBadValue(const std::string& value){
        auto front = value[0];
        std::cout << front << "\n";
	if (!(std::isdigit(front) || front == '-')) {
                std::cout << "first sign\n";
		return true;
        }
        if (count_dots(value) >=2 || value.find(',') != std::string::npos) {
                std::cout << "decimal\n";
		return true;
        }
        if (std::any_of(value.begin()+1, value.end(), isOperation)) {
                std::cout << "operation\n";
		return true;
        }

        return false;
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
		std::cout << "check 1\n";
                return true;
        }

        auto itSign = std::find_first_of(input.begin() + 1,
                                 input.end(),
                                 allOperations.begin(),
                                 allOperations.end());
	std::cout << *itSign << '\n';
	std::cout << *(std::prev(itSign,1)) << '\n';
        if (itSign == input.end() || *(std::prev(itSign,1)) == '-') {
		std::cout << "check 3\n";
                return true;
        }

        char sign = *itSign;
        std::string firstValue(input.begin(), itSign);
        std::string secondValue(itSign+1, input.end());

	std ::cout << sign << " " << firstValue << " " << secondValue <<'\n';

        if(isBadValue(firstValue) || isBadValue(secondValue)) {
                std::cout << "check 4\n";
		return true;
        }

        if (sign != '!' && secondValue.empty()) {
                std::cout << "check 5\n";
		return true;
        }

        data.first = convertStringToDouble(firstValue);
        data.second = convertStringToDouble(secondValue);
        data.sign = sign;

	std::cout << "firstVal: " << data.first << " sign: " << data.sign << " secondVal: " << data.second << '\n';

        return false;
}

void checkFormat(std::string& str, Data& data) {
	std::cout << std::boolalpha << isBadFormat(str,data) << '\n';
	
}

int main() {

	std::string input{"-hsgt5"}; 
	char front = input[0];
        std::cout << front << "\n";
        if (!(std::isdigit(front) || (front == '-'))) {
                std::cout << "wrong\n\n";
   
        } else {
		std::cout << "good\n\n";
	} 

	Data data;
	std::string str = "-7+  -5";
	prepareInput(str);
	std::cout << str << '\n';
	if (!isBadFormat(str,data)) {std::cout << operations.at(data.sign)(data.first, data.second) << '\n';};


}
