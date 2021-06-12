
#include "sort.hpp"

bool sort_fun(const std::string& lhs, const std::string& rhs)
{
    if(lhs.size() == rhs.size())
        return lhs < rhs;

    return lhs.size() < rhs.size();
}

std::deque<std::string> lengthSort(std::forward_list<std::string>& list)
{
    std::deque<std::string> deq{};

    for(auto& el : list)
        deq.emplace_back(el);

    std::sort(deq.begin(), deq.end(), sort_fun);

    return deq;
}

/////////////////////////////////////////////////////////////////////////////
std::deque<std::string> lengthSort_ver2(std::forward_list<std::string>& list)
{
    std::deque<std::string> deq{};

    for(auto& el : list)
    {
        if(deq.empty())
        {
            deq.insert(deq.begin(), el);
            continue;
        }

        auto it = deq.begin();
        while(it < deq.end())
        {
            if(el.size() < (*it).size()) {
                deq.insert(it, el);
                break;
            }
            else if(el.size() == (*it).size()) {
                if(el <= *it) {
                    deq.insert(it, el);
                    break;
                }
            }

            if (it == deq.end() - 1) {
                deq.insert(deq.end(), el);
                break;
            }
            ++it;
        }
    }
    return deq;
}
