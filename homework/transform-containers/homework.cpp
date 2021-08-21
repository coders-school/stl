#include "homework.hpp"
#include <algorithm>

void removeDuplicatesFromList(std::list<std::string>& l){
    std::set<std::string> foundDuplicates;
    
    for (auto x = l.begin(); x != l.end();) 
    {
        bool notFound = foundDuplicates.insert(*x).second;
        notFound == true ? x++: x = l.erase(x);
    }
}

void removeDuplicatesFromDeque(std::deque<int>& d){
    std::set<int> foundDuplicates;
    
    for (auto x = d.begin(); x != d.end();) 
    {
        bool notFound = foundDuplicates.insert(*x).second;
        notFound == true ? x++: x = d.erase(x);
    }
}

std::string getElementOfList(const std::list<std::string>& l, const int& i){
    if(i >= l.size()){
        return "";
    }
    auto l_front = l.begin();
    std::advance(l_front, i);
    
    return *l_front;
}

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> l, std::deque<int> d){
    std::map<int, std::string> m;
    
    removeDuplicatesFromList(l);
    removeDuplicatesFromDeque(d);
    
    if(l.size() != d.size())
        return m;
    
    int i = 0;
    std::transform(d.begin(), d.end(), std::inserter(m, m.end()), [&i, l](int a)
    {
        std::string toAdd = getElementOfList(l, i);
        i++;
        return std::make_pair(a, toAdd);
    });
    return m;
}