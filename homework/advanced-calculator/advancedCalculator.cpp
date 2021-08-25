#include "advancedCalculator.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>


bool is_not_integer(double number) {
    return std::floor(number) != number;
}

bool loadNumber(std::string& input, double& number) {
    size_t correct_symbol_position = 0;
    std::string set_of_numbers = "1234567890";
    size_t plus_position = 0;
    size_t number_position = 0;
    plus_position = input.find_first_of('+');
    if (plus_position != std::string::npos) {
        number_position = input.find_first_of(set_of_numbers);
        if (plus_position < number_position) {
            return true;
        }
    }
    try {
        number = stod(input, &correct_symbol_position);
        input.erase(0, correct_symbol_position);
    } catch (std::invalid_argument& e) {
        return true;
    }
    return false;
}

bool loadCharacter(std::string& input_without_the_first_number, char& operation_symbol) {
    std::string set_of_characters = "+-*/%!^$";
    std::string set_of_numbers = "1234567890.";
    size_t char_position = 0;
    size_t number_position = 0;
    char_position = input_without_the_first_number.find_first_of(set_of_characters);
    if (char_position != std::string::npos) {
        number_position = input_without_the_first_number.find_first_of(set_of_numbers);
        if (number_position < char_position) {
            return true;
        } else {
            operation_symbol = input_without_the_first_number[char_position];
            input_without_the_first_number.erase(0, char_position + 1);
            if ((operation_symbol == '!') && (input_without_the_first_number.size() > 0)) {
                return true;
            }
            return false;
        }
    } 
    // else {
        return true;
    }
// }

bool BadCharacter(const std::string& value) {
    std::string set_of_characters = "+-*/%!^$1234567890,. ";
    size_t it;
    it = value.find_first_not_of(set_of_characters);
    if (it != std::string::npos) {
        return true;
    }
    return false;
}

bool characterCountTest(const std::string& input) {
    std::string set_of_characters = "+*/%!^$";
    auto quantity_character = 0;
    for (size_t i = 0; i < set_of_characters.size(); i++) {
        auto character_counter = std::count(begin(input), end(input), set_of_characters[i]);
        quantity_character += character_counter;
        if (character_counter > 1) {
            return true;
        }
    }
    if (quantity_character > 1) {
        return true;
    }
    auto character_counter = std::count(begin(input), end(input), '.');
    if (character_counter > 2) {
        return true;
    }
    character_counter = std::count(begin(input), end(input), ',');
    if (character_counter > 0) {
        return true;
    }
    character_counter = std::count(begin(input), end(input), '-');
    if (character_counter > 3) {
        return true;
    }
    return false;
}

bool BadFormat(std::string input, double& firstNumber, double& secondNumber, char& operation_symbol) {
    if (characterCountTest(input)) {
        return true;
    }
    if (loadNumber(input, firstNumber)) {
        return true;
    }
    if (loadCharacter(input, operation_symbol)) {
        return true;
    }
    if (operation_symbol == '!')
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
    char operation_symbol;
    double firstNumber = 0;
    double secondNumber = 0;

    if (BadCharacter(input)) {
        return ErrorCode::BadCharacter;
    }
    if (BadFormat(input, firstNumber, secondNumber, operation_symbol)) {
        return ErrorCode::BadFormat;
    }
    if ((operation_symbol == '/') && (secondNumber == 0)) {
        return ErrorCode::DivideBy0;
    }

    if (operation_symbol == '%') {
        if ((is_not_integer(firstNumber)) || (is_not_integer(secondNumber))) {
            return ErrorCode::ModuleOfNonIntegerValue;
        }
    }
    if ((operation_symbol == '$') && (firstNumber < 0)) {
        return ErrorCode::SqrtOfNegativeNumber;
    }

    calculator_functions[operation_symbol](firstNumber, secondNumber, out);

    return ErrorCode::OK;
}
