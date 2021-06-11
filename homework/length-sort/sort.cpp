#include "sort.hpp"
#include <algorithm>

std::deque<std::string> lengthSort(const std::forward_list<std::string>& wordsList) {
    std::deque<std::string> result;
    for (const auto& word : wordsList) {
        result.push_back(word);
    }

    auto byLenghtThenLexical = [](const std::string& lhs, const std::string& rhs) {
        auto lhsSize = lhs.size();
        auto rhsSize = rhs.size();
        if (lhsSize == rhsSize) {
            return lhs <= rhs;
        }
        return lhsSize <= rhsSize;
    };

    std::sort(begin(result), end(result), byLenghtThenLexical);
    return result;
}
