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

intStringMap removeDuplicateAndTranformToMap(const stringList& strings, const intDeque& ints);

// returns a copy of container storing only unique elements of the original  passed containar
// takes container by copy in order to preserve orignal container unmodified (dessign choice)
// primary template
// template <typename value_type, template <typename> typename Container>
// Container<value_type> uniqueCopy(Container<value_type> container);

// partial specialisation for lists
template <typename value_type>
std::list<value_type> uniqueCopy(std::list<value_type> listContainer);

// partial specialisation for deques
template <typename value_type>
std::deque<value_type> uniqueCopy(std::deque<value_type> dequeContainer);

// template <typename value_type>
// typename std::list<value_type> uniqueCopy(typename std::list<value_type> container);
// stringList uniqueCopy(const stringList& textList);
