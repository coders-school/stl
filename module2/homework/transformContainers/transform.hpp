#pragma once

#include <deque>
#include <list>
#include <map>
#include <string>

using intStrMap = std::map<int, std::string>;
using strList = std::list<std::string>;
using intDeque = std::deque<int>;

bool anyContainerIsEmpty(const strList& strList, const intDeque& intDeq);
bool containersSizeIsNotEqual(const strList& strList, const intDeque& intDeq);
intStrMap removeDuplicateAndTranformToMap(strList strList, intDeque intDeq);
