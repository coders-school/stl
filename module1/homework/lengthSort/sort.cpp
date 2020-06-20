#include "sort.hpp"

#include <algorithm>
#include <iterator>

bool comparator(const std::string& firstString, const std::string& secondString) {
    return (firstString.size() == secondString.size() ? firstString < secondString
                                                      : (firstString.size() < secondString.size()));
}

std::deque<std::string> lengthSort(std::forward_list<std::string> list) {
    list.sort(comparator);
    std::deque<std::string> deq;
    std::copy(list.begin(), list.end(), std::back_inserter(deq));

    return deq;
}