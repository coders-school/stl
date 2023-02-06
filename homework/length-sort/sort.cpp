#include "sort.hpp"
#include <algorithm>
#include <string>

std::deque<std::string> lengthSort(std::forward_list<std::string> fli) {
    std::deque<std::string> deq;
    fli.sort();

    for (auto it = fli.begin(); it != fli.end(); ++it) {
        deq.emplace_back(*it);
    }
    return deq;
}