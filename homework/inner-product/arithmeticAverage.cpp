#include "arithmeticAverage.hpp"

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    std::vector<int> mergedVectors = first;
    mergedVectors.insert(mergedVectors.end(), second.begin(), second.end());
    if (0 == mergedVectors.size()) {
        return 0;
    }

    int sum = std::accumulate(mergedVectors.begin(), mergedVectors.end(), 0);

    return (double)((double)sum / (double)mergedVectors.size());
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    if (first.size() != second.size()) {
        return 0;
    }

    double partialDistancesSquared = 0;
    for (int it = 0; it < first.size(); it++) {
        partialDistancesSquared += std::pow((second.at(it) - first.at(it)), 2);
    }

    return std::sqrt(partialDistancesSquared);
}