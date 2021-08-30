#include "arithmeticAverage.hpp"
#include <algorithm>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& firstVector, const std::vector<int>& secondVector) {

    return static_cast<double>(std::accumulate(firstVector.cbegin(), firstVector.cend(), 0)
          + std::accumulate(secondVector.cbegin(), secondVector.cend(), 0))
          / (firstVector.size() + secondVector.size());
}

double Distance(const std::vector<int>& firstVector, const std::vector<int>& secondVector) {

    return 0.0;
}
