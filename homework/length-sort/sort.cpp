#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string>& words) {
    words.sort([](const std::string& lhs, const std::string& rhs){
        if (lhs.size() == rhs.size()) {
            return lhs < rhs;
        }
        return lhs.size() < rhs.size();
    });
    std::deque<std::string> WordsInDeque(words.begin(), words.end());
    return WordsInDeque;
}
