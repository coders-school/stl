#include "sort.hpp"

bool LexCompare(const std::string& a, const std::string& b) {
    return std::lexicographical_compare(a.begin(), a.end(),
                                        b.begin(), b.end());
}

bool LengthCompare(const std::string& a, const std::string& b) {
    return a.length() < b.length();
}

std::deque<std::string> lengthSort(std::forward_list<std::string>& words) {
    std::deque<std::string> sortedWords;

    words.sort(LexCompare);
    words.sort(LengthCompare);

    std::copy(words.begin(), words.end(), std::back_inserter(sortedWords));

    return sortedWords;
}
