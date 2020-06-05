#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 4, 5, 6};
    vec.erase(vec.begin());

    vec.push_back(5);
    vec.emplace(vec.begin(), 12);

    std::cout << vec.size() <<'\n';
    std::cout << vec.max_size() <<'\n';

    for (auto element : vec) {
        std::cout << element <<'\n';
    }
    vec.clear();
    std::cout << vec.size() <<'\n';
    std::cout << vec.capacity() <<'\n';

    vec.shrink_to_fit();
    std::cout << vec.size() <<'\n';
    std::cout << vec.capacity() <<'\n';
}
