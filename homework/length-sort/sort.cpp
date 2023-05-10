#include "sort.hpp"
std::deque<std::string> lengthSort(std::forward_list<std::string>& ls)
{
    std::deque<std::string> deq;
    std::deque<std::string>::iterator deqit;
    bool sorted = false;
    for(auto word : ls)
    {
        deq.emplace_back(word);
    }
    while(sorted == false)
    {
        sorted = true;
        for(deqit = deq.begin(); (deqit) != deq.end()-1; deqit++)
        {
            if(deqit->size()>(deqit+1)->size())
            {
                sorted = false;
                deqit->swap(*(deqit+1));
            }
        }
    }
    sorted = false;
    char l1,l2;
    while(sorted == false)
    {
        sorted = true;
        for(deqit = deq.begin(); (deqit) != deq.end()-1; deqit++)
        {
            if(deqit->size()==(deqit+1)->size())
            {
                for(int i=0;i<deqit->size();i++)
                {
                    if(tolower((*deqit)[i])>tolower((*(deqit+1))[i]))
                    {
                        sorted = false;
                        deqit->swap(*(deqit+1));
                        break;
                    }
                    else if(tolower((*deqit)[i])<tolower((*(deqit+1))[i]))
                    {
                        break;
                    }
                    else
                    {
                        if((*deqit)[i]>(*(deqit+1))[i])
                        {
                            sorted = false;
                            deqit->swap(*(deqit+1));
                            break;
                        }
                        else if((*deqit)[i]<(*(deqit+1))[i])
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
    return deq;
}