#include "sort.hpp"

// funkcja ma przyjąć forward_list<std::string> i zwrócić deque<std::string> z posortowanymi słowami
// od najkrótszego do najdłuższego. Jeżeli dwa lub więcej słów ma tyle samo znaków posortuj je leksykograficznie.
//inline bool test(std::string& a, std::string& b) { return (a<b); }
std::deque<std::string>lengthSort( std::forward_list<std::string>& words) {
    
    words.sort();
    std::deque<std::string> word;
    auto itFirst = word.begin();

    for( const auto& w : words) {

        word.push_back(w);
    } 
    std::sort(itFirst, word.end(), [](const std::string& first, const std::string& last){ return first.size() < last.size();} );
    
    return word;
}