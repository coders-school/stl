#include "sort.hpp"

std::deque<std::string>  lengthSort(std::forward_list<std::string> &wordFlist)
{
    std::deque<std::string> wordDeque{};
    wordFlist.sort();
    wordFlist.sort(cmp);
    wordDeque.insert(wordDeque.begin(),wordFlist.begin(),wordFlist.end());
    return wordDeque;
}

bool cmp(const std::string &a, const std::string &b)
{
    if(b.size() > a.size())
        return true;
    else 
        return false;
}
