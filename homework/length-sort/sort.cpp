#include "sort.hpp"
#include <algorithm>
#include <deque>
#include <forward_list>
#include <string>

bool compareLength(std::string s1, std::string s2) {
    if (s1.length() < s2.length())
        return true;
    if ((s1.length() == s2.length()) && (s1 < s2))
        return true;
}
std::deque<std::string> lengthSort(std::forward_list<std::string> container_forward_list) {
    container_forward_list.sort(compareLength);
    std::deque<std::string> container_deque(container_forward_list.begin(), container_forward_list.end());
    return container_deque;
}