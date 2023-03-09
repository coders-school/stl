#include "sort.hpp"

auto lengthSort(std::forward_list<std::string>& list) -> std::deque<std::string> {
    std::deque<std::string> result;

    for (auto& word : list) {
        if (result.empty()) {
            result.push_back(word);
        } else {
            auto it = result.begin();
            while (it != result.end() && (word.size() > it->size() || (word.size() == it->size() && word > *it))) {
                ++it;
            }
            result.insert(it, word);
        }
    }
    return result;
}