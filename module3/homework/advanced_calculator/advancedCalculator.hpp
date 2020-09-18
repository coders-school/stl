#pragma once

enum class ErrorCode {
    Ok,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue,
};

void startCalculate();