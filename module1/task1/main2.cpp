#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 4, 5, 6};

    vec.erase(vec.begin());

    vec.push_back(5);
    vec.emplace(vec.begin(), 12);

    std::cout << "vec size: " << vec.size() << " ; " << vec.capacity() <<"\n";
    std::for_each(vec.begin(), vec.end(), [](const auto& el){std::cout << el << " ";});
    std::cout<< "\n";
    vec.erase(vec.begin(), vec.end());
    std::cout << "vec size: " << vec.size() << " ; " << vec.capacity() <<"\n";
}