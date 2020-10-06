#include "sort.hpp"
#include <forward_list>

std::deque<std::string> lengthSort(std::forward_list<std::string>& words)
{
    std::string temp_word;
    words.sort([](const std::string& str1, const std::string& str2){
            return str1.size() == str2.size() ? str1 < str2 : str1.size() < str2.size();
    } );
    std::deque<std::string> sorted_words(words.begin(), words.end());
    return sorted_words;
}