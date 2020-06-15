#include "sort.hpp"

#include <functional>

std::deque<std::string> lengthSort(std::forward_list<std::string> mail) {
    mail.sort(std::greater<std::string>());
    mail.reverse();
    std::deque<std::string> vec{mail.begin(), mail.end()};

    return vec;
}