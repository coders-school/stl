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

    return state;
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

    auto [state, lhs, oper, rhs] = checkFormatErrors(line);
    if (state == ErrorCode::BadFormat) {
        return { ErrorCode::BadFormat, 0, ' ', 0 };
    }

    return FormatedInput { state, lhs, oper, rhs };
}

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
    // FormatedInput result;
    // auto& [state, lhs, operation, rhs] = result;
    ErrorCode state = ErrorCode::OK;
    double lhs {};
    double rhs {};
    char operation {};
    std::istringstream line_stream(line);
    if (invalidDecimalSeperator(line)
        || firstCharIllegal(line_stream)
        // check if retrieving left hand operand and operator succeds
        || (!(line_stream >> lhs >> operation))) {
        state = ErrorCode::BadFormat;
    }
    std::string all_after_operator;
    std::getline(line_stream, all_after_operator);
    line_stream.clear();
    line_stream.str(all_after_operator);
    bool rhs_read_wrong = !(line_stream >> rhs);
    std::string garbage_left;
    if (operation == '!' && !all_after_operator.empty()
        || operation != '!' && rhs_read_wrong) {
        state = ErrorCode::BadFormat;
    }
    if (line_stream >> garbage_left) {
        state = ErrorCode::BadFormat;
    }

    // bool second_part_empty = std::getline(line_stream, all_after_operator);
    // check if right hand side operand retreives succesfuly
    // bool rhs_not_read = !(line_stream >> rhs);
    // if (rhs_not_read && operation == '!') {
    //     state = ErrorCode::OK;
    // }
    // // if (!(line_stream >> rhs))
    // // for factorial rhs should not read
    // else if (rhs_not_read && operation != '!'
    //          // operation is factorial and we got something which shouldn't got there
    //          || (operation == '!' && rhs != 0)
    //          // there where leftovers in the stream after taking 2 operands and operator
    //          || (line_stream >> stream_garbage)) {
    //     state = ErrorCode::BadFormat;
    // }
    // else {
    //     state = ErrorCode::OK;
    // }

    // if (invalidDecimalSeperator(line) || firstCharIllegal(line_stream)) {
    //     state = ErrorCode::BadFormat;
    // }
    // // check if retrieving left hand operand and operator succeds
    // else if (!(line_stream >> lhs >> operation)) {
    //     state = ErrorCode::BadFormat;
    // }
    // // check if right hand side operand retreives succesfuly
    // else if (!(line_stream >> rhs)) {
    //     state = ErrorCode::BadFormat;
    // }
    // // operation is factorial and we got something which souldn't got there
    // else if (operation == '!' && rhs != 0) {
    //     state = ErrorCode::BadFormat;
    // }
    // // there where leftovers in the stream after taking 2 operands and operator
    // else if (line_stream >> stream_garbage) {
    //     state = ErrorCode::BadFormat;
    // }
    // else {
    //     state = ErrorCode::OK;
    // }

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
