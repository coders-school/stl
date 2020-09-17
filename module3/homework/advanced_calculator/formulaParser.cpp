#include "formulaParser.hpp"
#include "textParser.hpp"
#include "calcExceptions.hpp"


FormulaParser::FormulaParser(std::string text){
    TextParser tp(text);
    castIntoValues(tp);
}

void FormulaParser::castIntoValues(TextParser & tp) try{
    castParsedElementsIntoValues(tp);
} catch (std::logic_error &){
    throw BadFormatException();
}

void FormulaParser::castParsedElementsIntoValues(TextParser & tp){
    symbol = tp.symbol[0]; 
    numberOne = std::stod(tp.numberOne);
    if(tp.numberTwo.empty())
        return;
    numberTwo = std::stod(tp.numberTwo);
}



