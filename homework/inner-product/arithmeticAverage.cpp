#include "arithmeticAverage.hpp"
#include <numeric>
#include <cmath>

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    double sum = std::accumulate(first.begin(), first.end(), 0) + std::accumulate(second.begin(), second.end(), 0);
    size_t size = first.size() + second.size();
 
    return sum / size;
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    double distance = std::transform_reduce(begin(first),
                                            end(first),
                                            begin(second),
                                            0,
                                            std::plus<> {},
                                            [](const auto& lhs, const auto& rhs) { return std::pow(rhs - lhs, 2); });

    return std::sqrt(distance);
}
