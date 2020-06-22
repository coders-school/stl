#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string> words){
    words.sort();
    std::deque<std::string> result(words.begin(), words.end());

    return result;
}

