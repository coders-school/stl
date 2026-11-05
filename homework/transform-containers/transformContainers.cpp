#include "transformContainers.h"

std::map<int, std::string> removeDuplicateAndTranformToMap(
    std::list<std::string> texts,
    std::deque<int> digits) {
    std::sort(begin(digits), end(digits));
    digits.erase(std::unique(begin(digits), end(digits)), end(digits));

    std::vector<std::string> temp;
    std::for_each(begin(texts), end(texts),
                  [&temp](auto item) { temp.push_back(item); });
    std::sort(begin(temp), end(temp));
    temp.erase(std::unique(begin(temp), end(temp)), end(temp));

    std::map<int, std::string> output;
    std::transform(
        begin(digits), end(digits), begin(temp),
        std::inserter(output, end(output)),
        [](auto first, auto second) { return std::make_pair(first, second); });

    return output;
}
