#include "advancedCalculator.hpp"

std::map<char, std::function<double(double, double)>> operations =
{
    {'+', [](double a, double b) -> double {return a + b;}},
    {'-', [](double a, double b) -> double {return a - b;}},
    {'*', [](double a, double b) -> double {return a * b;}},
    {'/', [](double a, double b) -> double {return a / b;}},
    {'%', [](double a, double b) -> double {return int(a) % int(b);}},
    {'^', [](double a, double b) -> double {return std::pow(a, b);}},
    {'$', [](double a, double b) -> double {return std::pow(a, 1 / b);}},
    {'!', [](const double & x, const double & y)
        { 
            if (x >=0) {
                return std::tgamma(x+1);
            }
            return -std::tgamma(-x+1);
        }}
};

bool isGoodCharacter(std::string inString)
{
    char character = inString[0];
    bool goodCharOccured = false;
    std::string goodChars = {"+-*/%^$!"};
    std::for_each(goodChars.begin(), goodChars.end(), [&character, &goodCharOccured](char a)
        {if(a == character) goodCharOccured = true;});
    return goodCharOccured;
}
bool isBadCharacter(std::string inString)
{
    std::string badChars = "#@&?\\[]=;qQ";
    if(std::find_first_of(badChars.begin(), badChars.end(), inString.begin(), inString.end()) != badChars.end())
    {
        return 1;
    }
    return 0;
}

ErrorCode parse(std::string input, parsedText & parsedText)
{
    std::string inputCp = input.substr(1);
    size_t pos = inputCp.find_first_of("+-*/%^$!");
    if( pos > inputCp.size()) return ErrorCode::BadFormat;

    parsedText[0] = input.substr(0, pos+1);
    parsedText[1] = input.substr(pos+1, 1);
    parsedText[2] = input.substr(pos+2, input.size());
    return ErrorCode::OK;
}

std::string cleanFromSpaces(const std::string & str)
{
    std::string tmp;
    std::copy_if(str.begin(), str.end(), std::back_inserter(tmp), [](char a){return a != ' ';});
    return tmp;
}

ErrorCode parsedTextMakeSens(parsedText & parsedText)
{
    if( !isGoodCharacter(parsedText[1])) return ErrorCode::BadFormat;
    if( !canBeDouble(parsedText[0])) return ErrorCode::BadFormat;
    if( !canBeDouble(parsedText[2])) return ErrorCode::BadFormat;
    if( (parsedText[1] == "!") && (parsedText[2] != "")) return ErrorCode::BadFormat;
    if( parsedText[1] == "/")
    {
        auto denominator = std::stod(parsedText[2]);
        if( denominator == 0) return ErrorCode::DivideBy0;
    }
    if( parsedText[1] == "%")
    {
        auto val1 = std::stod(parsedText[0]);
        auto val2 = std::stod(parsedText[2]);
        int val1Int = (int)val1;
        int val2Int = (int)val2;
        if( ((double)(val1 - val1Int) != 0) || ((double)(val2 - val2Int) != 0) ) 
        return ErrorCode::ModuleOfNonIntegerValue;
    }
    if( parsedText[1] == "$")
    {
        auto val1 = std::stod(parsedText[0]);
        auto val2 = std::stod(parsedText[2]);
        if( (val1 < 0) ) return ErrorCode::SqrtOfNegativeNumber;// || (val2 < 0)
    }
    return ErrorCode::OK;
}

bool canBeDouble(std::string str)
{
    int dotCounter = 0;
    bool canBeDouble = true;
    std::for_each(str.begin(), str.end(), [&dotCounter, &canBeDouble](char a)mutable
    {
        if( !(isdigit(a) or (a == '.') or (a == '-')) ){
            canBeDouble = false;
        }
        if(a == '.'){
            dotCounter++;
        }
    });
    if ( (dotCounter <= 1) && canBeDouble) return true;
    else return false;
}

dataAsDigits prepareData(const parsedText & parsedText)
{
    dataAsDigits ret;
    ret.a = std::stod(parsedText[0]);
    ret.ch = parsedText[1][0];
    if(ret.ch != '!'){
        ret.b = std::stod(parsedText[2]);
    }
    return ret;
}

ErrorCode process(std::string input, double* out)
{
    if( isBadCharacter(input) ) return ErrorCode::BadCharacter;

    parsedText parsedText;
    auto error = parse(cleanFromSpaces(input), parsedText);
    if( error != ErrorCode::OK) return error;
    
    error = parsedTextMakeSens(parsedText);
    if( error != ErrorCode::OK) return error;

    dataAsDigits inputAsDigits = prepareData(parsedText);
    compute(inputAsDigits, out);
    return ErrorCode::OK;
}

void compute(dataAsDigits dataIn, double* out)
{
        *out = operations[dataIn.ch](dataIn.a, dataIn.b) ;
}

