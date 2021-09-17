#pragma once
#include <deque>
#include <list>
#include <map>
#include <string>

// template <typename T>
// void removeDuplicates(T& container);

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> list, std::deque<int> deque);