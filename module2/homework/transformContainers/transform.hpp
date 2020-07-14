#pragma once

#include <deque>
#include <list>
#include <map>
#include <string>

using intStrMap = std::map<int, std::string>;
using strList = std::list<std::string>;
using intDeque = std::deque<int>;

intStrMap removeDuplicateAndTranformToMap(strList strList, intDeque intDeq);
