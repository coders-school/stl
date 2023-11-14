#include "sort.hpp"
#include <utility>

std::deque<std::string> lengthSort(std::forward_list<std::string>& fl) {
    fl.sort([](const std::string& s1, const std::string& s2) {return std::make_pair(s1.size(), s1) < std::make_pair(s2.size(), s2);});
    return {fl.begin(), fl.end()};
}
