#include "sort.hpp"

#include <algorithm>

std::deque<std::string> lengthSort(const std::forward_list<std::string>& words)
{
    std::deque<std::string> result(words.begin(), words.end());

    const auto comparator = [](const std::string& lhs, const std::string& rhs) {
        if (lhs.size() == rhs.size()) {
            return lhs < rhs;
        }
        return lhs.size() < rhs.size();
    };

    std::sort(result.begin(), result.end(), comparator);
    return result;
}
