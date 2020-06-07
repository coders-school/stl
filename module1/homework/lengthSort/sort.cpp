#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string>& forwardList){
    std::deque<std::string> dq;
    auto it = dq.begin();

    for(const auto& word : forwardList){
        for(it = dq.begin(); it != dq.end(); it++)
            if (it->size() > word.size() || it->size() == word.size() && *it > word)
                break;
        dq.insert(it, word);
    }
    return dq;
}
