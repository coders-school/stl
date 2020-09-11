#include "textParser.hpp"
#include "calculatorExceptions.hpp"

void TextParser::parse(){
    searchElements();
    readElements();
    validateElements();
    castElements();
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

void TextParser::validateElements(){
    if(match != text_ || firstNumber.empty() || symbol.empty())
        throw BadFormatException();
}

//move it to formulaParser??
void TextParser::castElements() 
try{
    castToFormula();
} catch (std::logic_error &){
    throw BadFormatException();
}

//move it to formulaParser??
void TextParser::castToFormula(){
    formula_.first = std::stod(firstNumber);
    formula_.second = std::stod(secondNumber);
    formula_.symbol = symbol[0]; 
}
