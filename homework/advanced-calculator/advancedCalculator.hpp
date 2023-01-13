#pragma once

#include <functional>
#include <string>
#include <unordered_map>

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

struct HashForErrorCode {
    std::size_t operator()(ErrorCode const& s) const noexcept {
        return static_cast<std::size_t>(s);
    }
};

ErrorCode process(std::string, double*);
