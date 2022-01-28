#include "transform-containers.hpp"

// removes duplicates from passed containers and returns
// a map of <int,string> unique elements
// does not modify original passed arguments
intStringMap removeDuplicateAndTranformToMap(const stringList& strings, const intDeque& ints)
{
    // remove duplicates from passed containers
    // strings.sort();
    // auto last_string = std::unique(strings.begin(), strings.end());
    // strings.erase(last_string, strings.end());

    // std::sort(ints.begin(), ints.end());
    // auto last_int = std::unique(ints.begin(), ints.end());
    // ints.erase(last_int, ints.end());
    auto unique_strings = uniqueCopy(strings);
    auto unique_ints = uniqueCopy(ints);

    intStringMap result;

    std::transform(unique_strings.begin(),
                   unique_strings.end(),
                   unique_ints.begin(),
                   std::inserter(result, result.end()),
                   [](const auto& text, const auto& num) {
                       return std::make_pair(num, text);
                   });

    return std::move(result);
}

// returns a copy of container storing only unique elements of the original  passed containar
// takes container by copy in order to preserve orignal container unmodified (dessign choice)
// primary template
// template <typename value_type, template <typename> typename Container>
// Container<value_type> uniqueCopy(Container<value_type> container)
// {
//     std::sort(begin(container), end(container));
//     auto first_to_remove = std::unique(begin(container), end(container));
//     container.erase(first_to_remove, end(container));

//     return std::move(container);
// }

// partial specialisation for lists
template <typename value_type>
std::list<value_type> uniqueCopy(std::list<value_type> listContainer)
{
    listContainer.sort();
    auto first_to_remove = std::unique(begin(listContainer), end(listContainer));
    listContainer.erase(first_to_remove, end(listContainer));
    return std::move(listContainer);
}

template <typename value_type>
std::deque<value_type> uniqueCopy(std::deque<value_type> dequeContainer)
{
    //     std::deque<value_type> result { dequeContainer };
    std::sort(begin(dequeContainer), end(dequeContainer));
    auto first_to_remove = std::unique(begin(dequeContainer), end(dequeContainer));
    dequeContainer.erase(first_to_remove, end(dequeContainer));
    return std::move(dequeContainer);
}

// stringList uniqueCopy(const stringList& textList)
// {
//     stringList result { textList };
//     result.sort();
//     auto first_to_remove = std::unique(begin(result), end(result));
//     result.erase(first_to_remove, end(result));
//     return std::move(result);
// }