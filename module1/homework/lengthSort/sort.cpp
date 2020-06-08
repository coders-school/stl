#include "sort.hpp"
#include <algorithm>

struct Comparator
{
    bool operator()(const std::string& str1, const std::string& str2)
    {
        if (str1.size() == str2.size())
        {
            return str1 < str2;
        }
        return str1.size() < str2.size();
    }
};

std::deque<std::string> lengthSort(std::forward_list<std::string> words)
{
    words.sort(Comparator());
    std::deque<std::string> result;
    std::transform(words.begin(), words.end(), std::back_inserter(result), [](std::string& s) { return s; });
    return result;
}
