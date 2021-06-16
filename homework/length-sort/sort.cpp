#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string> not_sorted_list) {
    not_sorted_list.sort();
    std::deque<std::string> sorted_deque;
    std::for_each(not_sorted_list.begin(), not_sorted_list.end(), [&sorted_deque](std::string word){
        if(sorted_deque.empty()) {
            sorted_deque.push_back(word);
        }
        else {
            int deque_it = 0;
            while (word.size() >= sorted_deque[deque_it].size()) {
                ++deque_it;
                if (deque_it > sorted_deque.size()) {
                    --deque_it;
                    break;
                }
            }
            sorted_deque.emplace(sorted_deque.begin() + deque_it, word);
        }
    }
    );
    return sorted_deque;
}