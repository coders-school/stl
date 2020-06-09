#pragma once

#include <deque>
#include <forward_list>
#include <string>

std::deque<std::string> sort(std::forward_list<std::string>);
bool trueIfLhsBigger(const std::string& lhs, const std::string& rhs);
