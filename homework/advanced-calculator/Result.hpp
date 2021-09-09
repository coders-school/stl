#pragma once
#include <string>
#include "SeparatorFormat.hpp"
#include "Types.hpp"

struct Result {
public:
    Result(const std::vector<std::string>& args, const std::vector<char>& op);

    CalculationResult invoke(const CommandsMap& commands) const;

private:
    Numbers numbers_;
    std::vector<char> op_;
    ErrorCode errorCode_ = ErrorCode::OK;
};
