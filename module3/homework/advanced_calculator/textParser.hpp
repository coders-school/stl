#pragma once

#include "formula.hpp"

#include <string>
#include <regex>

class TextParser{
public:
    TextParser(std::string text): text_(text){
        parse();
    }

    Formula getFormula() const { return formula_; }

private:
    void parse();
        void searchElements();
        void readElements();
            std::string getElement(size_t number);
        void validateElements();

        void castElements();
        void castToFormula();


private:
    std::string match;
    std::string symbol;
    std::string firstNumber;
    std::string secondNumber;

    Formula formula_;

    std::string text_;
    std::smatch elements_;

    const std::string VALID_SYMBOLS = "-+/*%!^$";
    const std::string NUMBER_PATTERN = "(-?\\d*\\.?\\d*)";
    const std::string SYMBOL_PATTERN = "([" + VALID_SYMBOLS + "])";
};
