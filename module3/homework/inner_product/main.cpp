#include <iostream>
#include <math.h>
#include <numeric>
#include <string>
#include <vector>
//#include "arithmeticAverage.hpp"

template <typename T>
void printVector(const std::vector<T>& collection) {
    for (const auto& element : collection) {
        std::cout << element << '\n';
    }
    std::cout << '\n';
}

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    return std::inner_product(
               begin(first), end(first), begin(second), 0, std::plus<int>(), std::plus<int>()) /
           static_cast<double>((first.size() * 2));
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    return std::sqrt(std::inner_product(
               begin(first), end(first), begin(second), 0, std::plus<int>(), [](auto x, auto y){
                    return std::pow((y - x), 2);
               }));
}

int main() {
    std::vector<int> vec1{7, 4, 3};
    std::vector<int> vec2{17, 6, 2};

    std::cout << ArithmeticAverage(vec1, vec2) << '\n';
    std::cout << Distance(vec1, vec2) << '\n';

    return 0;
}
