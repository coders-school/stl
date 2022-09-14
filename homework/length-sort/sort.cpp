#include "sort.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <set>

struct StringLengthComparer {
    bool operator()(std::string left, std::string right) const {
        return left.length() < right.length();
    }
};

using StringMultiset = std::multiset<std::string, StringLengthComparer>;

StringMultiset sort_by_lenght(std::forward_list<std::string> arr) {
    return StringMultiset{arr.begin(), arr.end()};
}

std::deque<std::string> lengthSort(std::forward_list<std::string> fwdL) {
    fwdL.sort();
    auto ms = sort_by_lenght(fwdL);
    std::deque<std::string> ds(ms.begin(), ms.end());
    return ds;
}
