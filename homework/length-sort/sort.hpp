#ifndef SORT_HPP
#define SORT_HPP
#include <deque>
#include <forward_list>
#include <string>

bool compare(std::string a, std::string b);
std::deque<std::string> lengthSort(std::forward_list<std::string>& unsortedList);

#endif