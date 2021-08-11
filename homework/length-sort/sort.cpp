#include <iostream>
#include <forward_list>
#include <string>
#include <deque>
#include <algorithm>

std::deque<std::string> lengthSort(std::forward_list<std::string> & f_list){
    f_list.sort();
    std::deque<std::string> d_list;
    for(auto & el : f_list) {
        d_list.push_back(el);
    }

    std::sort(d_list.begin(), d_list.end(), [](std::string & str1, std::string & str2){return str1.size() < str2.size();});
    return d_list;
}