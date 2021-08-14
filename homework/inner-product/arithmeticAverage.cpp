#include "arithmeticAverage.hpp"

double ArithmeticAverage(std::vector<int>& v1, std::vector<int>& v2) {
    return (std::inner_product(v1.begin(),
                               v1.end(),
                               v2.begin(),
                               0,
                               std::plus<>(),
                               std::plus<>())) / static_cast<double>(v1.size() + v2.size());
}

double Distance(std::vector<int>& v1, std::vector<int>& v2) {
    return std::sqrt(std::inner_product(v1.begin(), v1.end(), v2.begin(), 0, std::plus<>(),
                                           []( const auto& point1, const auto& point2) {
                                               return std::pow(point1 - point2, 2);
                                           }));
}