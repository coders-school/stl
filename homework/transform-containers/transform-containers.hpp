#pragma once
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <string>

// helper directives
using stringList = std::list<std::string>;
using intDeque = std::deque<int>;
using intStringMap = std::map<int, std::string>;

intStringMap removeDuplicateAndTranformToMap(const stringList& list, const intDeque& ints);