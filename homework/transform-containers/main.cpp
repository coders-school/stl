#include <iostream>
#include <deque>
#include <list>
#include <map>
#include <string>

#include "transformContainers.hpp"

int main() {
    std::map<int, std::string> expected_result{
        {1, "Ala"},
        {2, "Kot"},
        {3, "Ma"},
        {4, "Rysia"},
        {5, "Sierotka"}};
    std::list<std::string> list{
        "Ala", "Kot", "Ma", "Rysia", "Ala",
        "Sierotka", "Kot", "Ma", "Ala"};
    std::deque<int> deque{
        1, 2, 3, 4, 5, 3, 1, 2, 3, 4,
        5, 2, 3, 1, 1, 2, 3, 2, 1, 4};


    auto map = removeDuplicateAndTranformToMap(list, deque);

    for (auto [key,val] : map) {
	    std::cout << key <<" : " << val << "  |  ";
    }
    std::cout << '\n';

	return 0;
}
