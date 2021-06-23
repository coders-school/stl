#pragma once
#include<forward_list>
#include<deque>
#include <string>

std::deque<std::string>  lengthSort(std::forward_list<std::string> &wordFlist);
bool cmp(const std::string &a, const std::string &b);