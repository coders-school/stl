#pragma once

#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <string>

using intStrMap = std::map<int, std::string>;
using strList = std::list<std::string>;
using intDeque = std::deque<int>;

bool AnyContainerIsEmpty(const strList& strList, const intDeque& intDeq);
bool ContainersSizeIsNotEqual(const strList& strList, const intDeque& intDeq);
intStrMap removeDuplicateAndTranformToMap(strList strList, intDeque intDeq);
