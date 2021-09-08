#pragma oonce 
#include <cmath>
#include <functional>
#include <map>
#include <string>

enum class ErrorCode { OK,
		       BadCharacter, 
		       BadFormat, 
		       DivideBy0, 
		       SqrtOfNegativeNumber, 
		       ModuleOfNonIntegerValue};

inline std::map<const char, std::function<ErrorCode (const double& a, const double& b, double* out)>> operations{
    {'+', [](const double& a, const double b, double* out) { *out = a + b; return ErrorCode::OK; }},

    {'-', [](const double& a, const double b, double* out) { *out = a - b; return ErrorCode::OK; }},

    {'*', [](const double& a, const double b, double* out) { *out = a * b; return ErrorCode::OK; }},

    {'/', [](const double& a, const double b, double* out) { if (b == 0 ) { return ErrorCode::DivideBy0; }
						*out = a / b; return ErrorCode::OK; }},

    {'%', [](const double& a, const double b, double* out) { if (static_cast<int>(a) != a || static_cast<int>(b) != b) { return ErrorCode::ModuleOfNonIntegerValue;}
						*out =  static_cast<int>(a) % static_cast<int>(b); return ErrorCode::OK; }},

    {'!', [](const double& a, [[maybe_unused]] const double b, double* out) { if (a < 0) { *out = -std::tgamma(-a + 1); return ErrorCode::OK; }
								 *out = std::tgamma(a + 1); return ErrorCode::OK; }},

    {'^', [](const double& a, const double b, double* out) { *out = std::pow(a, b); return ErrorCode::OK; }},

    {'$', [](const double& a, const double b, double* out) { if (a < 0) { return ErrorCode::SqrtOfNegativeNumber;}
						if (b == 0) { *out = 1.0; return ErrorCode::OK; }
						*out = std::pow(a, 1 / b); return ErrorCode::OK; }}};



struct Data {
        double first{};
        char sign{};
        double second{};
};


void prepareInput(std::string& input);

bool isAllowedChar(char sign);

bool isOperation(char sign);

bool isBadCharakter(const std::string& input);

bool isBadFront(std::string str);

bool isToManyDots(std::string str);

bool isPresentComma(std::string str);

bool inPresentOperationSign(std::string str);

bool isBadValue(const std::string& value);

double convertStringToDouble(const std::string& str);

void rewriteValues(const std::string& firstValue, const char sign, const std::string& secondValue, Data& data);

bool isBadFormat(const std::string& input, Data& data);

ErrorCode process(std::string input, double* out);

