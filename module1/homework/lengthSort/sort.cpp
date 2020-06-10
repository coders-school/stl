#include "sort.hpp"

#include <algorithm>

bool compareLexicographically(const std::string& first_string,
                              const std::string& second_string) {
    std::size_t i = 0;
    while ((i < first_string.size()) && (i < second_string.size())) {
        if (tolower(first_string[i]) < tolower(second_string[i])) {
            return true;
        } else if (tolower(first_string[i]) > tolower(second_string[i])) {
            return false;
        }
        i++;
    }
    return false;
}

bool compareSize(const std::string& first_string, const std::string& second_string) {
    return first_string.size() < second_string.size();
}

std::deque<std::string> lengthSort(std::forward_list<std::string> input_list) {
    std::deque<std::string> result_deque;
    input_list.sort(compareLexicographically);
    input_list.sort(compareSize);
    for (std::string element : input_list) {
        result_deque.emplace_back(element);
    }
    return result_deque;
}
