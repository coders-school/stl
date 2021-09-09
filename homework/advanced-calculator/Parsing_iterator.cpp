#include "Parsing_iterator.hpp"
#include <cwctype> //for iswspace

Parsing_Iterator& Parsing_Iterator::operator=(const char& letter) {
    if (std::iswspace(letter)) {  //ignore white spaces
        return (*this);
    }

    if (letter == SeparatorFormat::negative) {
        if (state_ == operation) {  //minus as new number
            num_.push_back({});
            num_.back() += letter;
            state_ = number;
        } else {  //minus as new operator
            op_.push_back(letter);
            state_ = operation;
        }
        return (*this);
    }

    if (!std::isdigit(letter) && letter != SeparatorFormat::legalOnce) {  //new operator
        op_.push_back(letter);
        state_ = operation;
        return (*this);
    }

    if (state_ == operation) {  //new number
        num_.push_back({});
        state_ = number;
    }
    num_.back() += letter;  //add letter to current number
    return (*this);
}

Result Parsing_Iterator::getResult() {
    return Result(num_, op_);  //Result can invoke calculations and have all needed data
}
