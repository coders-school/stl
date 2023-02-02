#include "sort.hpp"
std::deque<std::string> lengthSort(std::forward_list<std::string>& list) {
    std::deque<std::string> output;
    for (auto& el : list) {
        output.push_back(el);
    }
    std::sort(output.begin(), output.end(), [](std::string a, std::string b) {return a.size() < b.size(); });
    for (auto it = output.begin(); it != output.cend()-1; ++it) {
        auto it2 = it;
        auto str1 = *it;
        auto str2 = *it2;
        while (str1.size() == str2.size()) {
            ++it2;
            str2 = *it2;
        }
        std::sort(it, it2);
    }
    return output;
}