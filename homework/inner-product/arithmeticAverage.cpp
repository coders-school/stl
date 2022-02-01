#include "arithmeticAverage.hpp"

#include <functional>
#include <numeric>

// calculates an arithemetic average of all values stored in two vectores
long double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second)
{
    long double sum = std::transform_reduce(begin(first),
                                            end(first),
                                            begin(second),
                                            0,
                                            std::plus<>(),
                                            std::plus<>());
    long double number_of_elements = static_cast<long double>(first.size() + second.size());
    return sum / number_of_elements;
}

// calculates the distance between 2 points in n-dimentional space
long double Distance(const std::vector<int>& first, const std::vector<int>& second)
{
    return 0;
}