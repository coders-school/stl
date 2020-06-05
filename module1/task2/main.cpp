#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec;

    std::cout << "SIZE: " << vec.size() <<'\n';
    std::cout << "CAPACITY: " << vec.capacity() <<'\n';

    vec.resize(10,5);

    std::cout << "SIZE: " << vec.size() <<'\n';
    std::cout << "CAPACITY: " << vec.capacity() <<'\n';

    vec.reserve(20);

    std::cout << "SIZE: " << vec.size() <<'\n';
    std::cout << "CAPACITY: " << vec.capacity() <<'\n';

    vec.shrink_to_fit();

    std::cout << "SIZE: " << vec.size() <<'\n';
    std::cout << "CAPACITY: " << vec.capacity() <<'\n';

    for (auto element : vec) {
        std::cout << element <<' ';
    }

}
