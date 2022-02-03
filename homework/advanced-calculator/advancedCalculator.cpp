#include "advancedCalculator.hpp"

#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>
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
    // ErrorCode result_code = ErrorCode::OK;
    if (hasUnallowedChars(line)) {
        return { ErrorCode::BadCharacter, 0, ' ', 0 };
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

bool isAllowedOperator(const char oper)
{
    static constexpr std::array<char, 8> allowed = { '+', '*', '/', '-', '%', '!', '^', '$' };
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
                           return !(isdigit(ch) || isAllowedOperator(ch));
                       });
}

FormatedInput checkFormatErrors(const std::string& line)
{
    std::istringstream line_stream(line);
    double lhs {};
    char operation {};
    std::string rh_string;
    std::string stream_garbage;
    double rhs;
    if (invalidDecimalSeperator(line) || firstCharIllegal(line_stream)) {
        std::cout << "Returning bad-format here\n";
    }

    if (!(line_stream >> lhs >> operation) || !isAllowedOperator(operation)) {
        std::cout << "Returning bad-format here (after checking lhs and operator)\n";
    }
    // didn't manage to read anything after binary operation (other than factorial)
    if (!(line_stream >> rhs) && operation != '!') {
        std::cout << "Returning bad-format here - invalid binary operation\n";
    }
    // operation is factorial and we got something which souldn't got there
    if (operation == '!' && rhs != 0) {
        std::cout << "Returning bad-format here - invalid factorial operation\n";
    }
    // there where leftover in the stream after taking to operands and operator
    if (line_stream >> stream_garbage) {
        std::cout << "Returning bad-format here - garbage in the stream\n";
    }
    // if ()
    // ErrorCode state { ErrorCode::OK };
    //
    // else if (!(line_stream >> lhs >> operation >> rhs)) {
    //     if (operation == '!' /* && rhs != 0*/) {
    //         std::cout << "OK - factorial!\n";
    //     }
    //     else {
    //         // std::cout << "lhs: " << lhs
    //         //           << " operator: " << operation
    //         //           << " rhs" << rhs << '\n';
    //         std::cout << "Format error!\n";
    //     }
    // }
    // else if (line_stream >> garbage_left) {
    //     std::cout << "lhs: " << lhs
    //               << " operator: " << operation
    //               << " rhs: " << rhs << '\n';
    //     std::cout << "Garbage left! - FORMAT error\n";
    // }
    // else {
    //     if (operation == '!' && rhs != 0) {
    //         std::cout << "wrong factorial - FORMAT error\n";
    //     }
    //     else {
    //         std::cout << "OK\n";
    //     }
    // }
    // else
    // {
    //     std::cout << "lhs: " << lhs
    //               << " operator: " << operation
    //               << " rhs" << rhs << '\n';
    //     std::cout << "Correct format!\n";
    // }
    std::cout << "-------\n";
    return FormatedInput {};
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
