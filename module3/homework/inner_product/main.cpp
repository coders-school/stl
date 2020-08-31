#include "arithmeticAverage.hpp"
#include <iostream>

int main(){

    std::vector<int> vec1 = {1,2,3,4};
    std::vector<int> vec2 = {7, 4, 3};
    std::vector<int> vec3 = {17, 6, 2};

    std::cout << "Arithmetic average of vectors {1, 2, 3, 4}: " << ArithmeticAverage(vec1, vec1);

    return 0;
}