#include <iostream>
#include <list>
#include <array>

void print(const std::list<int>& contener){
    for (const auto& it : contener){
        std::cout << it << " ";
    }
    std::cout << "\n";
}

void print(const std::array<int, 8>& contener){
    for (const auto& it : contener){
        std::cout << it << " ";
    }
    std::cout << "\n";
}

int main (){
    std::cout << "List 1: \n";
    std::list<int>list{0, 1, 2, 3, 4, 5};
    print(list);
    list.erase(next(list.begin(), 2));
    list.push_back(10);
    list.push_front(10);
    print(list);
    list.insert(std::next(list.begin(), 3), 20);
    print(list);
    std::array<int, 8>arr;
    auto it = list.begin();
    for (auto& ele : arr){
        ele = *it++;
    }
    print(arr);
    
    return 0;

}