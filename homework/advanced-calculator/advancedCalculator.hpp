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

using FormatedInput = std::tuple<ErrorCode, double, char, double>;

using OperationsMap = std::map<char, std::function<std::pair<ErrorCode, double>(double, double)>>;

using TokensVector = std::vector<std::string>;

ErrorCode process(std::string input, double* out);

FormatedInput formatInput(const std::string& line);

bool quitRequested(std::string line);

void printInstructions();

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