#include "sort.hpp"

#include <algorithm>

struct StrCompare {
    bool operator()(const std::string& str1, const std::string& str2) {
        if (str1.size() == str2.size()) {
            return str1 < str2;
        }
        return str1.size() < str2.size();
    }
};

std::deque<std::string> lengthSort(std::forward_list<std::string> inputList) {
    inputList.sort(StrCompare());
    std::deque<std::string> result;
    for (const auto el : inputList)
        result.push_back(el);

    return result;
}
