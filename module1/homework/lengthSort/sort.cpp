#include "sort.hpp"

#include <algorithm>

std::deque<std::string> lengthSort(std::forward_list<std::string> &words)
{
    std::deque<std::string> result(words.begin(), words.end());

    std::sort(result.begin(), result.end(), [](const std::string &str1, const std::string &str2) {
        if (str1.size() == str2.size())
            return str1 < str2;
        else
            return str1.size() < str2.size();
    });
    return result;
}
