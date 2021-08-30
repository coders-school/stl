#include "sort.hpp"


std::deque<std::string> lengthSort(std::forward_list<std::string> words) {
    std::deque<std::string> deq(words.begin(), words.end());
    std::sort(deq.begin(), deq.end(), [](const std::string &s1, const std::string &s2){
        return (s1.length() < s2.length() || s1.length() == s2.length() && s1 < s2); 
    });
    return deq;
};