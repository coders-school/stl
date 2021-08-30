#include "arithmeticAverage.hpp"

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    int size = first.size() + second.size();
    return (std::accumulate(first.begin(), first.end(), 0.0) + std::accumulate(second.begin(), second.end(), 0.0)) / size;
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    if (first.size() != second.size()) {
        return 0;
    }
    double toRoot{0};
    for (int i = 0; i < first.size(); i++) {
        toRoot += ((second[i] - first[i]) * (second[i] - first[i]));
    }
    return sqrt(toRoot);
}
