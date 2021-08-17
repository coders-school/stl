#pragma once

#include <deque>
#include <list>
#include <map>
#include <string>

using Map = std::map<int, std::string>;

Map removeDuplicateAndTranformToMap(
    const std::list<std::string>& strings,
    const std::deque<int>& numbers);
