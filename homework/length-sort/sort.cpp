#include "sort.hpp"

bool compare(std::string a, std::string b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    return 0 > a.compare(b);
}

std::deque<std::string> lengthSort(std::forward_list<std::string>& unsortedList) {
    std::deque<std::string> sortedList{};
    unsortedList.sort(compare);

    for (auto it = unsortedList.begin(); it != unsortedList.end(); ++it)
        sortedList.push_back(*it);
    return sortedList;
}