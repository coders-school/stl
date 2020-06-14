#include <algorithm>

#include "sort.hpp"

bool sortWords(std::string  a, std::string b){
    if(a.size() != b.size()){
        return a.size() < b.size();
    }
    return a < b; 
} 

std::deque<std::string> lengthSort(
    const std::forward_list<std::string>& test){
    std::deque<std::string> result;
    for(auto& el : test){
        result.push_back(el);
    }
    std::sort(result.begin(), result.end(),sortWords);
    return result;
}
