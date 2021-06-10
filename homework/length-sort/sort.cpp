#include "sort.hpp"


bool compare_length(std::string& str1, std::string& str2) {
    if (str1.length() < str2.length() || str1.length() == str2.length() && str1 < str2) {
        return true;
    }
    return false;
}

std::deque<std::string> lengthSort(std::forward_list<std::string> flist) {
    std::deque<std::string> deq(flist.begin(), flist.end());
    std::sort(deq.begin(), deq.end(), compare_length);
    return deq;
}