#include "advancedCalculator.hpp"
#include "formulaParser.hpp"
#include "calculatorExceptions.hpp"

#include <iostream>

class FormulaProcess{
public:
    FormulaProcess(Formula & formula) : formula_(formula){
        process();
    }

private:
    void process(){
        
    }

private:
    Formula & formula_;
};


ErrorCode process(std::string input, double* out){
    try{
        FormulaParser fp(input);
        if(fp.formula.second != 0 && fp.formula.symbol == '!')
            throw BadFormatException();
            
        *out = fp.formula.first + fp.formula.second;

    } catch (const BadFormatException e) {
        return ErrorCode::BadFormat;
    } catch (const BadCharacterException e) {
        return ErrorCode::BadCharacter;
    }
    return ErrorCode::OK;
}

