#include "transform-containers.hpp"

#include <algorithm>
#include <iterator>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& words, std::deque<int>& numbers)
{
    words.sort();
    words.unique();

    std::sort(numbers.begin(), numbers.end());
    numbers.erase(std::unique(numbers.begin(), numbers.end()), numbers.end());

    std::map<int, std::string> numbersAndWords;
    std::transform(numbers.cbegin(), numbers.cend(), words.cbegin(), std::inserter(numbersAndWords, numbersAndWords.begin()),
        [](const auto& number, const auto& word) { return std::make_pair(number, word); });

    return numbersAndWords;
}
