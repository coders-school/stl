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
void makeAction();
void printHelp();
void printGoodByeScreen();

ErrorCode process(std::string input, double* out);
