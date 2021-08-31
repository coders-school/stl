#include <map>
#include <string>
#include <functional>
#include <algorithm>
#include <sstream>
#include <cmath>

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

struct Data {
    std::string firstValue;
    char character;
    std::string secondValue;
};

extern std::map<const char, std::function<double(double, double)>> calculator;

void removeSpace(std::string &input);
Data divideInput(std::string& input);
bool isBadNumber(std::string& input);
bool isBadFormat(std::string& input, Data& data);
bool isGoodCharacter(char operation);
bool isBadCharacter(std::string& input);
double stringToDouble(std::string& input);
ErrorCode process(std::string input, double* out);