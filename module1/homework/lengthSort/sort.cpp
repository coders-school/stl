#include "sort.hpp"
#include <algorithm>

std::deque<std::string> lengthSort(std::forward_list<std::string> words)
{
    words.sort(
            [](const std::string& str1, const std::string& str2) 
                {
                    if (str1.size() == str2.size())
                    {
                        return str1 < str2;
                    }
                    return str1.size() < str2.size();
                }
              );
    return std::deque<std::string>(words.begin(), words.end());
}
