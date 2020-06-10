#pragma once

#include <deque>
#include <forward_list>
#include <string>

bool pred(const std::string& a, const std::string& b);
std::deque<std::string> lengthSort(std::forward_list<std::string>& f);
