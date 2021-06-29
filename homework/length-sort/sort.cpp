#include "sort.hpp"
#include <string>

std::deque<std::string> lengthSort(std::forward_list<std::string> flist)
{
    std::deque<std::string> dlist;
    for(auto i = flist.begin(); i != flist.end(); i++)
    {
        if(dlist.empty())
        {
            dlist.push_back(*i);
        }
        else
        {
            bool isLast = true;
            for(auto j = dlist.begin(); j != dlist.end(); j++)
            {
                if((*i).length() < (*j).length())
                {
                    dlist.insert(j, *i);
                    isLast = false;
                    break;
                }
                else if((*i).length() == (*j).length() && *i < *j)
                {
                    dlist.insert(j, *i);
                    isLast = false;
                    break;
                }
            }
            if(isLast)
            {
                dlist.push_back(*i);
            }
        }
    }
    return dlist;
}
