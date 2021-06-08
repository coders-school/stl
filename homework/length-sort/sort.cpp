#include "sort.hpp"

bool round_sort(std::string a, std::string b) {
    if (a.size() < b.size())
        return true;
    if ((a.size() == b.size()) && (a < b))
        return true;
    else
        return false;
}

std::deque<std::string> lengthSort(const std::forward_list<std::string>& list) {
    std::deque<std::string> round(list.begin(), list.end());
    sort(round.begin(), round.end(), round_sort);

    return round;
}
