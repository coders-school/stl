#include "sort.hpp"

#include <algorithm>

std::deque<std::string> lengthSort(std::forward_list<std::string>& words) {
    words.sort([](const std::string& first, const std::string& second) {
        if (first.length() == second.length()) {
            return first < second;
        } else {
            return first.length() <= second.length();
        }
    });

    return std::deque<std::string>{words.begin(), words.end()};
}