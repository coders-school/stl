#include "sort.hpp"

#include <algorithm>
#include <map>
#include <vector>

std::deque<std::string> lengthSort(std::forward_list<std::string> lst) {
    std::vector<int> length_cont;
    std::vector<std::string> word_cont;
    for (auto el : lst) {
        length_cont.push_back(el.length());
        word_cont.push_back(el);
    }
    std::sort(length_cont.begin(), length_cont.end());
    std::deque<std::string> dq;

    for (size_t i = 0; i < length_cont.size(); ++i) {
        for (size_t j = 0; j < word_cont.size(); ++j) {
            if (length_cont[i] == word_cont[j].length()) {
                dq.push_back(word_cont[j]);
                auto it = std::remove(word_cont.begin(), word_cont.end(), word_cont[j]);
                word_cont.erase(it, word_cont.end());
            }
        }
    }
    int count = 0;
    while (count != dq.size()) {
        for (size_t i = 0; i < dq.size(); ++i) {
            if (i > 0 && dq[i].length() == dq[i - 1].length()) {
                if (std::lexicographical_compare(dq[i].begin(), dq[i].end(), dq[i - 1].begin(), dq[i - 1].end())) {
                    dq[i].swap(dq[i - 1]);
                }
            }
        }
        count++;
    }

    return dq;
}
