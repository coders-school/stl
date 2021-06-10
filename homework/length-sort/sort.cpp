#include "sort.hpp"
#include <iostream>

#include <map>



void pushWithAlphabeticalSort(std::deque<std::string>& deque, const std::string& str) {
    if (deque.front() > str) {
       deque.push_front(str);
    }
    else if (deque.back() < str) {
	deque.push_back(str);
    }
    else {
	deque.push_front(str);
	auto it = deque.begin(); 
	while ((*it) > (*(it + 1))) {
	    std::swap((*it), (*(it + 1)));
	    ++it;
	}
    }
}

std::map<size_t, std::deque<std::string>> bucketSort(const std::forward_list<std::string>& input) {
    std::map<size_t, std::deque<std::string>> result;
    for (const auto& str : input) {
	auto& deque = result[str.length()];
	if (deque.empty()) {
	    deque.push_front(str);
	    continue;
	}
	pushWithAlphabeticalSort(deque, str);
    }
    return result;
}

std::deque<std::string> lengthSort(const std::forward_list<std::string>& input) {
    std::deque<std::string> result;
    auto sortedDeques = bucketSort(input);
    for (const auto& [key, deque] : sortedDeques) {
	result.insert(result.end(), deque.begin(), deque.end());
    }
    return result;
}