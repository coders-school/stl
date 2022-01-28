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

// removes duplicates from passed containers and returns
// a map of <int,string> unique elements
intStringMap removeDuplicateAndTranformToMap(const stringList& strings, const intDeque& ints);

// returns a copy of a list, storing only unique elements of the original  passed containar
// takes container by copy in order to preserve orignal container unmodified (dessign choice)
template <typename value_type>
std::list<value_type> uniqueCopy(std::list<value_type> listContainer);

// returns a copy of a deque, storing only unique elements of the original  passed containar
// takes container by copy in order to preserve orignal container unmodified (dessign choice)
template <typename value_type>
std::deque<value_type> uniqueCopy(std::deque<value_type> dequeContainer);
