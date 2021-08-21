#include <iostream>
#include <vector>
#include "arithmeticAverage.hpp"

int main() {
    // std::vector <int> vec1 = {7, 4, 3};
    // std::vector <int> vec2 = {17, 6, 2};
    // std::vector<int> vec1 = {-5, 4, 2, -5, 2, 4, 6, 7};
    // std::vector<int> vec2 = {3, 5, -2, 6, 7, -3, 6, 9};
    std::vector<int> vec1 = {7, 4, 3, 13};
    std::vector<int> vec2 = {17, 6, 2, -2};
    
    //  first = {7, 4, 3, 13};
    // second = {17, 6, 2, -2};
    // expected = 18.16590212458495;
    std::cout << ArithmeticAverage (vec1, vec2);
    std::cout << '\n';
    std::cout << Distance (vec1, vec2);
    std::cout << '\n';
}

    // std::vector<int> first{7, 4, 3};
    // std::vector<int> second{17, 6, 2};

    // std::vector <int> vec1 = {1, 2, 3, 4};
    // std::vector <int> vec2 = {1, 2, 3, 4};
