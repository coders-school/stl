#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string> listOfStrings) {
    std::vector<std::string> vec;
    std::deque<std::string> resDeq;
    for (auto& it : listOfStrings) {
        vec.push_back(it);
    }

    for (auto& it : vec) {
        for (auto& iter : vec) {
            if (it.length() < iter.length()) {
                std::swap(it, iter);
            }
        }
    }

    for (auto& it : vec) {
        for (auto& iter : vec) {
            if (it.length() == iter.length()) {
                if (it < iter) {
                    std::swap(iter, it);
                }
            }
        }
    }

    for (auto& it : vec) {
        resDeq.push_back(it);
    }

    return resDeq;
}