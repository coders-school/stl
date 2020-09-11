#include "advancedCalculator.hpp"
#include "formulaParser.hpp"
#include "calculatorExceptions.hpp"

#include <iostream>


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

