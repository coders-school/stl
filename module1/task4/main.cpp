#include <iostream>
#include <list>
#include <array>

int main() {
    std::list<int> myList {0, 1, 2, 3, 4, 5};

    for (auto el : myList) {
        std::cout << el <<" ";
    }
    std::cout <<"\n";
    auto it = myList.begin();
    std::advance(it,2);
    myList.erase(it);
    myList.emplace_front(10);
    myList.emplace_back(10);
    for (auto el : myList) {
        std::cout << el <<" ";
    }
    std::cout <<"\n";
    it = myList.begin();
    std::advance(it,3);
    myList.emplace(it,20);

    std::array<int, 8> arr;
    std::copy(myList.begin(),myList.end(),arr.begin());

    for (auto el : arr) {
        std::cout << el <<" ";
    }
}