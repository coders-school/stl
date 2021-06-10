#pragma once
#include <algorithm>
#include <deque>
#include <forward_list>
#include <iostream>

std::deque<std::string> lengthSort(std::forward_list<std::string>&);

bool compare_length(const std::string& str1, const std::string& str2);