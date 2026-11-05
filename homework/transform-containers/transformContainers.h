#pragma once
#include <algorithm>
#include <deque>
#include <iterator>
#include <list>
#include <map>
#include <string>
#include <vector>

std::map<int, std::string> removeDuplicateAndTranformToMap(
    std::list<std::string> texts,
    std::deque<int> numbers);
