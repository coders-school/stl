#include "sort.hpp"

std::deque<std::string> lengthSort(const std::forward_list<std::string>& list_words) {
    static constexpr auto compare = [](const std::string& str1, const std::string& str2) {
        if (str1.size() == str2.size())
            return str1 < str2;
        return str1.size() < str2.size();
    };

    std::deque<std::string> deque{list_words.cbegin(), list_words.cend()};
    std::sort(deque.begin(), deque.end(), compare);
    return deque;
}