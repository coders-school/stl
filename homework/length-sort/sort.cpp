#include "sort.hpp"

#include <cstring>

bool compareWords(const std::string& word1, const std::string& word2) {
    bool result = false;
    if (word1.size() < word2.size()) {
        result = true;
    } else if (word1.size() > word2.size()) {
        result = false;
    } else {
        if (std::strcmp(word1.c_str(), word2.c_str()) < 0) {
            result = true;
        } else {
            result = false;
        }
    }
    return result;
}

std::deque<std::string> lengthSort(const std::forward_list<std::string>& words) {
    std::deque<std::string> result;
    for (const auto& word : words) {
        result.push_back(word);
    }
    for (int i = 1; i < result.size(); i++) {
        std::string word = result[i];
        int j = i - 1;
        while (j >= 0 && compareWords(word, result[j])) {
            result[j + 1] = result[j];
            j--;
        }
        result[j + 1] = word;
    }
    return result;
}
