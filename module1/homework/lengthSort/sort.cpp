#include "sort.hpp"


std::deque<std::string> lengthSort(std::forward_list<std::string>& strings) {
    std::deque<std::string> sorted_strings{};

    strings.sort();

    sorted_strings.insert(sorted_strings.cbegin(), strings.cbegin(), strings.cend());

    return sorted_strings;
}
