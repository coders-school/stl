#include "arithmeticAverage.hpp"


float ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    int sumFirst = std::accumulate(first.begin(), first.end(), 0); 
    int sumSecond = std::accumulate(second.begin(), second.end(), 0); 
    return  static_cast<float>(sumFirst + sumSecond) / static_cast<float>(first.size() + second.size());
}

float Distance(const std::vector<int>& first, const std::vector<int>& second) {
    // Creating diff vector initialised with second vector
    std::vector<int> diff(second);
    // Calculating difference of vecotrs first & second
    std::transform(first.begin(), first.end(), diff.begin(), diff.begin(), std::minus<int>());
    // std::copy(begin(diff), end(diff), std::ostream_iterator<int>(std::cout, " "));
    // std::cout << '\n';
    // Calculating square of each element of diff vector
    std::transform(diff.begin(), diff.end(), diff.begin(), [](int a){ return a * a; });
    // std::copy(begin(diff), end(diff), std::ostream_iterator<int>(std::cout, " "));
    // std::cout << '\n';
    // Calculating the sum of square of elements of diff vector return = sqrt((x2 - x1)^2 + (y2 - y1)^2 + (z2 - z1)^2)
    return std::sqrt(std::accumulate(diff.begin(), diff.end(), 0));
}