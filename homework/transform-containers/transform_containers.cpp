#include <algorithm>
#include <set>

#include "transform_containers.hpp"

Map removeDuplicateAndTranformToMap(
    const std::list<std::string>& strings,
    const std::deque<int>& numbers)
{
    std::set<int> unique_numbers(begin(numbers), end(numbers));
    std::set<std::string> unique_strings(begin(strings), end(strings));
    Map merged;
    std::transform(begin(unique_numbers), end(unique_numbers),
                   begin(unique_strings),
                   inserter(merged, merged.end()),
                   [](const auto& number, const auto& string) {
                       return make_pair(number, string);
                   });

    return merged;
}
