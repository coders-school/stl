#include "sort.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>

std::deque<std::string> lengthSort(std::forward_list<std::string> fli) {
    std::deque<std::string> deq;
    fli.sort();

    int i{0};

    for (auto it = fli.begin(); it != fli.end(); ++it, i++) {
        for (int j = 0; j < (*it).length() - 1; j++) {
            auto it1 = fli.begin();
            auto it2 = next(fli.begin(), j);

            std::cout << " it1: " << *it1 << "it2: " << *it2 << " ";
        }
        std::cout << (*it).size() << " ";

        // if(*it < *(it).be )

        deq.emplace_back(*it);
    }

    return deq;
}