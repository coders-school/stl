#include "textParser.hpp"
#include "calcExceptions.hpp"

#include <algorithm>


TextParser::TextParser(std::string text) : text_(text){
    checkAndPrepareText();
    parseTextAndValidateOutput();
}

void TextParser::checkAndPrepareText(){
    trimSpaces();
    validateCharacters();
}

void TextParser::trimSpaces(){
    text_.erase(std::remove(text_.begin(), text_.end(), ' '), text_.end());
}

void TextParser::validateCharacters(){
    if(!hasValidCharacters())
        throw BadCharacterException();
}

bool TextParser::hasValidCharacters(){
    return std::all_of(text_.begin(), text_.end(), 
        [&](char c){ return isdigit(c) || isSymbol(c) || c == '.'; });
};

bool TextParser::isSymbol(char c){
    return VALID_SYMBOLS.find(c) != std::string::npos;
}



void TextParser::parseTextAndValidateOutput(){
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
    symbol = getElement(2);
    numberOne = getElement(1);
    numberTwo = getElement(3);
}

std::string TextParser::getElement(size_t number){
    return elements_[number].str();
}

void TextParser::validateElements(){
    if(machIsValid() && (isStandard()  || isFactorial()))
        return;
    throw BadFormatException();
}

bool TextParser::machIsValid(){
    return match == text_;
}

bool TextParser::isStandard(){
    return !numberOne.empty() && !symbol.empty() && symbol != "!" && !numberTwo.empty();
}

bool TextParser::isFactorial(){
    return !numberOne.empty() && symbol == "!" && numberTwo.empty();
}
