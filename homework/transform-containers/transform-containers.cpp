#include "transform-containers.hpp"
#include <algorithm>

std::map<int, std::string>
removeDuplicateAndTranformToMap(std::list<std::string>& strings, std::deque<int>& ints) {
    strings.sort();
    auto stringsit = std::unique(begin(strings), end(strings));
    strings.erase(stringsit, strings.end());

    std::sort(begin(ints), end(ints));
    auto intsit = std::unique(begin(ints), end(ints));
    ints.erase(intsit, ints.end());

    std::map<int, std::string> result;
    std::transform(cbegin(strings), cend(strings),
                   cbegin(ints),
                   std::inserter(result, begin(result)),
                   [](const auto& text, auto value) {
                       return std::make_pair(value, text);
                   });
    return result;
}
