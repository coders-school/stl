#include "sort.hpp"
#include <algorithm>

std::deque<std::string> lengthSort(std::forward_list<std::string>& forwardList) {
    std::deque<std::string> dq;
    
    forwardList.sort( [](const auto str1, const auto str2){
        if(str1.size() == str2.size()){
            return str1 < str2;
        }
        return str1.size() < str2.size();
    } );
    
    for(const auto el : forwardList){
        dq.push_back(el);
    }

    return dq;
}
