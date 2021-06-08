#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string> &words)
{
    std::deque<std::string> sorttmp;

    words.sort([](std::string a, std::string b)
               {
                   if (a.length() == b.length())
                   {
                       if (std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end()))
                       {
                           return false;
                       }
                       return true;
                   }
                   if (a.length() < b.length())
                   {
                       return false;
                   }
                   return true;
               });

    std::copy(words.begin(), words.end(), std::front_inserter(sorttmp));

    return sorttmp;
};