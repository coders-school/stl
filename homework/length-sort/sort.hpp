#pragma once
#include <string>
#include <deque>
#include <algorithm>
#include <forward_list>

std::deque<std::string> lengthSort(std::forward_list<std::string>& words);

bool compare(std::string& lhs, std::string& rhs);