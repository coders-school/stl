#include "sort.hpp"
#include <algorithm>

std::deque<std::string> lengthSort(const std::forward_list<std::string>& list) {
    std::deque<std::string> words;

    std::copy(list.begin(), list.end(), std::back_inserter(words));
    std::sort(words.begin(), words.end(), [](const std::string& first, const std::string& second){
            if(first.size() == second.size()) {
                return first < second;
            } else {
                return first.size() < second.size();
            }
    });

    return words;
}
