#include "transform-containers.hpp"

#include <iostream>

// removes duplicates from passed containers and returns
// a map of <int,string> unique elements
// does not modify original passed arguments
intStringMap removeDuplicateAndTranformToMap(stringList strings, intDeque ints)
{
    // remove duplicates from passed containers
    strings.sort();
    auto last_string = std::unique(strings.begin(), strings.end());
    strings.erase(last_string, strings.end());

    std::sort(ints.begin(), ints.end());
    auto last_int = std::unique(ints.begin(), ints.end());
    ints.erase(last_int, ints.end());

    intStringMap result;

    std::transform(strings.begin(),
                   strings.end(),
                   ints.begin(),
                   std::inserter(result, result.end()),
                   [](const auto& text, const auto& num) {
                       return std::make_pair(num, text);
                   });

    return std::move(result);
}