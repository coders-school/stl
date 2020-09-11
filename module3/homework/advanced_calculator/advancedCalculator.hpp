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




struct Formula{
    double first;
    double second;
    char symbol;
};

class TextParser{
public:
    TextParser(std::string text): text_(text){
        parse();
    }

    Formula getFormula() const { return formula_; }

private:
    void parse();
    void searchElements();
    void readElements();
    std::string getElement(size_t number);
    bool validateElements();

    void castToFormula();


private:
    std::string match;
    std::string symbol;
    std::string firstNumber;
    std::string secondNumber;

    Formula formula_;

    std::string text_;
    std::smatch elements_;

    const std::string VALID_SYMBOLS = "-+/*%!^$";
    const std::string NUMBER_PATTERN = "(-?\\d*\\.?\\d*)";
    const std::string SYMBOL_PATTERN = "([" + VALID_SYMBOLS + "])";
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
  


private:
    std::string text_;
    const std::string VALID_CHARACTERS = "-+/*%!^$., 0123456789";
};

class FormulaProcess{

};
