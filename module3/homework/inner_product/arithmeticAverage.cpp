#include "arithmeticAverage.hpp"

#include <functional>
#include <cmath>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    auto amount = first.size() + second.size();
    if (amount == 0) {
        return 0.0;
    }
    return (std::inner_product(first.begin(), first.end(), second.begin(), 0.0, std::plus<>(), std::plus<>())) / amount;
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    if (first.empty() || second.empty()) {
        return 0.0;
    }
    
    auto pred = [](const auto el_first, const auto el_second){
        return pow((el_second - el_first), 2);
    };

    return sqrt(std::inner_product(first.begin(), first.end(), second.begin(), 0.0, std::plus<>(), pred));
}
