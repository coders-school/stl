#include "advancedCalculator.hpp"

#include <map>
#include <functional>
#include <cmath>
#include <cfenv>

ErrorCode devideOperation(double a, double b, double* result);
ErrorCode moduleOperation(double a, double b, double* result);
ErrorCode factorialOperation(double a, double, double* result);
ErrorCode sqrtOperation(double a, double b, double* result);

bool isOperation(char ch);
void skipSpaces(const std::string& input, size_t& index );
std::string parseValue(const std::string& input, size_t& index);
std::string parseOperation(const std::string& input, size_t& index);
bool castValue(double& value, const std::string& str);
bool testCharacters(const std::string& input);
bool testResult(const std::string& input, const std::string& operationCode, const size_t index, double& secondValue);

// _______________________________________________________________________________________________________
// -------------------------------------------------------------------------------------------------------
const std::map<char, std::function<ErrorCode(double, double, double*)>> operations {
	{'+', [](double a, double b, double* result) { *result = a + b; return ErrorCode::OK; }},
	{'-', [](double a, double b, double* result) { *result = a - b; return ErrorCode::OK; }},
	{'*', [](double a, double b, double* result) { *result = a * b; return ErrorCode::OK; }},
	{'/', devideOperation},
	{'%', moduleOperation},
	{'!', factorialOperation},
	{'^', [](double a, double b, double* result) { *result = std::pow(a, b); return ErrorCode::OK; }},
	{'$', sqrtOperation}
};

ErrorCode process(std::string input, double* out) {
	size_t i = 0;

	if (input.find('!') == std::string::npos) {
		if (!testCharacters(input)) {
			return ErrorCode::BadCharacter;
		}
	}
	
	double a;
	if (!castValue(a, parseValue(input, i))) {
		return ErrorCode::BadFormat;
	}

	skipSpaces(input, i);
	std::string operation = parseOperation(input, i);

	double b;
	if (operation != "!") {
		skipSpaces(input, i);		
		castValue(b, parseValue(input, i));
	}

	if (!testResult(input, operation, i, b)) {
		return ErrorCode::BadFormat;
	}
	auto it = operations.find(operation[0]);
	return std::invoke(it->second, a, b, out);
}

// _______________________________________________________________________________________________________
// -------------------------------------------------------------------------------------------------------
ErrorCode devideOperation(double a, double b, double* result) {
	if (b == 0) {
		return ErrorCode::DivideBy0;
	}
	*result = a / b;
	return ErrorCode::OK;
}

ErrorCode moduleOperation(double a, double b, double* result) {
    std::feclearexcept(FE_ALL_EXCEPT);
    auto value = std::fmod(a, b);

    if(std::fetestexcept(FE_INVALID) || a != static_cast<int>(a) || b != static_cast<int>(b)) {
		return ErrorCode::ModuleOfNonIntegerValue;
	}
	*result = value;
	return ErrorCode::OK;
}

ErrorCode factorialOperation(double a, double, double* result) {
	if (a < 0) {
		a *= -1;
		*result = std::tgamma(a + 1); //1;
		*result *= -1;
	}
	else {
		*result = std::tgamma(a + 1); //1;
	}
	return ErrorCode::OK;
}

ErrorCode sqrtOperation(double a, double b, double* result) {
	if (a < 0) {
		return ErrorCode::SqrtOfNegativeNumber;
	}
	*result = std::pow(a, 1/b); 
	return ErrorCode::OK; 
}

// _______________________________________________________________________________________________________
// -------------------------------------------------------------------------------------------------------
bool isOperation(char ch) {
	return operations.find(ch) != operations.end();
} 

void skipSpaces(const std::string& input, size_t& index ) {
	for ( ; index < input.size(); ++index) {
		if (input[index] != ' ') {
			break;
		}
	}
}

std::string parseValue(const std::string& input, size_t& index) {
	std::string result; // = "";
	bool canDot = true;

	if (input.at(index) == '-') {
		result += '-';
		++index;
	}
	for ( ; index < input.size(); ++index) {
		auto ch = input[index];
		if (std::isdigit(ch)) {
			result += ch;
			continue;
		}
		if (ch == '.' && canDot) {
			canDot = false;
			result += ch;
			continue;
		}
		return result;
	}
	return result;
}

std::string parseOperation(const std::string& input, size_t& index) {
	std::string result;
	for ( ; index < input.size(); ++index) {
		char ch = input[index];
		if (!isOperation(ch)) {
			if (std::isdigit(ch) || ch == ' ') {
				break;				
			}
		}
		result += ch;
	}
	return result;
}

bool castValue(double& value, const std::string& str) {
	try {
		value = std::stod(str);
	}
	catch (...) {
		return false;
	}
	return true;
}

bool testResult(const std::string& input, const std::string& operationCode, const size_t index, double& secondValue) {
	if (index < input.size()) {
		return false;
	}
	if (operationCode.size() != 1) {
		if (operationCode.size() == 2 && operationCode.back() == '-') {		
			secondValue *= -1;
		}
		else {
			return false;
		}
	}
	return true;
}

bool testCharacters(const std::string& input) {
	for (char ch : input) {
		if (!std::isdigit(ch) && !isOperation(ch) && ch != ' ' && ch != '.' && ch != ',') {
			return false;
		}
	}
	return true;
}