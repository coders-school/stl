#include "sort.hpp"

#include <algorithm>

std::deque<std::string> lengthSort(const std::forward_list<std::string>& listToSort) {
    std::deque<std::string> output{begin(listToSort), end(listToSort)};

    std::sort(begin(output), end(output), [](const std::string& s1, const std::string& s2) {
        if (s1.length() == s2.length()) {
            return s1 < s2;
        }
        return s1.length() < s2.length();
    });

    return output;
}
