#include "sort.hpp"

// funkcja ma przyjąć forward_list<std::string> i zwrócić deque<std::string> z posortowanymi słowami
// od najkrótszego do najdłuższego. Jeżeli dwa lub więcej słów ma tyle samo znaków posortuj je leksykograficznie.

std::deque<std::string>lengthSort(std::forward_list<std::string>& words) {

    std::deque<std::string> word;
    word.resize(100,0);
    for(const auto& w : words) {

        word.push_back( w);
    }
    std::sort(word.begin(), word.end());

    return word;
}