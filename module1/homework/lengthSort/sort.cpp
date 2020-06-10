#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string>& forwardList) {
    std::deque<std::string> deq;

    for (const auto& word : forwardList) {
        auto it = deq.begin();
        for (it = deq.begin(); it != deq.end(); it++) {
            if ((*it).size() > word.size() || ((*it).size() == word.size() && *it > word)) {
                break;
            }
        }
        deq.insert(it, word);
    }
    return deq;
}
