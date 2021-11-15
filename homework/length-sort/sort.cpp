#include "sort.hpp"

bool cmp(const std::string &a, const std::string &b){
    //length of both is the same
    if(a.length() == b.length()){
        int comparison_result = a.compare(b);
        if (comparison_result >= 0) // a is greater or identical
            return true;
        else
            return false;            //a is lesser (lexinogr)
    }
    if(a.length() > b.length())     //a is longer
        return true;
    else                            //a is shorter
        return false;
}

std::deque<std::string> lengthSort(std::forward_list<std::string> & words){
    std::deque<std::string> deq;
    words.sort(cmp);
    for (auto word : words){
        deq.push_front(word);
    }
    return deq;
}

