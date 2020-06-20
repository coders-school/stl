#include "sort.hpp"

#include <algorithm>
#include <iterator>

std::deque<std::string> lengthSort(std::forward_list<std::string> list) {
    std::deque<std::string> deq;
    list.sort([](const std::string& first, const std::string& second) {
        return (first.length() == second.length() ? first < second
                                                  : (first.length() < second.length()));
    });
    std::copy(list.begin(), list.end(), std::back_inserter(deq));

    return deq;
}
