#include <algorithm>

#include "sort.hpp"

bool sortWords(std::string a, std::string b) {
    if(a.size() != b.size()){
        return a.size() < b.size();
    }
    return a < b; 
} 

std::deque<std::string> lengthSort(
    const std::forward_list<std::string>& test) {
    std::deque<std::string> result{test.begin(), test.end()};
    std::sort(result.begin(), result.end(), sortWords);
    return result;
}
