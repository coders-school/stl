#include "sort.hpp"
#include <algorithm>

std::deque<std::string> lengthSort(std::forward_list<std::string> words)
{
    words.sort();
    std::deque<std::string> result;
    std::transform(words.begin(), words.end(), std::back_inserter(result), [](std::string& s) { return s; });
    return result;
}
