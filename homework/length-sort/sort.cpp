#include "sort.hpp"
bool sortB(const std::string& s1, const std::string& s2) {
    if (s1.length() < s2.length()) {
        return s1.length() < s2.length();
    } else if (s1.length() == s2.length()) {
        return s1 < s2;
    }
}

std::deque<std::string> lengthSort(const std::forward_list<std::string>& fl) {
    std::deque<std::string> deq;
    for (auto& el : fl) {
        deq.push_back(el);
    }
    // std::sort(deq.begin(), deq.end(), [](const std::string& s1, const std::string& s2) { return s1.length() < s2.length(); });
    std::sort(deq.begin(), deq.end(), sortB);
    return deq;
}
