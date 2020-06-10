#pragma once

#include <deque>
#include <forward_list>
#include <string>

bool compareLexicographically(const std::string&, const std::string&);
bool compareSize(const std::string&, const std::string&);
std::deque<std::string> lengthSort(std::forward_list<std::string>);
