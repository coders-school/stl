#include <iostream>
#include "transformContainers.hpp"

#include <deque>
#include <list>
#include <map>
#include <string>
#include <algorithm>

int main()
{
    std::list<std::string> names{"Jan", "Pawel", "Olek", "Jan" , "Pawel", "Joe", "Ola", "Magda"};
    std::deque<int> numbers{1, 2, 3, 1, 2, 4, 5};

    auto mapa = removeDuplicateAndTranformToMap(names,numbers);


}