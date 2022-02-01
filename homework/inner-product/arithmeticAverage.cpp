#include "arithmeticAverage.hpp"

#include <cmath>
#include <functional>
#include <numeric>

// calculates an arithemetic average of all values stored in two vectores
long double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second)
{
    long double sum = std::transform_reduce(begin(first),
                                            end(first),
                                            begin(second),
                                            0,
                                            std::plus<> {},
                                            std::plus<> {});
    long double number_of_elements = static_cast<long double>(first.size() + second.size());

    return sum / number_of_elements;
}

// calculates the distance between 2 points in n-dimentional space
long double Distance(const std::vector<int>& first, const std::vector<int>& second)
{
    auto difference_sq = [](const auto& lhs, const auto& rhs) {
        return pow(rhs - lhs, 2);
    };
    long double distance_squared = std::transform_reduce(begin(first),
                                                         end(first),
                                                         begin(second),
                                                         0,
                                                         std::plus<> {},
                                                         difference_sq);

    return sqrt(distance_squared);
}