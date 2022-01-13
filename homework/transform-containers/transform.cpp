#include "transform.hpp"

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> names, std::deque<int> numbers)
{

    names.sort();
    names.unique();

    std::sort(numbers.begin(), numbers.end());
    numbers.erase(std::unique(numbers.begin(), numbers.end()), numbers.end());

    /*for(auto & el : names)
    {
        std::cout<<el<<" ";
    }
    std::cout<<'\n';

    for(auto el : numbers)
    {
        std::cout<<el<<" ";
    }
    std::cout<<'\n';*/

    std::map<int, std::string> map;

    auto lambda = [] (auto number, auto name) { return std::make_pair(number, name); };

    std::transform(numbers.begin(), numbers.end(), names.begin(), std::inserter(map, map.end()), lambda);

    return map;
}
