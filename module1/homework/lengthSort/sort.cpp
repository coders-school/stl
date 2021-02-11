#include "sort.hpp"

bool lessSize(const std::string& first, const std::string&  last) {
    if (first.size() == last.size()) {
        return std::lexicographical_compare(first.begin(), first.end(), last.begin(), last.end());
    }
    return first.size() < last.size();
}

std::deque<std::string> lengthSort(std::forward_list<std::string>& list) {
    std::deque<std::string> result;
    std::copy(list.begin(), list.end(), std::back_inserter(result));
    std::sort(result.begin(), result.end(), lessSize);

    return result;
}