#include "sort.hpp"
#include <algorithm>


std::deque<std::string>lengthSort(std::forward_list<std::string> &li){
    std::deque<std::string> temp;
    for(const auto &t : li){
        temp.push_back(t);
    }
    std::sort(temp.begin(), temp.end());
    for(int i = 0; i < temp.size(); ++i){
        for(int j = 0; j < temp.size()-1; ++j){
            if(temp[j].length() > temp[j + 1].length()){
                std::swap(temp[j], temp[j+1]);
            }
        }
    }
    return temp;
}
