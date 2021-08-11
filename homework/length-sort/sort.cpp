#include <iostream>
#include <forward_list>
#include <string>
#include <deque>
#include <algorithm>

std::deque<std::string> lengthSort(std::forward_list<std::string> & f_list){
    f_list.sort();
    std::deque<std::string> d_list;
    for(const auto & el : f_list) {
        d_list.push_back(el);
    }

    std::sort(d_list.begin(), d_list.end(), [](const std::string & str1,const std::string & str2){return str1.size() < str2.size();});
    return d_list;
}