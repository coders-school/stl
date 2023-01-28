#include "sort.hpp"

std::deque<std::string> lengthSort(const std::forward_list<std::string>& fl) {
    std::deque<std::string> dq;

    for (auto& i : fl) {
        dq.emplace_back(i);
    }

    std::sort(dq.begin(), dq.end(), [](const std::string& a, const std::string& b) {
        if (a.length() == b.length()) {
            return a < b;
        }
        return a.length() < b.length();
    });

    return dq;
}