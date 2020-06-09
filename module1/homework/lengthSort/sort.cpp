#include "sort.hpp"

std::deque<std::string> sort(std::forward_list<std::string> sortMe) {
    sortMe.sort([](const std::string& lhs, const std::string& rhs) {
        if (lhs.length() == rhs.length()) {
            return lhs <= rhs;
        }

        return lhs.length() <= rhs.length();
    });
    std::deque<std::string> result(sortMe.begin(), sortMe.end());
    return result;
}
