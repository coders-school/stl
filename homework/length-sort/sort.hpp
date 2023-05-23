#include <algorithm>
#include <deque>
#include <forward_list>

std::deque<std::string> lengthSort(std::forward_list<std::string>& list)
{
    std::deque<std::string> deq(list.begin(), list.end());
    sort(deq.begin(), deq.end(), [](std::string& a, std::string& b) {if (a.size() == b.size()) { return a < b; } else { return a.size() < b.size(); }});
    return deq;
}