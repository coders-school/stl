#include <iostream>
#include <vector>

int main(){
    std::cout << "Vector: \n";
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
    return 0;
}
