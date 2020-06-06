#include "sort.hpp"
#include <algorithm>
#include <iostream>

std::deque<std::string> lengthSort(const std::forward_list<std::string>& words){
std::deque<std::string> result;

for(const auto& word : words){
    result.push_back(word);
}

std::sort(result.begin(), result.end(), [](std::string lhs, std::string rhs){ return lhs.size() == rhs.size() ? lhs < rhs: lhs.size() < rhs.size(); });

return result;
}
