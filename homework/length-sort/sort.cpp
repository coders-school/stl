#include "sort.hpp"

bool Compare(std::string& word1, std::string& word2) {
    return word1.length() < word2.length();
}
bool Compare1(std::string& word1, std::string& word2) {
    return std::lexicographical_compare(word1.begin(), word1.end(), 
                                        word2.begin(), word2.end());
}
std::deque<std::string> lengthSort(std::forward_list<std::string>& for_lis) { 
    std::deque<std::string> deq;
    
    for_lis.sort(Compare1);
    for_lis.sort(Compare);
    for (auto n : for_lis) {
        deq.push_back(n);
    }
    return deq;
}