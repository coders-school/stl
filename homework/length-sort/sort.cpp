#include "sort.hpp"

bool compare(const std::string& x, const std::string& y) {
    if (x.length() == y.length()) {
        return std::lexicographical_compare(x.cbegin(), x.cend(), y.cbegin(), y.cend());
    } else {
        return (x.length() < y.length());
    }
}

std::deque<std::string> lengthSort(std::forward_list<std::string>& list) {
    std::deque<std::string> ret(std::distance(list.cbegin(), list.cend()));

    std::copy(list.cbegin(), list.cend(), ret.begin());
    std::sort(ret.begin(), ret.end(), compare);

    return ret;
}