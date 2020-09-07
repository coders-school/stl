#include <iostream>

#include "arithmeticAverage.hpp"

int main() {
    std::vector<int> vec1{1, 2, 3, 4};

    auto result = ArithmeticAverage(vec1, vec1);
    std ::cout << result << '\n';
    std::vector<int> first{7, 4, 3};
    std::vector<int> second{17, 6, 2};
    std::copy(first.begin(), first.end(), second.begin());
    result = Distance(first, second);
    std ::cout << result << '\n';
}
