//#include <deque>
//#include <iostream>
//#include <list>
//#include <string>

#include "transformContainers.hpp"

int main() {
    std::list<std::string> list{
        "Ala", "Kot", "Ma", "Rysia", "Ala",
        "Sierotka", "Kot", "Ma", "Ala"};
    std::deque<int> deque{
        1, 2, 3, 4, 5, 3, 1, 2, 3, 4,
        5, 2, 3, 1, 1, 2, 3, 2, 1, 4};

    auto map = removeDuplicateAndTranformToMap(list, deque);

    return 0;
}
