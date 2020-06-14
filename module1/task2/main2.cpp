#include <algorithm>
#include <iostream>
#include <vector>

void prtSize(const std::vector<int>& vec) {
    std::cout << "vec size: " << vec.size() << " ; " << vec.capacity() <<"\n";
}

int main() {
    std::vector<int> vec;// = {1, 2, 4, 5, 6};
    prtSize(vec);
    vec.insert(vec.begin(), 10, 5);
    prtSize(vec);
    vec.reserve(20);
    prtSize(vec);
    vec.shrink_to_fit();
    prtSize(vec);
}