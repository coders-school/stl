#pragma once
#include <string>
#include "SeparatorFormat.hpp"
#include "Types.hpp"

struct Result {
    Result(const std::vector<std::string>& args, const std::vector<char>& op);

    CalculationResult invoke(const CommandsMap& commands) const;

private:
    void print_op() const;
    void print_args() const;
    void print_error() const;

    Numbers numbers;
    std::vector<char> op;
    mutable ErrorCode errorCode = ErrorCode::OK;
};
