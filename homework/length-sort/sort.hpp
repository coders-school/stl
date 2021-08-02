#pragma once

#include <deque>
#include <forward_list>
#include <string>
#include <functional>

struct IsShorter
{
    bool operator()(const std::string &first, const std::string &second)
    {
        if (first.size() == second.size())
        {
            auto iterator1 = first.begin();
            auto iterator2 = second.begin();

            for (; iterator1 != first.end(); iterator1++, iterator2++)
            {
                if (*iterator1 != *iterator2)
                {
                    return *iterator1 < *iterator2;
                }
            }
        }
        else
        {
            return first.size() < second.size();
        }

        return true; //return true, if both values are equal
    }
};

std::deque<std::string> lengthSort(std::forward_list<std::string> s);