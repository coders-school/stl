#include <iostream>
#include <vector>

int main(){
    std::cout << "Vector 1: \n";
    std::vector<int> vec {1, 2, 4, 5, 6};
    vec.erase(vec.begin());
    vec.insert(vec.end(), 5);
    vec.emplace(vec.begin(), 12);
    std::cout <<"Size: " << vec.size() << "\nCapacity: " << vec.capacity() << "\n";
    for(const auto i : vec){
        std::cout << i << " ";
    }
    vec.clear();
    std::cout <<"\nSize: " << vec.size() << "\nCapacity: " << vec.capacity() << "\n";

    std::cout << "\n\nVector 2: \n";
    std::vector<int>vec2{};
    std::cout <<"\nSize: " << vec2.size() << "\nCapacity: " << vec2.capacity() << "\n";
    vec2.insert(vec2.begin(),10, 5);
    std::cout <<"\nSize: " << vec2.size() << "\nCapacity: " << vec2.capacity() << "\n";
    vec2.reserve(20);
    std::cout <<"\nSize: " << vec2.size() << "\nCapacity: " << vec2.capacity() << "\n";
    vec2.shrink_to_fit();
    std::cout <<"\nSize: " << vec2.size() << "\nCapacity: " << vec2.capacity() << "\n";
    return 0;
}
