#pragma once

#include <deque>
#include <forward_list>
#include <string>

bool comparator(const std::string &, const std::string &);

std::deque<std::string> lengthSort(std::forward_list<std::string>);

