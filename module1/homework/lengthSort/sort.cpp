#include "sort.hpp"

bool isFirstLess(const std::string& first, const std::string& second) {
    if (first.length() == second.length()) {
        return first < second;
    }
    return first.length() < second.length();
}

std::deque<std::string> lengthSort(std::forward_list<std::string> list) {
    list.sort(isFirstLess);
    return std::deque<std::string>(begin(list), end(list));
}