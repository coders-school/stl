#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <deque>
#include <map>

std::map<int, std::string> transformContainers(std::list<std::string> cities, std::deque<int> numbers)
{
    cities.sort();
    cities.erase(std::unique(cities.begin(), cities.end()), cities.end());

    std::sort(numbers.begin(), numbers.end());
    numbers.erase(std::unique(numbers.begin(), numbers.end()), numbers.end());

    std::map<int, std::string> map;
    auto zip = [](std::string s, int i) { return std::make_pair(i, s); };
    std::transform(cities.begin(), cities.end(), numbers.begin(), std::inserter(map, map.end()), zip);

    return map;
}