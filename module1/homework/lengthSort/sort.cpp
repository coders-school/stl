#include "sort.hpp"

std::deque<std::string> lengthSort(const std::forward_list<std::string>& list) {
    std::deque<std::string> words_deq;

    auto deq_it = words_deq.begin();
    for(auto& word : list) {
        deq_it = words_deq.begin();
        while(deq_it != words_deq.end()) {
            if(word.size() < deq_it->size() || (word.size() == deq_it->size() && word < *deq_it)) {
                break;
            }
            ++deq_it;
        }
        words_deq.insert(deq_it, word);
    }
    return words_deq;
}
