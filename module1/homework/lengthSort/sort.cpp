#include "sort.hpp"

#include <functional>

std::deque<std::string> lengthSort(std::forward_list<std::string> mail) {
    std::deque<std::string> vec;
    mail.sort(std::greater<std::string>());
    for (const auto& el : mail) {
        vec.push_front(el);
    }
    return vec;
}