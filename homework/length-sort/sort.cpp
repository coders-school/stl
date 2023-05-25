#include <string>
#include <list>
#include <deque>
#include <forward_list>
#include <vector>
#include <algorithm>

#include "sort.hpp"

bool customSort(const std::string& str1, std::string& str2){
    if (str1.length() == str2.length()){
            return str1 < str2;  //This line will sort strings in alphabetic order
    }
    return str1.length() < str2.length(); //This line will sort strings in case of length
}



std::deque<std::string> lengthSort(std::forward_list<std::string>& str) {
    std::vector<std::string> temp(str.begin(), str.end());
    std::sort(temp.begin(), temp.end(), customSort);
    std::deque<std::string> sorted(temp.begin(), temp.end());

    return sorted;

}