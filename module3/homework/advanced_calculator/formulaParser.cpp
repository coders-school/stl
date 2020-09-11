#include "formulaParser.hpp"
#include "textParser.hpp"
#include "calculatorExceptions.hpp"

#include <algorithm>

void FormulaParser::validateCharacters(){
    if(!hasValidCharacters())
        throw BadCharacterException();
}

bool FormulaParser::hasValidCharacters(){
    return std::all_of(text_.begin(), text_.end(), 
        [&](char symbol){ return symbolIsValid(symbol); });
};

bool FormulaParser::symbolIsValid(char symbol){
    return VALID_CHARACTERS.find(symbol) != std::string::npos;
}

void FormulaParser::parseText(){
    trimSpaces();
    parseTextIntoFormula();

    if(formula.second != 0 && formula.symbol == '!')
        throw BadFormatException();

}

void FormulaParser::trimSpaces(){
    text_.erase(std::remove(text_.begin(), text_.end(), ' '), text_.end());
}

void FormulaParser::parseTextIntoFormula(){
    TextParser tp(text_);
    formula = tp.getFormula();
}