#include <cmath>
#include <functional>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& lhs, const std::vector<int>& rhs)
{
    auto sumOfVectors = std::accumulate(lhs.cbegin(), lhs.cend(), 0) + std::accumulate(rhs.cbegin(), rhs.cend(), 0.0);
    return sumOfVectors / (lhs.size() + rhs.size());
}

double Distance(const std::vector<int>& lhs, const std::vector<int>& rhs)
{
    auto radicantValue = std::inner_product(lhs.cbegin(), lhs.cend(), rhs.cbegin(), 0.0, std::plus<>(),
        [](const auto& lhs, const auto& rhs) { return std::pow(std::abs(rhs - lhs), 2); });
    return std::sqrt(radicantValue);
}


int main()
{
    return 0;
}
