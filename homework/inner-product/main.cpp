#include "arithmeticAverage.hpp"

int main () {
    std::vector<int> first{-5, 4, 2, -5, 2, 4, 6, 7};
    std::vector<int> second{3, 5, -2, 6, 7, -3, 6, 9};

    ArithmeticAverage(first, second);
    Distance(first, second);

    return 0;
}