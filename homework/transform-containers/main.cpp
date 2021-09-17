#include "transformContainers.hpp"
#include <deque>
#include <iostream>

int main() {

    std::deque<int> de = {1, 4, 3, 6, 2, 3, 4, 1, 5, 6};
    for (auto& el : de) {
        std::cout << el << ' ';
    }
    std::cout << '\n';

    // removeDuplicates(de);
    // for (auto& el : de) {
    //     std::cout << el << ' ';
    // }
    // std::cout << '\n';


    
}