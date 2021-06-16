#include <iostream>
#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string> inputList) {

    std::deque<std::string> sortedDeque; //resize?
    
    while(!inputList.empty()) {
        auto mainIt = inputList.begin();
        auto mainItBefore = inputList.before_begin();
        auto comparedValueIt = inputList.begin();
        auto comparedValueItBefore = inputList.before_begin();

        for (; mainIt != inputList.end(); ++mainIt, ++mainItBefore) {
            if ((*mainIt).length() < (*comparedValueIt).length()) {
                comparedValueIt = mainIt;
                comparedValueItBefore = mainItBefore;
            }
            else if ((*mainIt).length() == (*comparedValueIt).length() && *mainIt < *comparedValueIt) {
                comparedValueIt = mainIt;
                comparedValueItBefore = mainItBefore;
            }
        }
        sortedDeque.push_back(*comparedValueIt);
        inputList.erase_after(comparedValueItBefore);
    }
    return sortedDeque;
}
