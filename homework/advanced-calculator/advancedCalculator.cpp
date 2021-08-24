#include "advancedCalculator.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdexcept>


bool is_not_integer(double number) {
    return std::floor(number) != number;
}

bool loadNumber(std::string& value, double& number) {
    size_t idx = 0;
    std::string num = "1234567890";
    size_t plusPosition = 0;
    size_t numberPosition = 0;
    plusPosition = value.find_first_of('+');
    if (plusPosition != std::string::npos) {
        numberPosition = value.find_first_of(num);
        if (plusPosition < numberPosition) {
            return true;
        }
    }
    try {
        number = stod(value, &idx);
        value.erase(0, idx);
    } catch (std::invalid_argument& e) {
        return true;
    }
    return false;
}

bool loadCharacter(std::string& value, char& sign) {
    std::string characters = "+-*/%!^$";
    std::string num = "1234567890";
    size_t charPosition = 0;
    size_t numberPosition = 0;
    charPosition = value.find_first_of(characters);
    if (charPosition != std::string::npos) {
        numberPosition = value.find_first_of(num);
        if (numberPosition < charPosition) {
            return true;
        } else {
            sign = value[charPosition];
            value.erase(0, charPosition + 1);
            if ((sign == '!') && (value.size() > 0)) {
                return true;
            }
            return false;
        }
    } else {
        return true;
    }
}

bool BadCharacter(const std::string& value) {
    std::string characters = "+-*/%!^$1234567890,. ";
    size_t it;
    it = value.find_first_not_of(characters);
    if (it != std::string::npos) {
        return true;
    }
    return false;
}

bool characterCountTest(const std::string& value) {
    std::string characters = "+*/%!^$";
    size_t sum = 0;
    for (size_t i = 0; i < characters.size(); i++) {
        auto numberOfChar = std::count(begin(value), end(value), characters[i]);
        sum += numberOfChar;
        if (numberOfChar > 1) {
            return true;
        }
    }
    if (sum > 1) {
        return true;
    }
    auto num = std::count(begin(value), end(value), '.');
    if (num > 2) {
        return true;
    }
    auto numChar = std::count(begin(value), end(value), ',');
    if (numChar > 0) {
        return true;
    }
    auto numberChar = std::count(begin(value), end(value), '-');
    if (numberChar > 3) {
        return true;
    }
    return false;
}

bool BadFormat(std::string input, double& firstNumber, double& secondNumber, char& sign) {
    if (characterCountTest(input)) {
        return true;
    }
    if (loadNumber(input, firstNumber)) {
        return true;
    }
    if (loadCharacter(input, sign)) {
        return true;
    }
    if (sign == '!')
        return false;
    if (loadNumber(input, secondNumber)) {
        return true;
    }
    if (input.size() > 0) {
        return true;
    }
    return false;
}

ErrorCode process(std::string input, double* out) {
    char sign;
    double firstNumber = 0;
    double secondNumber = 0;

    if (BadCharacter(input)) {
        return ErrorCode::BadCharacter;
    }
    if (BadFormat(input, firstNumber, secondNumber, sign)) {
        return ErrorCode::BadFormat;
    }
    if ((sign == '/') && (secondNumber == 0)) {
        return ErrorCode::DivideBy0;
    }

    if (sign == '%') {
        if ((is_not_integer(firstNumber)) || (is_not_integer(secondNumber))) {
            return ErrorCode::ModuleOfNonIntegerValue;
        }
    }
    if ((sign == '$') && (firstNumber < 0)) {
        return ErrorCode::SqrtOfNegativeNumber;
    }

    calculator_functions[sign](firstNumber, secondNumber, out);

    return ErrorCode::OK;
}
