#pragma once
#include <iostream>
#include <deque>
#include <forward_list>
#include <algorithm>

bool setOrder(const std::string& a, const std::string& b);
bool myCompare(const std::string& a, const std::string& b);
std::deque<std::string> setDeque(const std::forward_list<std::string>& list);
std::deque<std::string> lengthSort(std::forward_list<std::string>& list);
