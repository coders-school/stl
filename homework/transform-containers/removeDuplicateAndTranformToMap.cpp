#include "removeDuplicateAndTranformToMap.hpp"

#include <algorithm>
#include <iostream>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> input_list, std::deque<int> input_deque) {
    std::map<int, std::string> output;

    auto print_list = [](const auto& input_list) {
        std::for_each(input_list.begin(), input_list.end(), [&](auto x) {
            std::cout << x << " ";
        });
        std::cout << std::endl;
    };

    auto print_deque = [](const auto& input_deque) {
        std::for_each(input_deque.begin(), input_deque.end(), [&](auto x) {
            std::cout << x << " ";
        });
        std::cout << std::endl;
    };

    // print_list(input_list);
    input_list.sort();
    input_list.unique();
    // print_list(input_list);

    // print_deque(input_deque);
    std::sort(input_deque.begin(), input_deque.end());
    input_deque.erase(std::unique(input_deque.begin(), input_deque.end()),
                      input_deque.end());
    // print_deque(input_deque);

    if (input_list.size() == input_deque.size()) {
        std::transform(input_deque.begin(),
                       input_deque.end(),
                       input_list.begin(),
                       std::inserter(output, output.end()),
                       [](auto first, auto second) {
                           //std::cout << first << " " << second << std::endl;
                           return std::pair<int, std::string>(first, second);
                       });
    }
    return output;
}