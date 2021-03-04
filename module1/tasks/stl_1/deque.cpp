#include <iostream>
#include <deque>

void print(const std::deque<int>& contener){
    for (const auto& it : contener){
        std::cout << it << " ";
    }
    std::cout << "\n";
}

int main (){
    std::cout << "Deque: \n";
    std::deque<int>deq;
    deq.push_front(5);
    deq.push_front(4);
    deq.push_front(3);
    deq.push_front(2);
    deq.push_front(1);
    print(deq);
    deq.erase(deq.begin() + 1);
    deq.erase(deq.begin() + 3);
    print(deq);
    deq.push_front(30);
    deq.push_back(30);
    print(deq);
    auto it = deq.begin();
    std::advance(it, 3);
    deq.insert(it, 20);
    print(deq);
    return 0;
}