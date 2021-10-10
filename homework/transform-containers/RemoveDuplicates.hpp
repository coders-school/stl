#pragma once
#include <iostream>
#include <map>
#include <string>
#include <deque>
#include <list>
#include <algorithm>
#include <stdexcept>

std::map<int, std::string> removeDuplicateAndTranformToMap(const std::list<std::string> &l, const std::deque<int> &d)
{
    auto list = l;
    auto deque = d;
    list.sort();
    list.unique();

    std::sort(deque.begin(), deque.end());
    deque.erase(std::unique(deque.begin(), deque.end()), deque.end());

    std::map<int, std::string> result;
    if (list.size() == deque.size())
    {
        std::transform(deque.begin(), deque.end(), list.begin(), std::inserter(result, result.begin()),
                       [](auto key, auto value)
                       { return std::make_pair(key, value); });
    }else{
        throw std::length_error("Input containers size are different after remove duplicates");
    }
    return result;
}