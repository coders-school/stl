#include "advancedCalculator.hpp"
#include "formulaParser.hpp"
#include "calculatorExceptions.hpp"

#include <iostream>
#include <map>
#include <functional>
#include <math.h>

using FunctionMap = std::map<char, std::function<double(double,double)>>;

// double addition(double a, double b){
//     return a + b;
// }
// double substraction(double a, double b){
//     return a - b;
// }
// double multiplication(double a, double b){
//     return a * b;
// }

double division(double a, double b){
    if(b == 0)
        throw DivideBy0Exception();
    return a / b;
}

double factorial(double a, double b){
    if(b != 0)
        throw BadFormatException();
    return a;
}

double power(double a, double b){
    return pow(a,b);
}

double squareRoot(double a, double b){
    if(a < 0)
        throw SqrtOfNegativeNumberException();
    return pow(a, 1 / b);
}

double modulo(double a, double b){
    return fmod(a,b);
}

FunctionMap functions{
        {'+', std::plus<double>()},
        {'-', std::minus<double>()},
        {'*', std::multiplies<double>()},
        {'/', division},
        {'!', factorial},
        {'^', power},
        {'$', squareRoot},
        {'%', modulo}
    };


class FormulaProcessor{
public:
    FormulaProcessor(FormulaParser & fp) : formula_(fp.formula){
        process();
    }

    double getValue() const {
        return value_;
    }

private:
    void process(){
        value_ = functions[formula_.symbol](formula_.first, formula_.second);
    }

private:
    Formula & formula_;
    double value_;

    
};


ErrorCode process(std::string input, double* out){
    try{
        FormulaParser fp(input);
        FormulaProcessor fpr(fp);
        *out = fpr.getValue();

    } catch (const BadFormatException e) {
        return ErrorCode::BadFormat;
    } catch (const BadCharacterException e) {
        return ErrorCode::BadCharacter;
    } catch (const DivideBy0Exception e) {
        return ErrorCode::DivideBy0;
    } catch (const SqrtOfNegativeNumberException e) {
        return ErrorCode::SqrtOfNegativeNumber;
    } catch (const ModuleOfNonIntegerValueException e) {
        return ErrorCode::ModuleOfNonIntegerValue;
    }
    return ErrorCode::OK;
}

