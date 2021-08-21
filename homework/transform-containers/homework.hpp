#pragma once

#include <map>
#include <string>
#include <deque>
#include <list>
#include <set>

void removeDuplicatesFromList(std::list<std::string>& l);

void removeDuplicatesFromDeque(std::deque<int>& d);

std::string getElementOfList(const std::list<std::string>& l, const int& i);

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> l, std::deque<int> d);