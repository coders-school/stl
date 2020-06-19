#include "sort.hpp"

#include <algorithm>

bool compare(const std::string& first_string, const std::string& second_string) {
    if (first_string.size() == second_string.size()) {
        return first_string < second_string;
    }
    return first_string.size() < second_string.size();
}

std::deque<std::string> lengthSort(std::forward_list<std::string> input_list) {
    std::deque<std::string> result_deque{input_list.begin(), input_list.end()};
    std::sort(result_deque.begin(), result_deque.end(), compare);
    return result_deque;
}
