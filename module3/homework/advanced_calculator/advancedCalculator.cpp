#include "advancedCalculator.hpp"
#include <algorithm>
#include <stdexcept>
#include <regex>
#include <iostream>





void FormulaParser::validateCharacters(){
    if(!hasValidCharacters())
        throw BadCharacterException();
}

bool FormulaParser::hasValidCharacters(){
    return std::all_of(text_.begin(), text_.end(), 
        [&](char symbol){ return symbolIsValid(symbol); });
};

bool FormulaParser::symbolIsValid(char symbol){
    return validCharacters.find(symbol) != std::string::npos;
}

void FormulaParser::parseText(){
    trimSpaces();
    parseTextIntoFormula();
}

void FormulaParser::trimSpaces(){
    text_.erase(std::remove(text_.begin(), text_.end(), ' '), text_.end());
}

void FormulaParser::parseTextIntoFormula(){
    std::string numberGroupPattern = "(-?\\d*\\.?\\d*)";
    std::string symbolGroupPattern = "([" + validSymbols + "])";
    std::regex formulaPattern(numberGroupPattern + symbolGroupPattern + numberGroupPattern);
    std::smatch formulaElements;

    bool found = std::regex_search(text_, formulaElements, formulaPattern);
    if(!found || !areElementsValid(formulaElements))
        throw BadFormatException();

    readAndValidateElements(formulaElements);

}

bool FormulaParser::areElementsValid(std::smatch el){
    bool lengthValid = el[0].length() == text_.length();
    bool sizeValid = el.size() == 4;
    bool elementsNotEmpty = el[1].length() != 0 
                         && el[2].length() != 0 
                         && el[3].length() != 0;
    return lengthValid && sizeValid && elementsNotEmpty;
}

void FormulaParser::readAndValidateElements(std::smatch elements){
    std::string firstNumber = elements[1];
    std::string symbol = elements[2];
    std::string secondNumber = elements[3];

    std::cout << elements[0] << "\n";

    formula.first = std::stod(firstNumber);
    formula.second = std::stod(secondNumber);
    formula.symbol = symbol[0];
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

