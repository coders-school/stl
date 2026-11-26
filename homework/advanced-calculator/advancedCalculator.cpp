#include "advancedCalculator.hpp"

#include <cmath>
#include <functional>
#include <map>

#include <cctype>
#include <cstdlib>

bool parseNumber(
    const std::string& input,
    std::size_t& position,
    double& result) {
    while (position < input.size() &&
           std::isspace(static_cast<unsigned char>(input[position]))) {
        ++position;
    }

    if (position < input.size() && input[position] == '+') {
        return false;
    }

    const char* start = input.c_str() + position;
    char* end = nullptr;

    result = std::strtod(start, &end);

    if (start == end) {
        return false;
    }

    position = static_cast<std::size_t>(end - input.c_str());

    return true;
}

bool parseOperator(const std::string& input,
                   std::size_t& position,
                   char& operation) {
    while (position < input.size() &&
           std::isspace(static_cast<unsigned char>(input[position]))) {
        ++position;
    }

    if (position >= input.size()) {
        return false;
    }

    operation = input[position];

    ++position;
    return true;
}

std::map<char, std::function<double(double, double)>> createOperations() {
    std::map<char, std::function<double(double, double)>> operations;

    operations['+'] = [](double a, double b) {
        return a + b;
    };

    operations['-'] = [](double a, double b) {
        return a - b;
    };

    operations['*'] = [](double a, double b) {
        return a * b;
    };

    operations['/'] = [](double a, double b) {
        return a / b;
    };

    operations['^'] = [](double a, double b) {
        return std::pow(a, b);
    };

    operations['$'] = [](double a, double b) {
        return std::pow(a, 1.0 / b);
    };
    operations['%'] = [](double a, double b) {
        return std::fmod(a, b);
    };

    return operations;
}

std::map<char, std::function<double(double)>> createUnaryOperations() {
    std::map<char, std::function<double(double)>> operations;

    operations['!'] = [](double a) {
        return std::copysign(std::tgamma(std::abs(a) + 1), a);
    };

    return operations;
}

ErrorCode process(std::string input, double* out) {
    if (out == nullptr) {
        return ErrorCode::BadFormat;
    }
    bool hasComma = false;
    bool hasOtherInvalidCharacter = false;

    for (unsigned char c : input) {
        if (c == ',') {
            hasComma = true;
        } else if (!std::isdigit(c) &&
                   !std::isspace(c) &&
                   c != '.' &&
                   c != '+' &&
                   c != '-' &&
                   c != '*' &&
                   c != '/' &&
                   c != '%' &&
                   c != '^' &&
                   c != '$' &&
                   c != '!') {
            hasOtherInvalidCharacter = true;
        }
    }

    if (hasOtherInvalidCharacter) {
        return ErrorCode::BadCharacter;
    }

    if (hasComma) {
        return ErrorCode::BadFormat;
    }

    std::size_t position = 0;

    double firstNumber = 0;
    double secondNumber = 0;
    char operation = '\0';

    // 1. Read first number
    if (!parseNumber(input, position, firstNumber)) {
        return ErrorCode::BadFormat;
    }

    // 2. Read operator
    if (!parseOperator(input, position, operation)) {
        return ErrorCode::BadFormat;
    }

    if (operation == '!') {
        while (position < input.size() &&
               std::isspace(static_cast<unsigned char>(input[position]))) {
            ++position;
        }

        if (position != input.size()) {
            return ErrorCode::BadFormat;
        }

        auto unaryOperations = createUnaryOperations();
        *out = unaryOperations.at('!')(firstNumber);

        return ErrorCode::OK;
    }
    auto operations = createOperations();

    if (operation == '.') {
        return ErrorCode::BadFormat;
    }

    auto it = operations.find(operation);

    if (it == operations.end()) {
        return ErrorCode::BadCharacter;
    }

    // 3. Read second number
    if (!parseNumber(input, position, secondNumber)) {
        return ErrorCode::BadFormat;
    }

    // 4. Check that nothing remains
    while (position < input.size() &&
           std::isspace(static_cast<unsigned char>(input[position]))) {
        ++position;
    }

    if (position != input.size()) {
        return ErrorCode::BadFormat;
    }

    // 5. Find operation

    // 6. Check special cases
    if (operation == '/' && secondNumber == 0) {
        return ErrorCode::DivideBy0;
    }

    if (operation == '$' && firstNumber < 0) {
        return ErrorCode::SqrtOfNegativeNumber;
    }

    if (operation == '%' &&
        (std::floor(firstNumber) != firstNumber ||
         std::floor(secondNumber) != secondNumber)) {
        return ErrorCode::ModuleOfNonIntegerValue;
    }

    // 7. Calculate
    double result = it->second(firstNumber, secondNumber);

    *out = result;

    return ErrorCode::OK;
}
