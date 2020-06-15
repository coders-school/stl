#include "sort.hpp"

bool isFirstLess(const std::string &first, const std::string &second) {
    if (first.length() < second.size())
        return true;
    else if (first.length() == second.length()){
        for (auto i = 0; i< first.length(); ++i)
            if (first[i] < second[i])
                return true;
            else if (first[i] > second[i])
                return false;
    }
    return false;
}

std::deque<std::string> lengthSort(std::forward_list<std::string> list) {
    list.sort(isFirstLess);
    return std::deque<std::string>(begin(list), end(list));
}