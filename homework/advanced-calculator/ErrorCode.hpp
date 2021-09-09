#pragma once

enum class ErrorCode {
    OK,
    BadCharacter,             //a character other than a number
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue,
    OtherError                // additional for other than the above
};
