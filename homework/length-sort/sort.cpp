#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string>& list) {
    std::deque<std::string> temp;

    list.sort();
    for(auto it = list.begin(); it != list.end(); ++it) {
        temp.push_back(*it);
    }

    std::sort(temp.begin(), temp.end(), []
    (const std::string& first, const std::string& second) {
        return first.size() < second.size();
    });

    return temp;
}