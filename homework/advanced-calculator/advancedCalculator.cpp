#include "advancedCalculator.hpp"

#include <algorithm>
#include <array>
#include <cctype>
#include <cmath>
#include <iostream>
#include <sstream>

// main function proccessing user input
// stores result in out and returns operations state
ErrorCode process(std::string input, double* out)
{
    const auto operations_map = getAllowedOperations();
    // get formated input // NOTE: consider better function name
    auto [state, lhs, operation, rhs] = formatInput(input);
    if (state == ErrorCode::OK) {
        const auto& it = operations_map.find(operation);
        if (it != operations_map.end()) {
            const auto& calculate = it->second;
            *out = calculate(lhs, rhs);
        }
    }
    return state;
}

// returns  map assigning matematical operations to operations
OperationsMap getAllowedOperations()
{
    return OperationsMap {
        { '+', std::plus<> {} },
        { '*', std::multiplies<> {} },
        { '/', std::divides<> {} },
        { '-', std::minus<> {} },
        { '%', [](auto lhs, auto rhs) {
             return static_cast<int>(lhs)
                    % static_cast<int>(rhs);
         } },
        { '^', [](auto lhs, auto rhs) {
             return pow(lhs, rhs);
         } },
        { '$', [](auto lhs, auto rhs) {
             return pow(lhs, 1 / rhs);
         } },
        { '!', [](auto lhs, [[maybe_unused]] auto) {
             return lhs >= 0 ? tgamma(lhs + 1)
                             : -tgamma(fabs(lhs) + 1);
         } }
    };
}

// main user input formatting function
FormatedInput formatInput(const std::string& line)
{
    if (hasUnallowedChars(line)) {
        return { ErrorCode::BadCharacter, 0, ' ', 0 };
    }

    auto [state, lhs, oper, rhs] = parseCheckFormatErrors(line);
    if (state != ErrorCode::BadFormat) {
        state = checkSpecialCases(state, lhs, oper, rhs, line);
    }

    return FormatedInput { state, lhs, oper, rhs };
}

// helper for format Input. Parses input in search  for format errors
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

// helper for input formatting
// checks if user has used invalid decimal seperator in the input
bool invalidDecimalSeperator(const std::string& line, const char invalidSep)
{
    auto pos = line.find(invalidSep);
    return pos != std::string::npos;
}

// helper for input formatting
// checks if the user inserted wrong character at the start of input
bool firstCharIllegal(std::istringstream& stream)
{
    char first_char = stream.peek();
    return !isdigit(first_char) && first_char != '-';
}

// helper for input formatting
// checks if a nondigit character bellongs to allowed special characters
bool isAllowedChar(const char oper)
{
    static constexpr std::array<char, 11> allowed = { '+', '*', '/', '-', '%', '!', '^', '$', ',', ' ', '.' };
    return std::any_of(begin(allowed),
                       end(allowed),
                       [oper](auto ch) {
                           return ch == oper;
                       });
}

// helper for parsing and checking format of input
// on the right side of mathematical operation symbol
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

// helper for input formatting
// maps special cases of user input into ErrorCodes
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
    else if (operation == '$' && lhs < 0) {
        current_state = ErrorCode::SqrtOfNegativeNumber;
    }

    return current_state;
}

// helper for input formatting
// checks if input provided by the user contains unnalowed characters
bool hasUnallowedChars(const std::string& line)
{
    return std::any_of(begin(line),
                       end(line),
                       [](auto ch) {
                           return !isdigit(ch) && !isAllowedChar(ch);
                       });
}

// helper for dettecting non-integer modulo operation in the user input
ErrorCode checkForNonIntigerModulo(ErrorCode current_state, const std::string& line)
{
    if (line.find('.') != std::string::npos) {
        current_state = ErrorCode::ModuleOfNonIntegerValue;
    }

    return current_state;
}

// prints usage instructions to the console
void printInstructions()
{
    std::cout << "============== Simple calculator =================\n"
              << "==> adding ('-')\n"
              << "==> substracting ('+')\n"
              << "==> multiplying ('*')\n"
              << "==> division ('/')\n"
              << "==> factorial ( <number>!)\n"
              << "==> modulo ('%')\n"
              << "==> computing power ( <number> ^ <exponent> )\n"
              << "==> computing root(<number> $ <root-base> )\n"
              << "### Type 'quit' to finish working with calculator.\n"
              << "---------------------------\n";
}

// prints the result of user requested calculations to the console
void printResult(ErrorCode state, double result)
{
    std::map<ErrorCode, std::string> messages {
        { ErrorCode::OK, "RESULT: " },
        { ErrorCode::BadCharacter, "Bad character included! Try again...\n\n" },
        { ErrorCode::BadFormat, "Bad format of user input! Try again...\n\n" },
        { ErrorCode::DivideBy0, "Cannot divide by 0! Try again...\n\n" },
        { ErrorCode::ModuleOfNonIntegerValue,
          "Cannot calculate module of a floating point! Try again...\n\n" },
        { ErrorCode::SqrtOfNegativeNumber,
          "Cannot calculate root of a negative number! Try again...\n\n" }
    };

    std::cout << "*************\n"
              << messages[state];
    if (state == ErrorCode::OK) {
        std::cout << result << "\n-------------\n"
                  << std::endl;
    }
}

// helper for checking if user requested to quit
bool quitRequested(std::string line)
{
    std::transform(begin(line), end(line), begin(line), tolower);
    auto search = line.find("quit");
    return search != std::string::npos;
}
