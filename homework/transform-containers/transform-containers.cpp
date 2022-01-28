#include "transform-containers.hpp"

// removes duplicates from passed containers and returns
// a map of <int,string> unique elements
intStringMap removeDuplicateAndTranformToMap(const stringList& strings, const intDeque& ints)
{
    auto unique_strings = uniqueCopy(strings);
    auto unique_ints = uniqueCopy(ints);
    intStringMap result;
    // Fill the result map
    std::transform(unique_strings.begin(),
                   unique_strings.end(),
                   unique_ints.begin(),
                   std::inserter(result, result.end()),
                   [](const auto& text, const auto& num) {
                       return std::make_pair(num, text);
                   });

    return std::move(result);
}

// returns a copy of a list, storing only unique elements of the original  passed containar
// takes container by copy in order to preserve orignal container unmodified (dessign choice)
template <typename value_type>
std::list<value_type> uniqueCopy(std::list<value_type> listContainer)
{
    listContainer.sort();
    auto first_to_remove = std::unique(begin(listContainer), end(listContainer));
    listContainer.erase(first_to_remove, end(listContainer));
    return std::move(listContainer);
}

// returns a copy of a deque, storing only unique elements of the original  passed containar
// takes container by copy in order to preserve orignal container unmodified (dessign choice)
template <typename value_type>
std::deque<value_type> uniqueCopy(std::deque<value_type> dequeContainer)
{
    std::sort(begin(dequeContainer), end(dequeContainer));
    auto first_to_remove = std::unique(begin(dequeContainer), end(dequeContainer));
    dequeContainer.erase(first_to_remove, end(dequeContainer));
    return std::move(dequeContainer);
}
