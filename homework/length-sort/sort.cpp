#include "sort.hpp"

bool lessSize(const std::string& first, const std::string& last) {
    if (first.size() == last.size()) {
        return std::lexicographical_compare(first.begin(), first.end(), last.begin(), last.end());
    }
    return first.size() < last.size();
}
std::deque<std::string> lengthSort(const std::forward_list<std::string>& words) {
    std::deque<std::string>  sorttmp;

    return  sorttmp;
};
