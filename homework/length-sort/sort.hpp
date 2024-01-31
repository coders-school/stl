#pragma once
#include <deque>
#include <forward_list>
#include <string>

bool sortLex(const std::string& first, const std::string& second);

std::deque<std::string> lengthSort(std::forward_list<std::string>& fl);
