#include "advancedCalculator.hpp"
#include <algorithm>
#include <stdexcept>
#include <regex>
#include <iostream>


void TextParser::parse(){
    searchElements();
    readElements();
    validateElements();
}

void TextParser::searchElements(){
    std::regex formulaPattern(NUMBER_PATTERN + SYMBOL_PATTERN + NUMBER_PATTERN);
    bool foundMatch = std::regex_search(text_, elements_, formulaPattern);

    if(!foundMatch)
        throw BadFormatException();
}

void TextParser::readElements(){
    match = getElement(0);
    firstNumber = getElement(1);
    symbol = getElement(2);
    secondNumber = getElement(3);
}

std::string TextParser::getElement(size_t number){
    return elements_[number].str();
}

bool TextParser::validateElements(){
    if(match != text_ || firstNumber.empty() || symbol.empty())
        throw BadFormatException();
}

void TextParser::castToFormula(){
    formula_.first = std::stod(firstNumber);
    formula_.second = std::stod(secondNumber);
    formula_.symbol = symbol[0]; 
}



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

ErrorCode process(std::string input, double* out){
    try{
        FormulaParser fp(input);
        *out = fp.formula.first + fp.formula.second;
    } catch (const BadFormatException e) {
        return ErrorCode::BadFormat;
    } catch (const BadCharacterException e) {
        return ErrorCode::BadCharacter;
    }
    return ErrorCode::OK;
}

