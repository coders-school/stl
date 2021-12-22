#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string>ls)
{
    int max_size=0;
    for(auto it=ls.begin(); it!=ls.end(); it++)
    {
        if(it->size()>max_size) max_size=it->size();
    }
    //std::cout<<max_size;

    std::deque<std::string>que;
    std::vector<std::string>temp_vector;

    auto it=ls.begin();
    for(int i=0; i<=max_size; i++)
    {
        for(it; it!=ls.end(); it++)
        {
            if(it->size()==i) temp_vector.push_back(*it);
        }
        it=ls.begin();
        auto it1=temp_vector.begin();
        auto it2=temp_vector.end();
        sort(it1,it2);
        for(auto element : temp_vector) que.push_back(element);
        temp_vector.clear();
    }
    return que;
}
