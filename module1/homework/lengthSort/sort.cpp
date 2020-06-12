#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string>& words) {
    words.sort([](const std::string& lhs, const std::string& rhs) {
        if (lhs.size() != rhs.size()) {
            return lhs.size() < rhs.size();
        }
        return lhs < rhs;
    });

    return std::deque<std::string>{ words.begin(), words.end() };
}
