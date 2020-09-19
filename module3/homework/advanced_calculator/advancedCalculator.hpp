#pragma once
#include <functional>
#include <map>
#include <string>

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue,
};

enum class Action {
    Calculate,
    Help,
    Exit,
};

void startCalculate();
void printWelcomeScreen();
void mainLoop();
void makeAction(Action choice);
void printHelp();
void printGoodByeScreen();

bool isComma(const char input);
bool isBadCharacter(std::string input);
bool isBadFormat(std::string input);
bool isDivideBy0(std::string input);
bool isSqrtOfNegativeNumber(std::string input);
bool isModuleOfNonIntegerValue(std::string input);

ErrorCode process(std::string input, double* out);
