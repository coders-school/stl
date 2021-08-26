#include "Parsing_iterator.hpp"
#include <iostream>

Parsing_Iterator& Parsing_Iterator::operator=(const char& letter) {
    if (std::iswspace(letter)) {  //ignore white spaces
        return (*this);
    }

    if (letter == SeparatorFormat::negative) {
        if (state == operation) {  //minus as new number
            num.push_back({});
            num.back() += letter;
            state = number;
        } else {  //minus as new operator
            op.push_back(letter);
            state = operation;
        }
        return (*this);
    }

    if (!std::isdigit(letter) && letter != SeparatorFormat::legalOnce) {  //new operator
        op.push_back(letter);
        state = operation;
        return (*this);
    }

    if (state == operation) {  //new number
        num.push_back({});
        state = number;
    }
    num.back() += letter;  //add letter to current number
    return (*this);
}

Result Parsing_Iterator::getResult() {
    return Result(num, op);  //Result can invoke calculations and have all needed data
}
