#pragma once
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <string>

std::map<int, std::string> zip(std::deque<int>& keys, std::list<std::string>& values)
{
    std::map<int, std::string> result{};

    std::transform(std::begin(keys),
                   std::end(keys),
                   std::begin(values),
                   std::inserter(result, result.end()),
                   [&keys, &values](int i, std::string& str) { return std::make_pair(i, str); });

    return result;
}

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& list_, std::deque<int>& deque_)
{
    list_.sort();
    list_.erase((std::unique(list_.begin(), list_.end())), list_.end());

    std::sort(deque_.begin(), deque_.end());
    deque_.erase((std::unique(deque_.begin(), deque_.end())), deque_.end());

    return zip(deque_, list_);
}
