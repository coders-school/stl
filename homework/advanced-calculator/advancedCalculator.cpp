#include "advancedCalculator.hpp"

#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>
#include <limits>   // REMOVE INU
#include <sstream>

ErrorCode process(std::string input, double* out)
{
    // get formated input // NOTE: consider better function name
    auto [state, lhs, operation, rhs] = formatInput(input);
    if (state == ErrorCode::BadCharacter
        || state == ErrorCode::BadFormat
        || state == ErrorCode::DivideBy0
        || state == ErrorCode::ModuleOfNonIntegerValue
        || state == ErrorCode::SqrtOfNegativeNumber) {
        return state;
    }

    return ErrorCode::OK;
}

bool quitRequested(std::string line)
{
    std::transform(begin(line), end(line), begin(line), tolower);

    return line == "quit";
}

void printInstructions()
{
    std::cout << "-----Simple calculator-----\n"
              << "type 'quit' or enter a calculation to be performed\n";
}

FormatedInput formatInput(const std::string& line)
{
    //   * Dodawanie, mnożenie, dzielenie, odejmowanie (`+`,  `*` , `/` , `-`)
    // * Modulo (`%`)
    // * Obliczanie silni (`!`)
    // * Podnoszenie liczby do potęgi (`^`)
    // * Obliczanie pierwiastka (`$`)
    ErrorCode result_code = ErrorCode::OK;
    if (hasUnallowedChars(line)) {
        return { ErrorCode::BadCharacter, 0, ' ', 0 };
    }

    auto [state, lhs, oper, rhs] = checkFormatErrors(line);
    if (state == ErrorCode::BadFormat) {
        return { ErrorCode::BadFormat, 0, ' ', 0 };
    }

    // REMOVE INU
    // TokensVector tokens = getTokens(line);
}

// REMOVE INU
//  TokensVector getTokens(const std::string& line)
//  {
//      std::vector<std::string> tokens_vec;
//      std::istringstream line_stream(line);
//      std::string token;
//      while (line_stream >> token) {
//          tokens_vec.emplace_back(token);
//      }
//      return tokens_vec;
//  }

bool isAllowedChar(const char oper)
{
    static constexpr std::array<char, 11> allowed = { '+', '*', '/', '-', '%', '!', '^', '$', ',', ' ', '.' };
    return std::any_of(begin(allowed),
                       end(allowed),
                       [oper](auto ch) {
                           return ch == oper;
                       });
}

bool hasUnallowedChars(const std::string& line)
{
    // constexpr std::array<char, 8> allowed = { '+', '*', '/', '-', '%', '!', '^', '$' };
    // auto is_allowed_operator = [&allowed](auto ch) -> bool {
    //     return std::any_of(begin(allowed), end(allowed), [ch](auto oper) {
    //         return ch == oper;
    //     });
    // };

    return std::any_of(begin(line),
                       end(line),
                       [](auto ch) {
                           return !isdigit(ch) && !isAllowedChar(ch);
                       });
}

FormatedInput checkFormatErrors(const std::string& line)
{
    std::istringstream line_stream(line);
    double lhs {};
    char operation {};
    double rhs {};
    ErrorCode state { ErrorCode::OK };
    std::string stream_garbage;
    if (invalidDecimalSeperator(line) || firstCharIllegal(line_stream)) {
        // std::cout << "Returning bad-format here\n";
        state = ErrorCode::BadFormat;
    }
    else if (!(line_stream >> lhs >> operation) /*|| !isAllowedChar(operation)*/) {
        // std::cout << "Returning bad-format here (after checking lhs and operator)\n";
        state = ErrorCode::BadFormat;
    }
    // didn't manage to read anything after binary operation (other than factorial)
    else if (!(line_stream >> rhs) /*&& operation != '!'*/) {
        // std::cout << "Returning bad-format here - invalid binary operation\n";
        state = ErrorCode::BadFormat;
    }
    // operation is factorial and we got something which souldn't got there
    else if (operation == '!' && rhs != 0) {
        // std::cout << "Returning bad-format here - invalid factorial operation\n";
        state = ErrorCode::BadFormat;
    }
    // there where leftover in the stream after taking to operands and operator
    else if (line_stream >> stream_garbage) {
        // std::cout << "Returning bad-format here - garbage in the stream\n";
        state = ErrorCode::BadFormat;
    }
    else {
        state = ErrorCode::OK;
    }

    // std::cout << "-------\n";REMOVE
    // line_stream.clear();
    // line_stream.ignore(std::numeric_limits<std::streamsize>::max());
    return FormatedInput { state, lhs, operation, rhs };
}

bool firstCharIllegal(std::istringstream& stream)
{
    char first_char = stream.peek();
    return !isdigit(first_char) && first_char != '-';
}

bool invalidDecimalSeperator(const std::string& line, const char invalidSep)
{
    auto pos = line.find(invalidSep);
    return pos != std::string::npos;
}

// constexpr OperationsMap getAllowedOperations()
// {
//     // return OperationsMap {
//     //     {
//     //         '+',
//     //     },
//     //     { '*', [](auto lhs, auto rhs) {
//     //          return lhs * rhs;
//     //      } },
//     //     { '/', [](auto lhs, auto rhs) {
//     //          return lhs / rhs;
//     //      } },
//     //     { '-', [](auto lhs, auto rhs) {
//     //          return lhs - rhs;
//     //      } },
//     //     { '%', [](auto lhs, auto rhs) {
//     //          return lhs % rhs;
//     //      } },
//     //     { '!', [](auto lhs, auto rhs) {
//     //          return lhs * rhs;
//     //      } },
//     // };
// }
