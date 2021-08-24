#pragma once
#include <string>
#include <vector>
#include "Commands.hpp"
#include "ErrorCode.hpp"

struct Result;

void print_input(std::string input);

struct SeparatorFormat{
    constexpr static auto legal = '.';
    constexpr static auto illegal = ',';
    constexpr static auto negative = '-';
};

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

struct Parsing_Iterator {
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = Parsing_Iterator;
    using pointer = Parsing_Iterator*;
    using reference = Parsing_Iterator&;

    Parsing_Iterator() = default;

    enum State {
        number,
        operation,
    };

    Parsing_Iterator& operator=(const char& letter);

    reference operator*() { return *this; }
    pointer operator->() { return this; }
    Parsing_Iterator& operator++() { return *this; }

    Result getResult() {
        return Result(num, op, result);
    }

private:
    std::vector<std::string> num{};
    std::vector<char> op{};
    ErrorCode result{ErrorCode::OK};
    State state{operation};
};
