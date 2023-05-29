#include "sort.hpp"
#include <algorithm>
#include <deque>
#include <forward_list>
#include <functional>
#include <string>

std::deque<std::string> lengthSort(std::forward_list<std::string> words) {
    std::deque<std::string> sortedWords{words.begin(), words.end()};
    std::sort(sortedWords.begin(), sortedWords.end(), [](const auto& first, const auto& second) {
        if (first.length() == second.length()) {
            return first < second;
        }
        return first.length() < second.length();
    });
    return sortedWords;
}