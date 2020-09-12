#include <functional>
#include <numeric>

#include "arithmeticMean.hpp"

double arithmeticMean(const std::vector<int>& vecA, const std::vector<int>& vecB) {
    return std::inner_product(vecA.begin(), vecA.end(),
                              vecB.begin(),
                              0.0,
                              std::plus<>(),
                              [&](const auto a, const auto b) {
                                  return 1.0 * (a + b) / (vecA.size() + vecB.size());
                              });
}
