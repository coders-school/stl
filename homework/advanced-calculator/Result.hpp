#pragma once
#include "Commands.hpp"
#include <string>
#include "SeparatorFormat.hpp"

struct Result {
    Result(const std::vector<std::string>& args, const std::vector<char>& op, ErrorCode err);
    CalculationResult invoke();

private:
    void print_op();
    void print_args();
    void print_error();

    Numbers numbers;
    std::vector<char> op;
    ErrorCode errorCode;
};
