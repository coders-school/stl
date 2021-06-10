#pragma once
#include <algorithm>
#include <deque>
#include <forward_list>
#include <iostream>

std::deque<std::string> lengthSort(std::forward_list<std::string>);

bool compare_length(std::string& str1, std::string& str2);