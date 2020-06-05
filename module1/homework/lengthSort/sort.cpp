#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string>& fls) {
    std::deque<std::string> sorted_strings{};

    fls.sort();

    sorted_strings.insert(sorted_strings.cbegin(), fls.cbegin(), fls.cend());

    return sorted_strings;
}