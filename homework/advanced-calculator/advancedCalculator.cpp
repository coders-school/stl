#include <algorithm>
#include <cmath>
#include <functional>
#include <map>

#include "advancedCalculator.hpp"

std::map<char, std::function<double(double a, double b)> > calcMap{
    { '+', [](auto a, auto b) { return a + b; } },
    { '-', [](auto a, auto b) { return a - b; } },
    { '*', [](auto a, auto b) { return a * b; } },
    { '/', [](auto a, auto b) { return a / b; } },
    { '%', [](auto a,
               auto b) { return (static_cast<int>(a) % static_cast<int>(b)); } },
    { '!',
        [](auto a, auto b) {
            return (a < 0 ? std::tgamma(-a + 1) * (-1) : std::tgamma(a + 1));
        } },
    { '^', [](auto a, auto b) { return std::pow(a, b); } },
    { '$', [](auto a, auto b) { return std::pow(a, 1.0 / b); } }
};

std::ostream& operator<<(std::ostream& out, const ErrorCode& err)
{
    switch (err) {
    case ErrorCode::OK:
        out << "OK\n";
        break;
    case ErrorCode::BadCharacter:
        out << "BadCharacter\n";
        break;
    case ErrorCode::BadFormat:
        out << "BadFormat\n";
        break;
    case ErrorCode::DivideBy0:
        out << "DivideBy0\n";
        break;
    case ErrorCode::SqrtOfNegativeNumber:
        out << "SqrtOfNegativeNumber\n";
        break;
    case ErrorCode::ModuleOfNonIntegerValue:
        out << "ModuleOfNonIntegerValue\n";
        break;
    }

    return out;
}

ErrorCode findError(const std::string& input)
{
    size_t str_size = input.size();

    // find invalid character
    if (input.find_first_of("~@#&:;?\\[]=", 0) != std::string::npos) {
        return ErrorCode::BadCharacter;
    }

    // starts from 1 to allow negative value
    auto sym_pos = input.find_first_of("+*/-%!^$", 1);
    if (sym_pos == std::string::npos) {
        return ErrorCode::BadFormat;
    }

    // find comma and return BadFormat
    if (input.find_first_of(",", 0) != std::string::npos) {
        return ErrorCode::BadFormat;
    }

    // find non-digit char different from '-' at the beginning of input str
    if (!std::isdigit(input[0]) && input[0] != '-') {
        if (std::isalpha(input[0])) {
            return ErrorCode::BadCharacter;
        } else {
            return ErrorCode::BadFormat;
        }
    }

    // find non-digit char different from '!' at the end of input str
    if (!std::isdigit(input[str_size - 1]) && input[str_size - 1] != '!') {
        return ErrorCode::BadFormat;
    }

    // find doubled symbols in operation
    if (input.find_first_of("+*/%!^$", sym_pos + 1) != std::string::npos) {
        return ErrorCode::BadFormat;
    }

    // find doubled '.' in operation
    if (std::count(input.substr(0, sym_pos).begin(),
            input.substr(0, sym_pos).end(), '.')
            > 2
        || std::count(input.substr(sym_pos, str_size).begin(),
               input.substr(sym_pos, str_size).end(), '.')
            > 2) {
        return ErrorCode::BadFormat;
    }

    return ErrorCode::OK;
}

ErrorCode process(std::string input, double* out)
{
    double a{}, b{};
    char c{};

    // remove spaces
    auto end_pos = std::remove(input.begin(), input.end(), ' ');
    input.erase(end_pos, input.end());

    size_t str_size = input.size();

    auto err = findError(input);
    if (err != ErrorCode::OK) {
        return err;
    }

    // starts from 1 to allow negative value
    auto sym_pos = input.find_first_of("+*/-%!^$", 1);

    try {
        a = stod(input.substr(0, sym_pos));
        c = input[sym_pos];
        if (sym_pos < str_size - 1) {
            b = stod(input.substr(++sym_pos, str_size));
        }
    } catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return ErrorCode::BadFormat;
    }

    // find division by 0
    if (c == '/' && b == 0.0) {
        return ErrorCode::DivideBy0;
    }

    // find sqrt of negative value
    if (c == '$' && a < 0.0) {
        return ErrorCode::SqrtOfNegativeNumber;
    }

    // find more chars after '!'
    if (c == '!' && sym_pos != str_size - 1) {
        return ErrorCode::BadFormat;
    }

    double iptr{};
    // find module operation on non-integral value
    if (c == '%' && (std::modf(a, &iptr) != 0 || std::modf(b, &iptr) != 0)) {
        return ErrorCode::ModuleOfNonIntegerValue;
    }

    *out = calcMap[c](static_cast<double>(a), b);

    return ErrorCode::OK;
}
