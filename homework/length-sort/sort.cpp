#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string>& words)
{
	std::deque<std::string> sorted;
	for (const auto& list : words) {
		sorted.emplace_back(list);
	}
	std::sort(sorted.begin(), sorted.end(), compare);

	return sorted;
}

bool compare(std::string& lhs, std::string& rhs)
{
	if (lhs.length() == rhs.length()) {
		return lhs < rhs;
	}
	return lhs.length() < rhs.length();
}
