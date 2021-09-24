#include "arithmeticAverage.hpp"

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    if (first.size() != second.size()) {
        return 0.0;
    }
    float factor = 0.5f;
    std::vector<double> result(first.size(), 0);
    std::transform(begin(first), end(first), begin(second), begin(result),
                   [factor](auto lhs, auto rhs) { return (lhs + rhs) * factor; });
    double product = std::accumulate(begin(result), end(result), 0.0, std::plus<double>());

    return product / result.size();
}
