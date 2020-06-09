#include "sort.hpp"

#include <algorithm>

std::deque<std::string> lengthSort(const std::forward_list<std::string>& words) {
    std::deque<std::string> sortedWords;

    std::transform(begin(words), end(words), begin(sortedWords), [](const auto& first, const auto& second) {
        return first.length() == second.length() ? first < second : first.length() < second.length();
    });

    return sortedWords;
}
