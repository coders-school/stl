#include "arithmeticAverage.hpp"

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    return (std::accumulate(first.begin(), first.end(), 0) + std::accumulate(second.begin(), second.end(), 0))
    / static_cast<double>(first.size() + second.size());
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    std::vector<int> result;
    std::transform(first.begin(), first.end(), second.begin(), std::back_inserter(result), std::minus<int>());
    std::for_each(result.begin(), result.end(), [](auto& a) {
        return a *= a;
    });
    return sqrt(std::accumulate(result.begin(), result.end(), 0));
}