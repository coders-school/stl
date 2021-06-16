#include "sort.hpp"

std::deque<std::string> lengthSort(const std::forward_list<std::string> &words) {
    std::deque<std::string> sorted;
    for (auto word : words) {
        sorted.push_back(word);
    }
    for (size_t i = 0; i < sorted.size()-1; ++i) {
        for (size_t j = 0; j < sorted.size()-i-1; ++j) {
            if (sorted[j].size() > sorted[j+1].size()) {
                swap(sorted[j], sorted[j+1]);
            }
            if (sorted[j].size() == sorted[j+1].size() && sorted[j] > sorted[j+1]) {
                swap(sorted[j], sorted[j+1]);
            }
        }
    }
    return sorted;
};