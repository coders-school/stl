#include <algorithm>
#include <deque>
#include <forward_list>
#include <iostream>
#include <string>

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
