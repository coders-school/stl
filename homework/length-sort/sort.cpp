#include "sort.hpp"

bool cmp(const std::string& a, const std::string& b) {
    if (a.length() == b.length()) {
        return a < b;
    }

    return a.length() < b.length();
}
std::deque<std::string> lengthSort(std::forward_list<std::string> collection) {
    collection.sort(cmp);

    std::deque<std::string> dq;

    while (!collection.empty()) {
        dq.push_back(collection.front());

        collection.pop_front();
    }

    return dq;
}
