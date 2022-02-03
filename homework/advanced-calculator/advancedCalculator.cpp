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
}

TokensVector getTokens(const std::string& line)
{
    std::vector<std::string> tokens_vec;
    std::istringstream line_stream(line);
    std::string token;
    while (line_stream >> token) {
        tokens_vec.emplace_back(token);
    }
    return tokens_vec;
}

bool hasUnallowedChars(const std::string& line)
{
    constexpr std::array<char, 8> allowed = { '+', '*', '/', '-', '%', '!', '^', '$' };
    auto is_allowed_operator = [&allowed](auto ch) -> bool {
        std::any_of(begin(allowed), end(allowed), [ch](auto oper) {
            return ch == oper;
        });
    };

    return !std::all_of(begin(line),
                        end(line),
                        [&is_allowed_operator](auto ch) {
                            return isdigit(ch) || is_allowed_operator(ch);
                        });
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
