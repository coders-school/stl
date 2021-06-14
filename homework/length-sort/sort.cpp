#include "sort.hpp"
#include <deque>
#include <string>
#include <forward_list>



std::deque<std::string> lengthSort(std::forward_list<std::string>& words) {
    std::deque<std::string> dec;
    auto compare = [](auto lhs, auto rhs) {
        if (lhs.size() == rhs.size()) {
            return lhs < rhs;
        }
        return lhs.size() < rhs.size();
        };

    words.sort(compare);
    
    for (const auto& word: words) {
        dec.push_back(word);
    }
    return dec;
}
