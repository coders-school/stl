#include <algorithm>
#include <deque>
#include <forward_list>
#include <iostream>
#include <string>
#include <vector>

std::deque<std::string> lengthSort(const std::forward_list<std::string>& words) {
    std::cout << "Hello from lengthSort" << std::endl;
    std::deque<std::string> sorted;
    int i = 0;

    for (const auto& element : words) {
        sorted.push_back(element);
    }

    std::sort(sorted.begin(), sorted.end());
    return sorted;
}