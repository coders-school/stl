#include <iostream>
#include <forward_list>
#include <array>

int main() {
    std::forward_list<int> myList {0, 1, 2, 3, 4, 5};

    for (auto el : myList) {
        std::cout << el <<" ";
    }
    std::cout <<"\n";
    auto it = myList.begin();
    std::advance(it,1);
    myList.erase_after(it);
    myList.emplace_front(10);
    it = myList.begin();
    std::advance(it,5);
    myList.emplace_after(it, 10);
    for (auto el : myList) {
        std::cout << el <<" ";
    }
    std::cout <<"\n";
    it = myList.begin();
    std::advance(it,2);
    myList.emplace_after(it,20);
    for (auto el : myList) {
        std::cout << el <<" ";
    }
    
}