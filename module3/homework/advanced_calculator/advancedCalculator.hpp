#include <string>
#include <regex>

struct BadFormatException : public std::invalid_argument{
	BadFormatException() : std::invalid_argument("BadFormat Exception"){};
};

struct BadCharacterException : public std::invalid_argument{
	BadCharacterException() : std::invalid_argument("BadCharacter Exception"){};
};

enum class ErrorCode{
    OK,
    BadFormat,
    BadCharacter,
    DivideBy0,
    ModuleOfNonIntegerValue,
    SqrtOfNegativeNumber,
};

ErrorCode process(std::string input, double* out);


const std::string validCharacters = "-+/*%!^$., 0123456789";
const std::string validSymbols = "-+/*%!^$";


struct Formula{
    double first;
    double second;
    char symbol;
};

class FormulaParser{
public:
    Formula formula;

    FormulaParser(std::string text) : text_(text){
        validateCharacters();
        parseText();
    }

private:
    void validateCharacters();
        bool hasValidCharacters();
        bool symbolIsValid(char symbol);

    void parseText();
        void trimSpaces();
        void parseTextIntoFormula();
        void readAndValidateElements(std::smatch elements);
        bool areElementsValid(std::smatch el);



private:
    std::string text_;

};

class FormulaProcess{

};
