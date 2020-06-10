#include "sort.hpp"

bool stringCompare(const std::string& first, const std::string& second) {
    size_t first_len = first.length();
    size_t second_len = second.length();
    if (first_len == second_len) {
        return first < second;
    }
    return first_len < second_len;
}

/* 
   I really think we need copy here, just because Command Query separation principle.
*/

std::deque<std::string> lengthSort(std::forward_list<std::string>& fwdList) {
    fwdList.sort(stringCompare);
    return std::deque<std::string>{fwdList.begin(), fwdList.end()};
}
