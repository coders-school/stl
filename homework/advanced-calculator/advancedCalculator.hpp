#pragma once
#include <functional>
#include <map>
#include <string>

enum class ErrorCode
{
    OK,
    BadCharacter,             // operator other then a number
    BadFormat,                // bad command format, e.g. "+ 5 4" instead of "4 + 5"
    DivideBy0,                // attempt of division by zero
    SqrtOfNegativeNumber,     // attempt of getting Sqrt of negative numbber
    ModuleOfNonIntegerValue   // attempt of getting modulo of non integer value
};

// namespace for constants
namespace calc {
constexpr char add = { '+' };
constexpr char sub = { '-' };
constexpr char multiply = { '*' };
constexpr char div = { '/' };
constexpr char mod = { '%' };
constexpr char pwr = { '^' };
constexpr char root = { '$' };
constexpr char factorial = { '!' };
constexpr char punct = { '.' };
constexpr char comma = { ',' };
constexpr char space = { ' ' };
}   // namespace calc

// allias for grouping errorcode and operation components
using FormatedInput = std::tuple<ErrorCode, double, char, double>;
// allias for map assigning matematical operations to operations
using OperationsMap = std::map<const char, std::function<double(double, double)>>;

// main function proccessing user input
// stores result in out and returns operations state
ErrorCode process(const std::string& input, double* out);

// returns  map assigning matematical operations to operations
OperationsMap getAllowedOperations();

// main user input formatting function
FormatedInput parseAndformatInput(const std::string& line);

// helper for format Input. Parses input for format errors
FormatedInput parseCheckFormatErrors(const std::string& line);

// helper for input formatting
// checks if user has used invalid decimal seperator in the input
bool invalidDecimalSeperator(const std::string& line, const char invalidSep = calc::comma);

// helper for input formatting
// checks if the user inserted wrong character at the start of input
bool firstCharIllegal(std::istringstream& stream);

// helper for input formatting
// checks if a nondigit character bellongs to allowed special characters
bool isAllowedChar(const char oper);

// helper for parsing and checking format of input
// on the right side of mathematical operation symbol
ErrorCode parseCheckRightSide(ErrorCode current_state,
                              const char oper,
                              double& rhs,
                              std::istringstream& stream);

// helper for input formatting
// maps special cases of user input into ErrorCodes
ErrorCode checkSpecialCases(ErrorCode current_state,
                            double lhs,
                            char operation,
                            double rhs,
                            const std::string& line);

// helper for input formatting
// checks if input provided by the user contains unnalowed characters
bool hasUnallowedChars(const std::string& line);

// helper for dettecting non-integer modulo operation in the user input
ErrorCode checkForNonIntigerModulo(ErrorCode current_state, const std::string& line);

// prints usage instructions to the console
void printInstructions();

// prints the result of user requested calculations to the console
void printResult(ErrorCode state, double result);

// helper for checking if user requested to quit
bool quitRequested(std::string line);
