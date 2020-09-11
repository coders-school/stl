#pragma once

#include "formula.hpp"

#include <string>

class FormulaParser{
public:
    Formula formula;

    FormulaParser(std::string text) : text_(text){
        validateCharacters();
        parseText();
    }

private:
    void validateCharacters();
        bool hasValidCharacters();
        bool symbolIsValid(char symbol);

    void parseText();
        void trimSpaces();
        void parseTextIntoFormula();

private:
    std::string text_;
    const std::string VALID_CHARACTERS = "-+/*%!^$., 0123456789";
};
