#pragma once

#include "textParser.hpp"

#include <string>

class FormulaParser{
public:
    FormulaParser(std::string text);

private:
    void castIntoValues(TextParser & tp);
    void castParsedElementsIntoValues(TextParser & tp);

public:
    char symbol;
    double numberOne;
    double numberTwo;
};
