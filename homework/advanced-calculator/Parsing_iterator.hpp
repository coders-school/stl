#pragma once
#include <string>
#include <vector>
#include "Result.hpp"

//will parse chars to numbers or operations containers
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

    Result getResult();

private:
    std::vector<std::string> num{};
    std::vector<char> op{};
    State state{operation};
};