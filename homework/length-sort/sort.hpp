#pragma once

#include <string>
#include <deque>
#include <forward_list>
#include <algorithm> //std::remove

std::deque<std::string> lengthSort(std::forward_list<std::string> & words);

bool cmp(const std::string &a, const std::string &b);