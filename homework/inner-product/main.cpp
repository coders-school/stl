#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
#include "arithmeticAverage.hpp"

int main(int argc, char const *argv[]) { 
    auto a = Distance({7, 4, 3}, {17, 6, 2});
    std::cout << a << std::endl;
    a = ArithmeticAverage({1, 2, 3, 4}, {1, 2, 3, 4});
    std::cout << a << std::endl;
    return 0; 
    }