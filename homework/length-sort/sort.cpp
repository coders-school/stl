#include "sort.hpp"
#include <algorithm>

std::deque<std::string> lengthSort(const std::forward_list<std::string> &words)
{
    std::deque<std::string> sorttmp;
    std::copy(words.begin(), words.end(), std::front_inserter(sorttmp));

    std::sort(sorttmp.begin(), sorttmp.end(), [](std::string a, std::string b)
              {
                  if (a.length() == b.length())
                  {
                      if (std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end()))
                      {
                          return true;
                      }
                      return false;
                  }
                  if (a.length() < b.length())
                  {
                      return true;
                  }
                  return false;
              });

    return sorttmp;
};