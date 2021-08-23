#include <algorithm>
#include <deque>
#include <forward_list>
#include <string>

bool commparator(std::string first, std::string second) {
    return first.size() < second.size();
}

std::deque<std::string> lengthSort(std::forward_list<std::string>& sortWords) {
    sortWords.sort();
    sortWords.sort(commparator);
    std::deque<std::string> lengthSort;
    std::copy(sortWords.begin(), sortWords.end(), std::back_inserter(lengthSort));
    return lengthSort;
}
