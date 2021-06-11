#include "sort.hpp"

bool compare(std::string x, std::string y) {
    if (x.length() == y.length()) {
        return std::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
    } else {
        return (x.length() < y.length());
    }
}

std::deque<std::string> lengthSort(std::forward_list<std::string>& list) {
    std::deque<std::string> ret(std::distance(list.begin(), list.end()));

    std::copy(list.begin(), list.end(), ret.begin());
    std::sort(ret.begin(), ret.end(), compare);
    
    return ret;
}