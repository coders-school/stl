#pragma once

#include <string>
#include <regex>

class TextParser{
public:
    TextParser(std::string text);

private:
    void checkAndPrepareText();
        void trimSpaces();
        void validateCharacters();
        bool hasValidCharacters();
            bool isSymbol(char c);

private:
    void parseTextAndValidateOutput();
        void searchElements();
        void readElements();
            std::string getElement(size_t number);

        void validateElements();
            bool machIsValid();
            bool isStandard();
            bool isFactorial();

public:
    std::string match;
    std::string symbol;
    std::string numberOne;
    std::string numberTwo;

private:
    std::string text_;
    std::smatch elements_;

private:
    const std::string VALID_SYMBOLS = "-+/*%!^$";
    const std::string NUMBER_PATTERN = "(-?\\d*\\.?\\d*)";
    const std::string SYMBOL_PATTERN = "([" + VALID_SYMBOLS + "])";
};
