#include "sort.hpp"

#include<algorithm>


std::deque<std::string> lengthSort(std::forward_list<std::string> takedList) {

takedList.sort();

std::deque<std::string> deq (takedList.begin(), takedList.end());

auto sortSize = [](std::string s1, std::string s2){return s1.size() < s2.size();};

std::sort(deq.begin(),deq.end(), sortSize);

return deq;

}

