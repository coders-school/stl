#include "sort.hpp"

#include <algorithm>

std::deque<std::string> lengthSort(std::forward_list<std::string>& words){
    std::deque<std::string> output;
    std::copy(words.begin(), words.end(), std::back_inserter(output));
   
    auto customLess = [](auto first, auto second){
        if(first.size() == second.size()){
            return std::lexicographical_compare(first.begin(), first.end(), second.begin(), second.end());
        }
        return first.size() < second.size();
    };

    std::sort(output.begin(), output.end(), customLess);

    return output;
}
