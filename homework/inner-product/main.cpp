#include <iostream>
#include <vector>
#include "arithmeticAverage.hpp"

int main() {
    std::vector <int> vec1 = {7, 4, 3};
    std::vector <int> vec2 = {7, 4, 3};
    std::cout << ArithmeticAverage (vec1, vec2);
    std::cout << '\n';
    std::cout << Distance (vec1, vec2);
    std::cout << '\n';
}

    // std::vector<int> first{7, 4, 3};
    // std::vector<int> second{17, 6, 2};

    // std::vector <int> vec1 = {1, 2, 3, 4};
    // std::vector <int> vec2 = {1, 2, 3, 4};
