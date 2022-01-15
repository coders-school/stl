#include "sort.hpp"
#include <algorithm>
#include <vector>
#include <utility>

std::deque<std::string> lengthSort(std::forward_list<std::string> & word_list)
{
    std::vector< std::pair<size_t, std::string> > pairs;
    for (auto word : word_list)
        pairs.emplace_back(std::make_pair(word.size(), word) );

    std::sort(pairs.begin(), pairs.end(),
        [](std::pair<size_t, std::string>& p1, std::pair<size_t, std::string>& p2) {return p1.first < p2.first;}
        );

    std::deque<std::string> ans;
    for (auto i : pairs)
        ans.push_back(i.second);

    return ans;
}
