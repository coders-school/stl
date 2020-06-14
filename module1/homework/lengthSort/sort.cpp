#include <algorithm>
#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string> wordsList)
{
    wordsList.sort(std::less<std::string>());
    std::deque<std::string> sortedWords(wordsList.begin(), wordsList.end());
    return sortedWords;
}
