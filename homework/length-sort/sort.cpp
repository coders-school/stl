#include "sort.hpp"
#include <iostream>
#include <algorithm>
#include <functional>

std::ostream& operator<<(std::ostream& ostr, const std::forward_list<std::string>& list)
{
    for (auto &i : list) {
        ostr << " " << i;
    }
    return ostr;
}

std::string sort_lexo(std::string& s)
{
    return s;
}

std::deque<std::string> lengthSort(std::forward_list<std::string> fwdL)
{
    std::cout << "before:     " << fwdL << "\n";
    fwdL.sort(std::greater<std::string>());
    std::cout << "after :     " << fwdL << "\n";
    fwdL.reverse();
    
    std::deque<std::string> ds{};
    std::for_each(fwdL.begin(), fwdL.end(), [&](auto s){
        s = sort_lexo(s);
        ds.push_back(s);
    });

    return ds;
}

