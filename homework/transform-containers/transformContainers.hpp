#pragma once

#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <string>

using resultMap = std::map<int, std::string>;
using inList = std::list<std::string>;
using inDeq = std::deque<int>;

resultMap removeDuplicateAndTranformToMap(inList&, inDeq&);