#include "arithmeticAverage.hpp"

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    double sum1 = std::accumulate(first.begin(), first.end(), 0);
    double sum2 = std::accumulate(second.begin(), second.end(), 0);
    double sum = sum1 + sum2;
    double result = sum / (first.size() + second.size());

    return result;
}
double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    double result = 0;

    for (auto it1 = first.begin(), it2 = second.begin(); it1 != first.end() && it2 != second.end(); ++it1, ++it2) {
        int element1 = *it1;
        int element2 = *it2;
        result += std::pow(*it2 - *it1, 2);
    }
    return std::sqrt(result);
}