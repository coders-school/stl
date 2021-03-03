#include <iostream>
#include <forward_list>

void print(const std::forward_list<int>& contener){
    for (const auto& it : contener){
        std::cout << it << " ";
    }
    std::cout << "\n";
}

int main (){
    std::cout << "Forward list: \n";
    std::forward_list<int>list{0, 1, 2, 3, 4, 5};
    print(list);
    auto it = list.begin();
    std::advance(it, 1);
    list.erase_after(it);
    it = list.begin();
    list.push_front(10);
    std::advance(it, 4);
    list.insert_after(it, 10);
    print(list);
    it = list.begin();
    std::advance(it, 2);
    list.insert_after(it, 20);
    print(list);
    return 0;

}