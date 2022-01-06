#include "sort.hpp"

#include <algorithm>

// Returns std::deque with words sorted from the shortest to the longest or
// lexicographically if they have the same length.
// Takes words to sort
std::deque<std::string> lengthSort(const std::forward_list<std::string>& words)
{
    std::deque<std::string> result { words.begin(), words.end() };
    auto sorter = [](const auto& first, const auto& second) {
        // lexicographical compare for same length strings
        if (first.length() == second.length()) {
            return first < second;
        }

        return first.length() < second.length();
    };

    std::sort(result.begin(), result.end(), sorter);

    return result;
}