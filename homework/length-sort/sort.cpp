#include "sort.hpp"
#include <algorithm>

class str_comp_functor //function would be ok here, but I want to try functor class
{
public:
    bool operator() (std::string& s1, std::string& s2)
    {
    if ( s1.size() == s2.size() ) return s1 < s2;
    else return s1.size() < s2.size();
    }
};

std::deque<std::string> lengthSort(std::forward_list<std::string> & word_list)
{
    std::deque<std::string> ans;
    for (auto & word : word_list)
    {
        ans.push_back(word);
    }
    std::sort(ans.begin(), ans.end(), str_comp_functor());

    return ans;
}
