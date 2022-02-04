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

    auto [state, lhs, oper, rhs] = parseCheckFormatErrors(line);
    // if (state == ErrorCode::BadFormat) {
    //     return { ErrorCode::BadFormat, 0, ' ', 0 };
    // }
    if (state != ErrorCode::BadFormat) {
        state = checkSpecialCases(state, lhs, oper, rhs, line);
    }

    return FormatedInput { state, lhs, oper, rhs };
}

ErrorCode checkSpecialCases(ErrorCode current_state,
                            double lhs,
                            char operation,
                            double rhs,
                            const std::string& line)
{
    if (operation == '/' && (rhs == 0)) {
        current_state = ErrorCode::DivideBy0;
    }
    else if (operation == '%') {
        current_state = checkForNonIntigerModulo(current_state, line);
    }

    return current_state;
}

ErrorCode checkForNonIntigerModulo(ErrorCode current_state, const std::string& line)
{
    if (line.find('.') != std::string::npos) {
        current_state = ErrorCode::ModuleOfNonIntegerValue;
    }

    return current_state;
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

FormatedInput parseCheckFormatErrors(const std::string& line)
{
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
    state = parseCheckRightSide(state, operation, rhs, line_stream);

    return FormatedInput { state, lhs, operation, rhs };
}

ErrorCode parseCheckRightSide(ErrorCode current_state,
                              const char operation,
                              double& rhs,
                              std::istringstream& stream)
{
    // copy what's left in the stream
    std::string all_after_operator;
    std::getline(stream, all_after_operator);
    // and reaload it to the stream with resetting state
    stream.clear();
    stream.str(all_after_operator);
    // try to read the right hand side operand
    bool rhs_read_wrong = !(stream >> rhs);
    std::string garbage_left;
    // in the factorial operation there should be nothing to the right of operator
    // in other operations right hand side operand should be read without error
    // there should be no garbage left after reading the right hand side opperand
    if ((operation == '!' && !all_after_operator.empty())
        || (operation != '!' && rhs_read_wrong)
        || (stream >> garbage_left)) {
        current_state = ErrorCode::BadFormat;
    }

    return current_state;
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
