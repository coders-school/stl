#include "transformContainers.hpp"

#include <algorithm>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& word1, std::deque<int>& num1) {
    word1.sort();
    std::sort(num1.begin(), num1.end());
    word1.erase(std::unique(word1.begin(), word1.end()), word1.end());
    num1.erase(std::unique(num1.begin(), num1.end()), num1.end());

    std::map<int, std::string> word2;
    std::transform(word1.begin(), word1.end(), num1.begin(), std::inserter(word2, word2.end()), [](const auto& word3, const int& num2) {
        return std::make_pair(num2, word3);
    });

    return word2;
}