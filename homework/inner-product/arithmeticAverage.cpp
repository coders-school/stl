#include "arithmeticAverage.hpp"

float ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second)
{
    if (first.size() != second.size()
        || first.empty() || second.empty()) {
        return -1;
    }

    auto sum = static_cast<float>(std::accumulate(begin(first), end(first), 0.0)
        + std::accumulate(begin(second), end(second), 0.0));
    auto sizes = first.size() + second.size();
    auto average = sum / sizes;
    return average;
}

float Distance(const std::vector<int>& first, const std::vector<int>& second)
{
    if (first.size() != second.size()
        || first.empty() || second.empty()) {
        return -1;
    }

    auto size = first.size();
    std::vector<int> resV(size);

    std::transform(begin(first), end(first), begin(second), begin(resV),
        [](auto x, auto y) { return (abs(x - y) * abs(x - y)); });
    auto res = sqrt(std::accumulate(begin(resV), end(resV), 0));
    return res;
}
