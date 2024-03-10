#include <iostream>
#include <vector>
#include "arithmeticAverage.hpp"

int main() {
    std::vector<int> vec1{1, 2, 3, 4};
    std::vector<int> vec2{1, 1, 1, 1};

    std::vector<int> vec3{2, 4};
    std::vector<int> vec4{3, 3};

    std::cout << ArithmeticAverage(vec1, vec2) << std::endl;

    std::cout << Distance(vec3, vec4);

    return 0;
}