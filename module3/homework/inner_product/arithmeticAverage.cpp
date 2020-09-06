#include "arithmeticAverage.hpp"

#include <functional>
#include <cmath>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    auto amount = first.size() + second.size();
    return (std::inner_product(first.begin(), first.end(), second.begin(), 0.0, std::plus<>(), std::plus<>())) / amount;
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    auto pred = [](const auto el_first, const auto el_second){
        return pow((el_second - el_first), 2);
    };

    return sqrt(std::inner_product(first.begin(), first.end(), second.begin(), 1.0, std::plus<>(), pred));
}
