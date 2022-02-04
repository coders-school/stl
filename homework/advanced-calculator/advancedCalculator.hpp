#pragma once
#include <functional>
#include <map>
#include <string>
#include <utility>

enum class ErrorCode
{
    OK,
    BadCharacter,             // operator other then a number
    BadFormat,                // bad command format, e.g. "+ 5 4" instead of "4 + 5"
    DivideBy0,                // attempt of division by zero
    SqrtOfNegativeNumber,     // attempt of getting Sqrt of negative numbber
    ModuleOfNonIntegerValue   // attempt of getting modulo of non integer value
};

// namespace for assigning operation symbols to mathematical operations
namespace calc {
constexpr char add = { '+' };
constexpr char substr = { '-' };
constexpr char multiply = { '*' };
constexpr char div = { '/' };
constexpr char mod = { '%' };
constexpr char pwr = { '^' };
constexpr char root = { '$' };
constexpr char factorial = { '!' };
}   // namespace calc

// allias for grouping errorcode and operation components
using FormatedInput = std::tuple<ErrorCode, double, char, double>;
// allias for map assigning matematical operations to operations
using OperationsMap = std::map<const char, std::function<double(double, double)>>;

using TokensVector = std::vector<std::string>;

ErrorCode process(std::string input, double* out);

OperationsMap getAllowedOperations();

FormatedInput formatInput(const std::string& line);

ErrorCode checkSpecialCases(ErrorCode current_state,
                            double lhs,
                            char operation,
                            double rhs,
                            const std::string& line);

ErrorCode checkForNonIntigerModulo(ErrorCode current_state, const std::string& line);

bool quitRequested(std::string line);

void printInstructions();

void printResult(ErrorCode state, double result);

// REMOVE INU
// TokensVector getTokens(const std::string& line);

bool isAllowedChar(const char oper);

bool hasUnallowedChars(const std::string& line);

// bool hasBadFormat(const TokensVector& tokens);

FormatedInput parseCheckFormatErrors(const std::string& line);

ErrorCode parseCheckRightSide(ErrorCode current_state,
                              const char oper,
                              double& rhs,
                              std::istringstream& stream);

bool firstCharIllegal(std::istringstream& stream);

bool invalidDecimalSeperator(const std::string& line, const char invalidSep = ',');

//   * Dodawanie, mnożenie, dzielenie, odejmowanie (`+`,  `*` , `/` , `-`)
// * Modulo (`%`)
// * Obliczanie silni (`!`)
// * Podnoszenie liczby do potęgi (`^`)
// * Obliczanie pierwiastka (`$`)

// auto add = [](auto lhs, auto rhs) { return lhs + rhs; };

// auto multiply = []